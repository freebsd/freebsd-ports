/* $FreeBSD$ */
/* FreeBSD libthread_db assisted debugging support.
   Copyright 1999, 2000, 2001 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/user.h>
#include <libutil.h>

#include <dlfcn.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <signal.h>

#include "proc_service.h"
#include "thread_db.h"

#include "defs.h"
#include "bfd.h"
#include "elf-bfd.h"
#include "gdb_assert.h"
#include "gdbcore.h"
#include "gdbthread.h"
#include "inferior.h"
#include "objfiles.h"
#include "regcache.h"
#include "symfile.h"
#include "symtab.h"
#include "target.h"
#include "observer.h"
#include "gdbcmd.h"
#include "gregset.h"
#ifdef PT_GETXMMREGS
#include "i387-tdep.h"
#endif

#define LIBTHREAD_DB_SO "libthread_db.so"

struct private_thread_info
{
  char *lwp_name;
};

struct ps_prochandle
{
  pid_t pid;
};

/* Defining the prototype of _initialize_thread_db to remove warning */
extern initialize_file_ftype _initialize_thread_db;

/* This module's target vectors.  */
static struct target_ops fbsd_thread_ops;

/* Non-zero if there is a thread module */
static int fbsd_thread_present;

/* Non-zero if we're using this module's target vector.  */
static int fbsd_thread_active;

/* Non-zero if we have to keep this module's target vector active
   across re-runs.  */
static int keep_thread_db;

/* Structure that identifies the child process for the
   <proc_service.h> interface.  */
static struct ps_prochandle proc_handle;

/* Connection to the libthread_db library.  */
static td_thragent_t *thread_agent;

/* The last thread we are single stepping */
static ptid_t last_single_step_thread;


/* Pointers to the libthread_db functions.  */
static td_err_e (*td_init_p) (void);

static td_err_e (*td_ta_new_p) (struct ps_prochandle *ps, td_thragent_t **ta);
static td_err_e (*td_ta_delete_p) (td_thragent_t *);
static td_err_e (*td_ta_map_id2thr_p) (const td_thragent_t *ta, thread_t pt,
				       td_thrhandle_t *__th);
static td_err_e (*td_ta_map_lwp2thr_p) (const td_thragent_t *ta, lwpid_t lwpid,
					td_thrhandle_t *th);
static td_err_e (*td_ta_thr_iter_p) (const td_thragent_t *ta,
				     td_thr_iter_f *callback,
				     void *cbdata_p, td_thr_state_e state,
				     int ti_pri, sigset_t *ti_sigmask_p,
				     unsigned int ti_user_flags);
static td_err_e (*td_ta_event_addr_p) (const td_thragent_t *ta,
				       td_event_e event, td_notify_t *ptr);
static td_err_e (*td_ta_set_event_p) (const td_thragent_t *ta,
				      td_thr_events_t *event);
static td_err_e (*td_ta_event_getmsg_p) (const td_thragent_t *ta,
					 td_event_msg_t *msg);
static td_err_e (*td_thr_get_info_p) (const td_thrhandle_t *th,
				      td_thrinfo_t *infop);
#ifdef PT_GETXMMREGS
static td_err_e (*td_thr_getxmmregs_p) (const td_thrhandle_t *th,
					char *regset);
#endif
static td_err_e (*td_thr_getfpregs_p) (const td_thrhandle_t *th,
				       prfpregset_t *regset);
static td_err_e (*td_thr_getgregs_p) (const td_thrhandle_t *th,
				      prgregset_t gregs);
#ifdef PT_GETXMMREGS
static td_err_e (*td_thr_setxmmregs_p) (const td_thrhandle_t *th,
					const char *fpregs);
#endif
static td_err_e (*td_thr_setfpregs_p) (const td_thrhandle_t *th,
				       const prfpregset_t *fpregs);
static td_err_e (*td_thr_setgregs_p) (const td_thrhandle_t *th,
				      prgregset_t gregs);
static td_err_e (*td_thr_event_enable_p) (const td_thrhandle_t *th, int event);

static td_err_e (*td_thr_sstep_p) (td_thrhandle_t *th, int step);

static td_err_e (*td_ta_tsd_iter_p) (const td_thragent_t *ta,
				 td_key_iter_f *func, void *data);
static td_err_e (*td_thr_tls_get_addr_p) (const td_thrhandle_t *th,
                                          void *map_address,
                                          size_t offset, void **address);
static td_err_e (*td_thr_dbsuspend_p) (const td_thrhandle_t *);
static td_err_e (*td_thr_dbresume_p) (const td_thrhandle_t *);

static CORE_ADDR td_create_bp_addr;

/* Location of the thread death event breakpoint.  */
static CORE_ADDR td_death_bp_addr;

/* Prototypes for local functions.  */
static void fbsd_find_lwp_name(long lwpid, struct private_thread_info *info);
static void fbsd_thread_update_thread_list (struct target_ops *ops);
static int fbsd_thread_alive (struct target_ops *ops, ptid_t ptid);
static void attach_thread (ptid_t ptid, const td_thrhandle_t *th_p,
               const td_thrinfo_t *ti_p, int verbose);
static void fbsd_thread_detach (struct target_ops *ops, const char *args,
				int from_tty);

CORE_ADDR fbsd_thread_get_local_address(struct target_ops *ops,
		ptid_t ptid, CORE_ADDR lm, CORE_ADDR offset);

/* Building process ids.  */

#define GET_PID(ptid)		ptid_get_pid (ptid)
#define GET_LWP(ptid)		ptid_get_lwp (ptid)
#define GET_THREAD(ptid)	ptid_get_tid (ptid)

#define IS_LWP(ptid)		(GET_LWP (ptid) != 0)
#define IS_THREAD(ptid)		(GET_THREAD (ptid) != 0)

#define BUILD_LWP(lwp, pid)	ptid_build (pid, lwp, 0)
#define BUILD_THREAD(tid, pid)	ptid_build (pid, 0, tid)

static void
free_private_thread_info(struct private_thread_info *info)
{
  xfree(info->lwp_name);
  xfree(info);
}

static char *
thread_db_err_str (td_err_e err)
{
  static char buf[64];

  switch (err)
    {
    case TD_OK:
      return "generic 'call succeeded'";
    case TD_ERR:
      return "generic error";
    case TD_NOTHR:
      return "no thread to satisfy query";
    case TD_NOSV:
      return "no sync handle to satisfy query";
    case TD_NOLWP:
      return "no LWP to satisfy query";
    case TD_BADPH:
      return "invalid process handle";
    case TD_BADTH:
      return "invalid thread handle";
    case TD_BADSH:
      return "invalid synchronization handle";
    case TD_BADTA:
      return "invalid thread agent";
    case TD_BADKEY:
      return "invalid key";
    case TD_NOMSG:
      return "no event message for getmsg";
    case TD_NOFPREGS:
      return "FPU register set not available";
    case TD_NOLIBTHREAD:
      return "application not linked with libthread";
    case TD_NOEVENT:
      return "requested event is not supported";
    case TD_NOCAPAB:
      return "capability not available";
    case TD_DBERR:
      return "debugger service failed";
    case TD_NOAPLIC:
      return "operation not applicable to";
    case TD_NOTSD:
      return "no thread-specific data for this thread";
    case TD_MALLOC:
      return "malloc failed";
    case TD_PARTIALREG:
      return "only part of register set was written/read";
    case TD_NOXREGS:
      return "X register set not available for this thread";
    default:
      snprintf (buf, sizeof (buf), "unknown thread_db error '%d'", err);
      return buf;
    }
}

static char *
thread_db_state_str (td_thr_state_e state)
{
  static char buf[64];

  switch (state)
    {
    case TD_THR_STOPPED:
      return "stopped by debugger";
    case TD_THR_RUN:
      return "runnable";
    case TD_THR_ACTIVE:
      return "active";
    case TD_THR_ZOMBIE:
      return "zombie";
    case TD_THR_SLEEP:
      return "sleeping";
    case TD_THR_STOPPED_ASLEEP:
      return "stopped by debugger AND blocked";
    default:
      snprintf (buf, sizeof (buf), "unknown thread_db state %d", state);
      return buf;
    }
}

/* Convert LWP to user-level thread id. */
static ptid_t
thread_from_lwp (ptid_t ptid, td_thrhandle_t *th, td_thrinfo_t *ti)
{
  td_err_e err;

  gdb_assert (IS_LWP (ptid));

  if (fbsd_thread_active)
    {
      err = td_ta_map_lwp2thr_p (thread_agent, GET_LWP (ptid), th);
      if (err == TD_OK)
        {
          err = td_thr_get_info_p (th, ti);
          if (err != TD_OK)
            error ("Cannot get thread info: %s", thread_db_err_str (err));
          return BUILD_THREAD (ti->ti_tid, GET_PID (ptid));
        }
    }

  /* the LWP is not mapped to user thread */
  return BUILD_LWP (GET_LWP (ptid), GET_PID (ptid));
}

static void
fbsd_core_get_first_lwp (bfd *abfd, asection *asect, void *obj)
{
  if (strncmp (bfd_section_name (abfd, asect), ".reg/", 5) != 0)
    return;

  if (*(lwpid_t *)obj != 0)
    return;

  *(lwpid_t *)obj = atoi (bfd_section_name (abfd, asect) + 5);
}

static long
get_current_lwp (int pid)
{
  struct ptrace_lwpinfo pl;
  lwpid_t lwpid;

  if (!target_has_execution)
    {
      lwpid = 0;
      bfd_map_over_sections (core_bfd, fbsd_core_get_first_lwp, &lwpid);
      return lwpid;
    }
  if (ptrace (PT_LWPINFO, pid, (caddr_t)&pl, sizeof(pl)))
    perror_with_name("PT_LWPINFO");

  return (long)pl.pl_lwpid;
}

static void
get_current_thread (void)
{
  td_thrhandle_t th;
  td_thrinfo_t ti;
  long lwp;
  ptid_t tmp, ptid;

  lwp = get_current_lwp (proc_handle.pid);
  tmp = BUILD_LWP (lwp, proc_handle.pid);
  ptid = thread_from_lwp (tmp, &th, &ti);
  if (in_thread_list (inferior_ptid) )
    {
      struct thread_info * ti_inf = inferior_thread();
      ti_inf->ptid = ptid;
    }
  if (!in_thread_list (ptid))
    {
      attach_thread (ptid, &th, &ti, 1);
    }
  inferior_ptid = ptid;
}

static CORE_ADDR
extract_func_ptr(void *value)
{

  return (extract_typed_address
	  ((gdb_byte *)value,
	   builtin_type (target_gdbarch ())->builtin_func_ptr));
}

static CORE_ADDR
extract_data_ptr(void *value)
{

  return (extract_typed_address
	  ((gdb_byte *)value,
	   builtin_type (target_gdbarch ())->builtin_data_ptr));
}

static td_err_e
enable_thread_event (td_thragent_t *thread_agent, int event, CORE_ADDR *bp)
{
  td_notify_t notify;
  td_err_e err;

  /* Get the breakpoint address for thread EVENT.  */
  err = td_ta_event_addr_p (thread_agent, event, &notify);
  if (err != TD_OK)
    return err;

  /* Set up the breakpoint.  */
  (*bp) = (gdbarch_convert_from_func_ptr_addr
	   (target_gdbarch (),
	    extract_func_ptr(&notify.u.bptaddr),
	    &current_target));
  create_thread_event_breakpoint (target_gdbarch (), (*bp));

  return TD_OK;
}

static void
enable_thread_event_reporting (void)
{
  td_thr_events_t events;
  td_notify_t notify;
  td_err_e err;

  /* We cannot use the thread event reporting facility if these
     functions aren't available.  */
  if (td_ta_event_addr_p == NULL || td_ta_set_event_p == NULL
      || td_ta_event_getmsg_p == NULL || td_thr_event_enable_p == NULL)
    return;

  /* Set the process wide mask saying which events we're interested in.  */
  td_event_emptyset (&events);
  td_event_addset (&events, TD_CREATE);
  td_event_addset (&events, TD_DEATH);

  err = td_ta_set_event_p (thread_agent, &events);
  if (err != TD_OK)
    {
      warning ("Unable to set global thread event mask: %s",
	       thread_db_err_str (err));
      return;
    }

  /* Delete previous thread event breakpoints, if any.  */
  remove_thread_event_breakpoints ();
  td_create_bp_addr = 0;
  td_death_bp_addr = 0;

  /* Set up the thread creation event.  */
  err = enable_thread_event (thread_agent, TD_CREATE, &td_create_bp_addr);
  if (err != TD_OK)
    {
      warning ("Unable to get location for thread creation breakpoint: %s",
	       thread_db_err_str (err));
      return;
    }

  /* Set up the thread death event.  */
  err = enable_thread_event (thread_agent, TD_DEATH, &td_death_bp_addr);
  if (err != TD_OK)
    {
      warning ("Unable to get location for thread death breakpoint: %s",
	       thread_db_err_str (err));
      return;
    }
}

static void
disable_thread_event_reporting (void)
{
  td_thr_events_t events;

  /* Set the process wide mask saying we aren't interested in any
     events anymore.  */
  td_event_emptyset (&events);
  td_ta_set_event_p (thread_agent, &events);

  td_create_bp_addr = 0;
  td_death_bp_addr = 0;
}

static void
fbsd_thread_activate (void)
{
  fbsd_thread_active = 1;
  if (target_has_execution)
    enable_thread_event_reporting ();
  else
    init_thread_list ();
  fbsd_thread_update_thread_list (NULL);
  get_current_thread ();
}

static void
fbsd_thread_deactivate (void)
{
  if (target_has_execution)
    disable_thread_event_reporting();
  td_ta_delete_p (thread_agent);

  inferior_ptid = pid_to_ptid (proc_handle.pid);
  proc_handle.pid = 0;
  fbsd_thread_active = 0;
  fbsd_thread_present = 0;
}

static void
check_for_thread_db (void)
{
  td_err_e err;

  if (td_ta_new_p == NULL)
    return;

  /* Don't try to attach to a dead target if there is no core file. */
  if (!target_has_execution && core_bfd == NULL)
    return;

  /* Nothing to do.  The thread library was already detected and the
     target vector was already activated.  */
  if (fbsd_thread_active)
    return;

  /* Now, initialize libthread_db.  This needs to be done after the
     shared libraries are located because it needs information from
     the user's thread library.  */

  err = td_init_p ();
  if (err != TD_OK)
    {
      warning ("Cannot initialize libthread_db: %s", thread_db_err_str (err));
      return;
    }

  /* Initialize the structure that identifies the child process.  Note
     that at this point there is no guarantee that we actually have a
     child process.  */
  proc_handle.pid = GET_PID (inferior_ptid);

  /* Now attempt to open a connection to the thread library.  */
  err = td_ta_new_p (&proc_handle, &thread_agent);
  switch (err)
    {
    case TD_NOLIBTHREAD:
      /* No thread library was detected.  */
      break;

    case TD_OK:
      /* The thread library was detected.  Activate the thread_db target.  */
      push_target(&fbsd_thread_ops);
      fbsd_thread_present = 1;
      fbsd_thread_activate();

      break;

    default:
      warning ("Cannot initialize thread debugging library: %s",
               thread_db_err_str (err));
      break;
    }
}

static void
fbsd_thread_new_objfile (struct objfile *objfile)
{
  if (objfile != NULL)
    check_for_thread_db ();
}

static void
fbsd_thread_detach (struct target_ops *ops, const char *args, int from_tty)
{
  struct target_ops *beneath = find_target_beneath (ops);

  fbsd_thread_deactivate ();

  /* Delete thread event breakpoints, if any.  */
  remove_thread_event_breakpoints ();

  unpush_target (&fbsd_thread_ops);

  beneath->to_detach (beneath, args, from_tty);
}

static int
suspend_thread_callback (const td_thrhandle_t *th_p, void *data)
{
  int err = td_thr_dbsuspend_p (th_p);
  if (err != 0)
	fprintf_filtered(gdb_stderr, "%s %s\n", __func__, thread_db_err_str (err));
  return (err);
}

static int
resume_thread_callback (const td_thrhandle_t *th_p, void *data)
{
  int err = td_thr_dbresume_p (th_p);
  if (err != 0)
	fprintf_filtered(gdb_stderr, "%s %s\n", __func__, thread_db_err_str (err));
  return (err);
}

static void
fbsd_thread_resume (struct target_ops *ops,
		    ptid_t ptid, int step, enum gdb_signal signo)
{
  struct target_ops *beneath = find_target_beneath (ops);
  td_thrhandle_t th;
  td_thrinfo_t ti;
  ptid_t work_ptid;
  int resume_all, ret;
  long lwp, thvalid = 0;

  if (!fbsd_thread_active)
    {
      // XXX: I don't think this can happen
      printf_unfiltered ("%s: called without active threads\n", __func__);
      beneath->to_resume (beneath, ptid, step, signo);
      return;
    }

  if (GET_PID(ptid) != -1 && step != 0)
    {
      resume_all = 0;
      work_ptid = ptid;
    }
  else
    {
      resume_all = 1;
      work_ptid = inferior_ptid;
    }

  lwp = GET_LWP (work_ptid);
  if (lwp == 0)
    {
      /* check user thread */
      ret = td_ta_map_id2thr_p (thread_agent, GET_THREAD(work_ptid), &th);
      if (ret)
        error ("%s: %s", __func__, thread_db_err_str (ret));

      /* For M:N thread, we need to tell UTS to set/unset single step
         flag at context switch time, the flag will be written into
         thread mailbox. This becauses some architecture may not have
         machine single step flag in ucontext, so we put the flag in mailbox,
         when the thread switches back, kse_switchin restores the single step
         state.  */
      ret = td_thr_sstep_p (&th, step);
      if (ret)
        error ("%s: %s", __func__, thread_db_err_str (ret));
      ret = td_thr_get_info_p (&th, &ti);
      if (ret)
        error ("%s: %s", __func__, thread_db_err_str (ret));
      thvalid = 1;
      lwp = ti.ti_lid;
    }

  if (lwp)
    {
      int req = step ? PT_SETSTEP : PT_CLEARSTEP;
      if (ptrace (req, (pid_t) lwp, (caddr_t) 1, gdb_signal_to_host(signo)))
        perror_with_name ("PT_SETSTEP/PT_CLEARSTEP");
    }

  if (!ptid_equal (last_single_step_thread, null_ptid))
    {
       ret = td_ta_thr_iter_p (thread_agent, resume_thread_callback, NULL,
          TD_THR_ANY_STATE, TD_THR_LOWEST_PRIORITY,
          TD_SIGNO_MASK, TD_THR_ANY_USER_FLAGS);
      if (ret != TD_OK)
        error ("resume error: %s", thread_db_err_str (ret));
    }

  if (!resume_all)
    {
      ret = td_ta_thr_iter_p (thread_agent, suspend_thread_callback, NULL,
          TD_THR_ANY_STATE, TD_THR_LOWEST_PRIORITY,
          TD_SIGNO_MASK, TD_THR_ANY_USER_FLAGS);
      if (ret != TD_OK)
        error ("suspend error: %s", thread_db_err_str (ret));
      last_single_step_thread = work_ptid;
    }
  else
    last_single_step_thread = null_ptid;

  if (thvalid)
    {
      ret = td_thr_dbresume_p (&th);
      if (ret != TD_OK)
        error ("resume error: %s", thread_db_err_str (ret));
    }
  else
    {
      /* it is not necessary, put it here for completness */
      ret = ptrace(PT_RESUME, lwp, 0, 0);
    }

  /* now continue the process, suspended thread wont run */
  if (ptrace (PT_CONTINUE, proc_handle.pid , (caddr_t)1,
	      gdb_signal_to_host(signo)))
    perror_with_name ("PT_CONTINUE");
}

static void
attach_thread (ptid_t ptid, const td_thrhandle_t *th_p,
               const td_thrinfo_t *ti_p, int verbose)
{
  struct private_thread_info *private;
  struct thread_info *tp = NULL;
  char *lwpstr = NULL;
  td_err_e err;

  /* Add the thread to GDB's thread list.  */
  if (!in_thread_list (ptid))
  {
    /* Add thread with info */
    private = xmalloc(sizeof(struct private_thread_info));
    gdb_assert(private != NULL);
    // Thread name is assigned when printed
    memset(private, 0, sizeof(struct private_thread_info));

    tp = add_thread_with_info(ptid, private);
    tp->priv = private;
    tp->private_dtor = free_private_thread_info;
  }

  if (ti_p->ti_state == TD_THR_UNKNOWN || ti_p->ti_state == TD_THR_ZOMBIE)
    return;                     /* A zombie thread -- do not attach.  */

  if (! IS_THREAD(ptid))
    return;
  if (!target_has_execution)
    return;
  /* Enable thread event reporting for this thread. */
  err = td_thr_event_enable_p (th_p, 1);
  if (err != TD_OK)
    error ("Cannot enable thread event reporting for %s: %s",
           target_pid_to_str (ptid), thread_db_err_str (err));
}

static void
detach_thread (ptid_t ptid, int verbose)
{
  if (verbose)
    printf_unfiltered ("[%s exited]\n", target_pid_to_str (ptid));
}

static void
check_event (ptid_t ptid)
{
  struct regcache *regcache = get_thread_regcache (ptid);
  struct gdbarch *gdbarch = get_regcache_arch (regcache);
  td_event_msg_t msg;
  td_thrinfo_t ti;
  td_err_e err;
  CORE_ADDR stop_pc;
  int loop = 0;

  /* Bail out early if we're not at a thread event breakpoint.  */
  stop_pc = regcache_read_pc (regcache)
	    - gdbarch_decr_pc_after_break (gdbarch);
  if (stop_pc != td_create_bp_addr && stop_pc != td_death_bp_addr)
    return;
  loop = 1;

  do
    {
      err = td_ta_event_getmsg_p (thread_agent, &msg);
      if (err != TD_OK)
        {
	  if (err == TD_NOMSG)
	    return;
          error ("Cannot get thread event message: %s",
		 thread_db_err_str (err));
        }
      err = td_thr_get_info_p ((void *)(uintptr_t)msg.th_p, &ti);
      if (err != TD_OK)
        error ("Cannot get thread info: %s", thread_db_err_str (err));
      ptid = BUILD_THREAD (ti.ti_tid, GET_PID (ptid));
      switch (msg.event)
        {
        case TD_CREATE:
          /* We may already know about this thread, for instance when the
             user has issued the `info threads' command before the SIGTRAP
             for hitting the thread creation breakpoint was reported.  */
          attach_thread (ptid, (void *)(uintptr_t)msg.th_p, &ti, 1);
          break;
       case TD_DEATH:
         if (!in_thread_list (ptid))
           error ("Spurious thread death event.");
         detach_thread (ptid, 1);
         break;
       default:
          error ("Spurious thread event.");
       }
    }
  while (loop);
}

static ptid_t
fbsd_thread_wait (struct target_ops *ops,
		  ptid_t ptid, struct target_waitstatus *ourstatus, int options)
{
  struct target_ops *beneath = find_target_beneath (ops);
  ptid_t ret;
  long lwp;
  CORE_ADDR stop_pc;
  td_thrhandle_t th;
  td_thrinfo_t ti;

  ret = beneath->to_wait (beneath, ptid, ourstatus, options);
  if (GET_PID(ret) >= 0 &&
    ( ourstatus->kind == TARGET_WAITKIND_STOPPED ||
      ourstatus->kind == TARGET_WAITKIND_FORKED ) )
    {
      lwp = get_current_lwp (GET_PID(ret));
      ret = thread_from_lwp (BUILD_LWP(lwp, GET_PID(ret)),
         &th, &ti);
      if (!in_thread_list(ret)) {
        /*
         * We have to enable event reporting for initial thread
         * which was not mapped before.
	 */
        attach_thread(ret, &th, &ti, 1);
      }
      if (ourstatus->value.sig == GDB_SIGNAL_TRAP)
        check_event(ret);
      /* this is a hack, if an event won't cause gdb to stop, for example,
         SIGALRM, gdb resumes the process immediatly without setting
         inferior_ptid to the new thread returned here, this is a bug
         because inferior_ptid may already not exist there, and passing
         a non-existing thread to fbsd_thread_resume causes error. However,
         if the exiting thread is the currently selected thread,
         then that is handled later in handle_inferior_event(), and we must
         not delete the currently selected thread.
      */
      if (!fbsd_thread_alive (ops, inferior_ptid) && !ptid_equal(inferior_ptid, ret))
        {
          ptid_t save_ptid;
          save_ptid = inferior_ptid;
          inferior_ptid = ret;
          delete_thread (save_ptid);
        }
    }

  return (ret);
}

static void
fbsd_thread_fetch_registers (struct target_ops *ops,
			     struct regcache *regcache, int regnum)
{
  prgregset_t gregset;
  prfpregset_t fpregset;
  td_thrhandle_t th;
  td_thrinfo_t ti;
  td_err_e err;
#ifdef PT_GETXMMREGS
  char xmmregs[512];
#endif

  if (!IS_THREAD (inferior_ptid))
    {
      struct target_ops *beneath = find_target_beneath (ops);

      beneath->to_fetch_registers (ops, regcache, regnum);
      return;
    }

  err = td_ta_map_id2thr_p (thread_agent, GET_THREAD (inferior_ptid), &th);
  if (err != TD_OK)
    error ("Cannot find thread %d: Thread ID=%ld, %s",
           pid_to_thread_id (inferior_ptid),
           GET_THREAD (inferior_ptid), thread_db_err_str (err));

  err = td_thr_get_info_p (&th, &ti);
  if (err != TD_OK)
    error ("Cannot get thread info, Thread ID=%ld, %s",
	   GET_THREAD (inferior_ptid), thread_db_err_str (err));

  if (ti.ti_lid != 0)
    {
      struct target_ops *beneath = find_target_beneath (ops);
      struct cleanup *old_chain;

      old_chain = save_inferior_ptid ();

      inferior_ptid = BUILD_LWP (ti.ti_lid, GET_PID (inferior_ptid));
      beneath->to_fetch_registers (ops, regcache, regnum);

      do_cleanups (old_chain);
      return;
    }
  
  err = td_thr_getgregs_p (&th, gregset);
  if (err != TD_OK)
    error ("Cannot fetch general-purpose registers for thread %d: Thread ID=%ld, %s",
           pid_to_thread_id (inferior_ptid),
           GET_THREAD (inferior_ptid), thread_db_err_str (err));
#ifdef PT_GETXMMREGS
  err = td_thr_getxmmregs_p (&th, xmmregs);
  if (err == TD_OK)
    {
      i387_supply_fxsave (regcache, -1, xmmregs);
    }
  else
    {
#endif
      err = td_thr_getfpregs_p (&th, &fpregset);
      if (err != TD_OK)
	error ("Cannot get floating-point registers for thread %d: Thread ID=%ld, %s",
	       pid_to_thread_id (inferior_ptid),
	       GET_THREAD (inferior_ptid), thread_db_err_str (err));
      supply_fpregset (regcache, &fpregset);
#ifdef PT_GETXMMREGS
    }
#endif

  supply_gregset (regcache, gregset);
}

static void
fbsd_thread_store_registers (struct target_ops *ops,
			     struct regcache *regcache, int regnum)
{
  prgregset_t gregset;
  prfpregset_t fpregset;
  td_thrhandle_t th;
  td_thrinfo_t ti;
  td_err_e err;
#ifdef PT_GETXMMREGS
  char xmmregs[512];
#endif

  if (!IS_THREAD (inferior_ptid))
    {
      struct target_ops *beneath = find_target_beneath (ops);

      beneath->to_store_registers (ops, regcache, regnum);
      return;
    }

  err = td_ta_map_id2thr_p (thread_agent, GET_THREAD (inferior_ptid), &th);
  if (err != TD_OK)
    error ("Cannot find thread %d: Thread ID=%ld, %s",
           pid_to_thread_id (inferior_ptid),
           GET_THREAD (inferior_ptid),
           thread_db_err_str (err));

  err = td_thr_get_info_p (&th, &ti);
  if (err != TD_OK)
    error ("Cannot get thread info, Thread ID=%ld, %s",
	   GET_THREAD (inferior_ptid), thread_db_err_str (err));

  if (ti.ti_lid != 0)
    {
      struct target_ops *beneath = find_target_beneath (ops);
      struct cleanup *old_chain;

      old_chain = save_inferior_ptid ();

      inferior_ptid = BUILD_LWP (ti.ti_lid, GET_PID (inferior_ptid));
      beneath->to_store_registers (ops, regcache, regnum);

      do_cleanups (old_chain);
      return;
    }
  
  if (regnum != -1)
    {
      char old_value[MAX_REGISTER_SIZE];

      regcache_raw_collect (regcache, regnum, old_value);
      err = td_thr_getgregs_p (&th, gregset);
      if (err != TD_OK)
        error ("%s: td_thr_getgregs %s", __func__, thread_db_err_str (err));
#ifdef PT_GETXMMREGS
      err = td_thr_getxmmregs_p (&th, xmmregs);
      if (err != TD_OK)
        {
#endif
          err = td_thr_getfpregs_p (&th, &fpregset);
          if (err != TD_OK)
            error ("%s: td_thr_getfpgregs %s", __func__, thread_db_err_str (err));
#ifdef PT_GETXMMREGS
        }
#endif
      regcache_raw_supply (regcache, regnum, old_value);
    }

  fill_gregset (regcache, gregset, regnum);
  err = td_thr_setgregs_p (&th, gregset);
  if (err != TD_OK)
    error ("Cannot store general-purpose registers for thread %d: Thread ID=%ld, %s",
           pid_to_thread_id (inferior_ptid), GET_THREAD (inferior_ptid),
           thread_db_err_str (err));

#ifdef PT_GETXMMREGS
  i387_collect_fxsave (regcache, regnum, xmmregs);
  err = td_thr_setxmmregs_p (&th, xmmregs);
  if (err == TD_OK)
    return;
#endif

  fill_fpregset (regcache, &fpregset, regnum);
  err = td_thr_setfpregs_p (&th, &fpregset);
  if (err != TD_OK)
    error ("Cannot store floating-point registers for thread %d: Thread ID=%ld, %s",
           pid_to_thread_id (inferior_ptid), GET_THREAD (inferior_ptid),
           thread_db_err_str (err));
}

static void
fbsd_thread_mourn_inferior (struct target_ops *ops)
{
  struct target_ops *beneath = find_target_beneath (ops);

  fbsd_thread_deactivate ();

  beneath->to_mourn_inferior (beneath);

  /* Delete thread event breakpoints, if any.  */
  remove_thread_event_breakpoints ();

  unpush_target (ops);
}

static void
fbsd_core_check_lwp (bfd *abfd, asection *asect, void *obj)
{
  lwpid_t lwp;

  if (strncmp (bfd_section_name (abfd, asect), ".reg/", 5) != 0)
    return;

  /* already found */
  if (*(lwpid_t *)obj == 0)
    return;

  lwp = atoi (bfd_section_name (abfd, asect) + 5);
  if (*(lwpid_t *)obj == lwp)
    *(lwpid_t *)obj = 0;
}

static int
fbsd_thread_alive (struct target_ops *ops, ptid_t ptid)
{
  td_thrhandle_t th;
  td_thrinfo_t ti;
  td_err_e err;
  gregset_t gregs;
  lwpid_t lwp;

  if (IS_THREAD (ptid))
    {
      err = td_ta_map_id2thr_p (thread_agent, GET_THREAD (ptid), &th);
      if (err != TD_OK)
        return 0;

      err = td_thr_get_info_p (&th, &ti);
      if (err != TD_OK)
        return 0;

      /* A zombie thread. */
      if (ti.ti_state == TD_THR_UNKNOWN || ti.ti_state == TD_THR_ZOMBIE)
        return 0;

      return 1;
    }
  else if (GET_LWP (ptid) == 0)
    {
      /* we sometimes are called with lwp == 0 */
      return 1;
    }

  if (fbsd_thread_active)
    {
      err = td_ta_map_lwp2thr_p (thread_agent, GET_LWP (ptid), &th);

      /*
       * if the lwp was already mapped to user thread, don't use it
       * directly, please use user thread id instead.
       */
      if (err == TD_OK)
        return 0;
    }

  if (!target_has_execution)
    {
      lwp = GET_LWP (ptid);
      bfd_map_over_sections (core_bfd, fbsd_core_check_lwp, &lwp);
      return (lwp == 0);
    }

  /* check lwp in kernel */
  return ptrace (PT_GETREGS, GET_LWP (ptid), (caddr_t)&gregs, 0) == 0;
}

static int
update_thread_list_callback (const td_thrhandle_t *th_p, void *data)
{
  td_thrinfo_t ti;
  td_err_e err;
  ptid_t ptid;

  err = td_thr_get_info_p (th_p, &ti);
  if (err != TD_OK)
    error ("Cannot get thread info: %s", thread_db_err_str (err));

  /* Ignore zombie */
  if (ti.ti_state == TD_THR_UNKNOWN || ti.ti_state == TD_THR_ZOMBIE)
    return 0;

  ptid = BUILD_THREAD (ti.ti_tid, proc_handle.pid);
  attach_thread (ptid, th_p, &ti, 1);
  return 0;
}

static void
fbsd_thread_update_thread_list (struct target_ops *ops)
{
  td_err_e err;

  /* Delete dead threads.  */
  prune_threads();

  /* Iterate over all user-space threads to discover new threads. */
  err = td_ta_thr_iter_p (thread_agent, update_thread_list_callback, NULL,
          TD_THR_ANY_STATE, TD_THR_LOWEST_PRIORITY,
          TD_SIGNO_MASK, TD_THR_ANY_USER_FLAGS);
  if (err != TD_OK)
    error ("Cannot find new threads: %s", thread_db_err_str (err));
}

static void
fbsd_find_lwp_name(long lwpid, struct private_thread_info *info)
{
  struct cleanup *old_chain;
  int error, name[4];
  unsigned int i;
  struct kinfo_proc *kipp, *kip;
  char *lwpstr = info->lwp_name;
  int pid = inferior_ptid.pid;
  size_t len = 0;

  if (!target_has_execution)
    return;

  name[0] = CTL_KERN;
  name[1] = KERN_PROC;
  name[2] = KERN_PROC_PID | KERN_PROC_INC_THREAD;
  name[3] = pid;

  error = sysctl(name, 4, NULL, &len, NULL, 0);
  if (error < 0) {
    if (errno != ESRCH)
      warning (_("sysctl: kern.proc.pid: %d: %s"), pid,
	       safe_strerror (errno));
    return;
  }

  kip = xmalloc(len);
  if (kip == NULL)
    return;
  old_chain = make_cleanup(xfree, kip);

  if (sysctl(name, 4, kip, &len, NULL, 0) < 0) {
    warning (_("sysctl: kern.proc.pid: %d: %s"), pid, safe_strerror(errno));
    do_cleanups(old_chain);
    return;
  }

  for (i = 0; i < len / sizeof(*kipp); i++) {
      kipp = &kip[i];
      if ((kipp->ki_tid == lwpid) && strlen(kipp->ki_ocomm) &&
          (strcmp(kipp->ki_comm, kipp->ki_ocomm) != 0))
        {
          // Found the LWP, update the name field
          if (lwpstr != NULL)
            {
              if (strcmp(lwpstr, kipp->ki_ocomm) != 0)
                {
                  xfree(lwpstr);
                }
              else
                {
                  // Name hasn't changed, just return
                  break;
                }
            }

	  lwpstr = xstrdup(kipp->ki_ocomm);
          info->lwp_name = lwpstr;
          break;
        }
  }

  do_cleanups(old_chain);
}

static char *
fbsd_thread_pid_to_str (struct target_ops *ops, ptid_t ptid)
{
  static char buf[64];
  struct thread_info *tinfo = NULL;

  if (IS_THREAD (ptid))
    {
      td_thrhandle_t th;
      td_thrinfo_t ti;
      td_err_e err;

      err = td_ta_map_id2thr_p (thread_agent, GET_THREAD (ptid), &th);
      if (err != TD_OK)
        error ("Cannot find thread, Thread ID=%ld, %s",
                GET_THREAD (ptid), thread_db_err_str (err));

      err = td_thr_get_info_p (&th, &ti);
      if (err != TD_OK)
        error ("Cannot get thread info, Thread ID=%ld, %s",
               GET_THREAD (ptid), thread_db_err_str (err));

      tinfo = find_thread_ptid(ptid);
      gdb_assert(tinfo != NULL);

      if (ti.ti_lid != 0)
        {
          // Need to find the name of this LWP, even though it shouldn't change
          fbsd_find_lwp_name(ti.ti_lid, tinfo->priv);

          if (tinfo->priv->lwp_name == NULL)
            {
              snprintf(buf, sizeof (buf), "Thread %llx (LWP %d)",
                  (unsigned long long)th.th_thread, ti.ti_lid);
            }
          else
            {
              snprintf(buf, sizeof (buf), "Thread %llx (LWP %d %s)",
                  (unsigned long long)th.th_thread, ti.ti_lid,
                  tinfo->priv->lwp_name);
            }
        }
      else
        {
          snprintf (buf, sizeof (buf), "Thread %llx (%s)",
		    (unsigned long long)th.th_thread,
		    thread_db_state_str (ti.ti_state));
        }

      return buf;
    }
  else if (IS_LWP (ptid))
    {
      snprintf (buf, sizeof (buf), "LWP %d", (int) GET_LWP (ptid));
      return buf;
    }
  return normal_pid_to_str (ptid);
}

CORE_ADDR
fbsd_thread_get_local_address(struct target_ops *ops,
			      ptid_t ptid,
			      CORE_ADDR lm,
                              CORE_ADDR offset)
{
  td_thrhandle_t th;
  void *address;
  int ret;

  if (IS_THREAD (ptid))
    {
      if (!td_thr_tls_get_addr_p)
        error ("Cannot find thread-local interface in thread_db library.");

      ret = td_ta_map_id2thr_p (thread_agent, GET_THREAD(ptid), &th);

      /* get the address of the variable. */
      ret = td_thr_tls_get_addr_p (&th, (void *)lm, offset, &address);

      if (ret != TD_OK)
        {
            error ("Cannot find thread-local storage for thread %ld\n%s",
                   (long) GET_THREAD (ptid), thread_db_err_str (ret));
        }

      /* Cast assuming host == target. */
      return extract_data_ptr (&address);
    }
  return (0);
}

static int
tsd_cb (thread_key_t key, void (*destructor)(void *), void *ignore)
{
  struct bound_minimal_symbol bms;
  const char *name;

  bms = lookup_minimal_symbol_by_pc (extract_func_ptr (&destructor));
  if (!bms.minsym)
    name = "???";
  else
    name = MSYMBOL_PRINT_NAME (bms.minsym);

  printf_filtered ("Key %d, destructor %p <%s>\n", key, destructor, name);
  return 0;
}

static void
fbsd_thread_tsd_cmd (char *exp, int from_tty)
{
  if (fbsd_thread_active)
    td_ta_tsd_iter_p (thread_agent, tsd_cb, NULL);
}

static void
fbsd_print_sigset (sigset_t *set)
{
  int i;

  for (i = 1; i <= _SIG_MAXSIG; ++i) {
     if (sigismember(set, i)) {
       if (i < sizeof(sys_signame)/sizeof(sys_signame[0]))
         printf_filtered("%s ", sys_signame[i]);
       else
         printf_filtered("sig%d ", i);
     }
  }
  printf_filtered("\n");
}

static void
fbsd_thread_signal_cmd (char *exp, int from_tty)
{
  td_thrhandle_t th;
  td_thrinfo_t ti;
  td_err_e err;
#ifdef PL_FLAG_SI
  const char *code;
#endif

  if (!fbsd_thread_active || !IS_THREAD(inferior_ptid))
    return;

  err = td_ta_map_id2thr_p (thread_agent, GET_THREAD (inferior_ptid), &th);
  if (err != TD_OK)
    return;

  err = td_thr_get_info_p (&th, &ti);
  if (err != TD_OK)
    return;

  printf_filtered("signal mask:\n");
  fbsd_print_sigset(&ti.ti_sigmask);
  printf_filtered("signal pending:\n");
  fbsd_print_sigset(&ti.ti_pending);
#ifdef PL_FLAG_SI
  if (ti.ti_siginfo.si_signo != 0) {
   printf_filtered("si_signo %d si_errno %d", ti.ti_siginfo.si_signo,
     ti.ti_siginfo.si_errno);
   if (ti.ti_siginfo.si_errno != 0)
    printf_filtered(" (%s)", strerror(ti.ti_siginfo.si_errno));
   printf_filtered("\n");
   switch (ti.ti_siginfo.si_code) {
   case SI_NOINFO:
	code = "NOINFO";
	break;
    case SI_USER:
	code = "USER";
	break;
    case SI_QUEUE:
	code = "QUEUE";
	break;
    case SI_TIMER:
	code = "TIMER";
	break;
    case SI_ASYNCIO:
	code = "ASYNCIO";
	break;
    case SI_MESGQ:
	code = "MESGQ";
	break;
    case SI_KERNEL:
	code = "KERNEL";
	break;
    default:
	code = "UNKNOWN";
	break;
    }
    printf_filtered("si_code %s si_pid %d si_uid %d si_status %x si_addr %p\n",
      code, ti.ti_siginfo.si_pid, ti.ti_siginfo.si_uid, ti.ti_siginfo.si_status,
      ti.ti_siginfo.si_addr);
  }
#endif
}

static void
init_fbsd_thread_ops (void)
{
  fbsd_thread_ops.to_shortname = "freebsd-threads";
  fbsd_thread_ops.to_longname = "FreeBSD multithreaded child process.";
  fbsd_thread_ops.to_doc = "FreeBSD threads support.";
  fbsd_thread_ops.to_detach = fbsd_thread_detach;
  fbsd_thread_ops.to_resume = fbsd_thread_resume;
  fbsd_thread_ops.to_wait = fbsd_thread_wait;
  fbsd_thread_ops.to_fetch_registers = fbsd_thread_fetch_registers;
  fbsd_thread_ops.to_store_registers = fbsd_thread_store_registers;
  fbsd_thread_ops.to_mourn_inferior = fbsd_thread_mourn_inferior;
  fbsd_thread_ops.to_thread_alive = fbsd_thread_alive;
  fbsd_thread_ops.to_update_thread_list = fbsd_thread_update_thread_list;
  fbsd_thread_ops.to_pid_to_str = fbsd_thread_pid_to_str;
  fbsd_thread_ops.to_stratum = thread_stratum;
  fbsd_thread_ops.to_get_thread_local_address = fbsd_thread_get_local_address;
  fbsd_thread_ops.to_magic = OPS_MAGIC;
}

static int
thread_db_load (void)
{
  void *handle;
  td_err_e err;

  handle = dlopen (LIBTHREAD_DB_SO, RTLD_NOW);
  if (handle == NULL)
      return 0;

#define resolve(X)			\
 if (!(X##_p = dlsym (handle, #X)))	\
   return 0;

  resolve(td_init);
  resolve(td_ta_new);
  resolve(td_ta_delete);
  resolve(td_ta_map_id2thr);
  resolve(td_ta_map_lwp2thr);
  resolve(td_ta_thr_iter);
  resolve(td_thr_get_info);
#ifdef PT_GETXMMREGS
  resolve(td_thr_getxmmregs);
#endif
  resolve(td_thr_getfpregs);
  resolve(td_thr_getgregs);
#ifdef PT_GETXMMREGS
  resolve(td_thr_setxmmregs);
#endif
  resolve(td_thr_setfpregs);
  resolve(td_thr_setgregs);
  resolve(td_thr_sstep);
  resolve(td_ta_tsd_iter);
  resolve(td_thr_dbsuspend);
  resolve(td_thr_dbresume);
  resolve(td_thr_tls_get_addr);

  /* These are not essential.  */
  td_ta_event_addr_p = dlsym (handle, "td_ta_event_addr");
  td_ta_set_event_p = dlsym (handle, "td_ta_set_event");
  td_ta_event_getmsg_p = dlsym (handle, "td_ta_event_getmsg");
  td_thr_event_enable_p = dlsym (handle, "td_thr_event_enable");
  td_thr_tls_get_addr_p = dlsym (handle, "td_thr_tls_get_addr");

  return 1;
}

void
_initialize_thread_db (void)
{

  init_fbsd_thread_ops ();

  if (thread_db_load ())
    {
      add_target (&fbsd_thread_ops);

      /* "thread tsd" command */
      add_cmd ("tsd", class_run, fbsd_thread_tsd_cmd,
            "Show the thread-specific data keys and destructors "
            "for the process.\n",
           &thread_cmd_list);

      add_cmd ("signal", class_run, fbsd_thread_signal_cmd,
            "Show the thread signal info.\n",
           &thread_cmd_list);

      /* Hook into new_objfile notification.  */
      observer_attach_new_objfile (fbsd_thread_new_objfile);
    }
  else
    {
      fprintf_unfiltered (gdb_stderr,
        "[GDB will not be able to debug user-mode threads: %s]\n", dlerror());
    }
}

/* proc service functions */
void
ps_plog (const char *fmt, ...)
{
  va_list args;

  va_start (args, fmt);
  vfprintf_filtered (gdb_stderr, fmt, args);
  va_end (args);
}

ps_err_e
ps_pglobal_lookup (struct ps_prochandle *ph, const char *obj,
   const char *name, psaddr_t *sym_addr)
{
  struct bound_minimal_symbol ms;
  CORE_ADDR addr;

  ms = lookup_minimal_symbol (name, NULL, NULL);
  if (!ms.minsym) 
    return PS_NOSYM;

  *sym_addr = BMSYMBOL_VALUE_ADDRESS (ms);
  return PS_OK;
}

ps_err_e
ps_pread (struct ps_prochandle *ph, psaddr_t addr, void *buf, size_t len)
{
  int err = target_read_memory (extract_data_ptr (&addr), buf, len);
  return (err == 0 ? PS_OK : PS_ERR);
}

ps_err_e
ps_pwrite (struct ps_prochandle *ph, psaddr_t addr, const void *buf,
            size_t len)
{
  int err = target_write_memory (extract_data_ptr (&addr), (void *)buf, len);
  return (err == 0 ? PS_OK : PS_ERR);
}

ps_err_e
ps_lgetregs (struct ps_prochandle *ph, lwpid_t lwpid, prgregset_t gregset)
{
  struct cleanup *old_chain;
  struct regcache *regcache;

  old_chain = save_inferior_ptid ();

  inferior_ptid = BUILD_LWP (lwpid, ph->pid);
  regcache = get_thread_arch_regcache (inferior_ptid, target_gdbarch ());

  target_fetch_registers (regcache, -1);
  fill_gregset (regcache, gregset, -1);
  do_cleanups (old_chain);
  return PS_OK;
}

ps_err_e
ps_lsetregs (struct ps_prochandle *ph, lwpid_t lwpid, const prgregset_t gregset)
{
  struct cleanup *old_chain;
  struct regcache *regcache;

  old_chain = save_inferior_ptid ();
  inferior_ptid = BUILD_LWP (lwpid, ph->pid);
  regcache = get_thread_arch_regcache (inferior_ptid, target_gdbarch ());

  supply_gregset (regcache, gregset);
  target_store_registers (regcache, -1);
  do_cleanups (old_chain);
  return PS_OK;
}

ps_err_e
ps_lgetfpregs (struct ps_prochandle *ph, lwpid_t lwpid, prfpregset_t *fpregset)
{
  struct cleanup *old_chain;
  struct regcache *regcache;

  old_chain = save_inferior_ptid ();
  inferior_ptid = BUILD_LWP (lwpid, ph->pid);
  regcache = get_thread_arch_regcache (inferior_ptid, target_gdbarch ());

  target_fetch_registers (regcache, -1);
  fill_fpregset (regcache, fpregset, -1);
  do_cleanups (old_chain);
  return PS_OK;
}

ps_err_e
ps_lsetfpregs (struct ps_prochandle *ph, lwpid_t lwpid,
               const prfpregset_t *fpregset)
{
  struct cleanup *old_chain;
  struct regcache *regcache;

  old_chain = save_inferior_ptid ();
  inferior_ptid = BUILD_LWP (lwpid, ph->pid);
  regcache = get_thread_arch_regcache (inferior_ptid, target_gdbarch ());

  supply_fpregset (regcache, fpregset);
  target_store_registers (regcache, -1);
  do_cleanups (old_chain);
  return PS_OK;
}

#ifdef PT_GETXMMREGS
ps_err_e
ps_lgetxmmregs (struct ps_prochandle *ph, lwpid_t lwpid, char *xmmregs)
{
  struct cleanup *old_chain;
  struct regcache *regcache;

  old_chain = save_inferior_ptid ();
  inferior_ptid = BUILD_LWP (lwpid, ph->pid);
  regcache = get_thread_arch_regcache (inferior_ptid, target_gdbarch ());

  target_fetch_registers (regcache, -1);
  i387_collect_fxsave (regcache, -1, xmmregs);
  do_cleanups (old_chain);
  return PS_OK;
}

ps_err_e
ps_lsetxmmregs (struct ps_prochandle *ph, lwpid_t lwpid,
		const char *xmmregs)
{
  struct cleanup *old_chain;
  struct regcache *regcache;

  old_chain = save_inferior_ptid ();
  inferior_ptid = BUILD_LWP (lwpid, ph->pid);
  regcache = get_thread_arch_regcache (inferior_ptid, target_gdbarch ());

  i387_supply_fxsave (regcache, -1, xmmregs);
  target_store_registers (regcache, -1);
  do_cleanups (old_chain);
  return PS_OK;
}
#endif

ps_err_e
ps_lstop(struct ps_prochandle *ph, lwpid_t lwpid)
{
  if (ptrace (PT_SUSPEND, lwpid, 0, 0) == -1)
    return PS_ERR;
  return PS_OK;
}

ps_err_e
ps_lcontinue(struct ps_prochandle *ph, lwpid_t lwpid)
{
  if (ptrace (PT_RESUME, lwpid, 0, 0) == -1)
    return PS_ERR;
  return PS_OK;
}

ps_err_e
ps_linfo(struct ps_prochandle *ph, lwpid_t lwpid, void *info)
{
  if (!target_has_execution) {
    /* XXX should verify lwpid and make a pseudo lwp info */
    memset(info, 0, sizeof(struct ptrace_lwpinfo));
    return PS_OK;
  }

  if (ptrace (PT_LWPINFO, lwpid, info, sizeof(struct ptrace_lwpinfo)) == -1)
    return PS_ERR;
  return PS_OK;
}
