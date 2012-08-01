
$FreeBSD$

--- src/sysdep.c.orig
+++ src/sysdep.c
@@ -37,6 +37,20 @@
 #include "sysselect.h"
 #include "blockinput.h"
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+/* machine/frame.h in Sparc has 'struct frame' which conflicts with Emacs' 'struct frame', so rename it */
+#ifdef __sparc__ 
+#define frame freebsd_sparc_frame
+#endif
+#include <sys/user.h>
+#ifdef __sparc__ 
+#undef frame
+#endif
+#include <sys/resource.h>
+#include <math.h>
+#endif
+
 #ifdef WINDOWSNT
 #define read sys_read
 #define write sys_write
@@ -2529,6 +2543,40 @@
   return proclist;
 }
 
+#elif defined (__FreeBSD__)
+
+Lisp_Object
+list_system_processes ()
+{
+  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PROC};
+  size_t len;
+  struct kinfo_proc *procs;
+  size_t i;
+
+  struct gcpro gcpro1;
+  Lisp_Object proclist = Qnil;
+
+  if (sysctl (mib, 3, NULL, &len, NULL, 0) != 0)
+    return proclist;
+  
+  procs = xmalloc (len);
+  if (sysctl (mib, 3, procs, &len, NULL, 0) != 0)
+    {
+      xfree (procs);
+      return proclist;
+    }
+  
+  GCPRO1 (proclist);
+  len /= sizeof (struct kinfo_proc);
+  for (i = 0; i < len; i++)
+    proclist = Fcons (make_fixnum_or_float (procs[i].ki_pid), proclist);
+  UNGCPRO;
+  
+  xfree (procs);
+
+  return  proclist;
+}
+
 /* The WINDOWSNT implementation is in w32.c.
    The MSDOS implementation is in dosfns.c.  */
 #elif !defined (WINDOWSNT) && !defined (MSDOS)
@@ -3079,6 +3127,176 @@
   return attrs;
 }
 
+#elif defined(__FreeBSD__)
+
+Lisp_Object
+system_process_attributes (Lisp_Object pid)
+{
+  int proc_id;
+  int pagesize = getpagesize();
+  int npages;
+  int fscale;
+  struct passwd *pw;
+  struct group  *gr;
+  char *ttyname;
+  size_t len;
+  char args[MAXPATHLEN];
+  EMACS_TIME t, now;
+  
+  int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID};
+  struct kinfo_proc proc;
+  size_t proclen = sizeof(proc);
+
+  struct gcpro gcpro1, gcpro2;
+  Lisp_Object attrs = Qnil;
+  Lisp_Object decoded_comm;
+  
+  CHECK_NUMBER_OR_FLOAT (pid);
+  proc_id = FLOATP (pid) ? XFLOAT_DATA (pid) : XINT (pid);
+  mib[3] = proc_id;
+  
+  if (sysctl (mib, 4, &proc, &proclen, NULL, 0) != 0)
+    return attrs;
+
+  GCPRO2 (attrs, decoded_comm);
+  
+  attrs = Fcons (Fcons (Qeuid, make_fixnum_or_float(proc.ki_uid)), attrs);
+  
+  BLOCK_INPUT;
+  pw = getpwuid (proc.ki_uid);
+  UNBLOCK_INPUT;
+  if (pw)
+    attrs = Fcons (Fcons (Quser, build_string (pw->pw_name)), attrs);
+
+  attrs = Fcons (Fcons (Qegid, make_fixnum_or_float(proc.ki_svgid)), attrs);
+
+  BLOCK_INPUT;
+  gr = getgrgid (proc.ki_svgid);
+  UNBLOCK_INPUT;
+  if (gr)
+    attrs = Fcons (Fcons (Qgroup, build_string (gr->gr_name)), attrs);
+
+  decoded_comm = code_convert_string_norecord
+    (make_unibyte_string (proc.ki_comm, strlen (proc.ki_comm)),
+     Vlocale_coding_system, 0);
+  
+  attrs = Fcons (Fcons (Qcomm, decoded_comm), attrs);
+  {
+    char state[2] = {'\0', '\0'};
+    switch (proc.ki_stat)
+      {
+      case SRUN:
+	state[0] = 'R';
+	break;
+
+      case SSLEEP:
+	state[0] = 'S';
+	break;
+	
+      case SLOCK:
+	state[0] = 'D';
+	break;
+
+      case SZOMB:
+	state[0] = 'Z';
+	break;
+	
+      case SSTOP:
+	state[0] = 'T';
+	break;
+      }
+    attrs = Fcons (Fcons (Qstate, build_string (state)), attrs);
+  }
+  
+  attrs = Fcons (Fcons (Qppid, make_fixnum_or_float (proc.ki_ppid)), attrs);
+  attrs = Fcons (Fcons (Qpgrp, make_fixnum_or_float (proc.ki_pgid)), attrs);
+  attrs = Fcons (Fcons (Qsess, make_fixnum_or_float (proc.ki_sid)),  attrs);
+
+  BLOCK_INPUT;
+  ttyname = proc.ki_tdev == NODEV ? NULL : devname (proc.ki_tdev, S_IFCHR);
+  UNBLOCK_INPUT;
+  if (ttyname)
+    attrs = Fcons (Fcons (Qtty, build_string (ttyname)), attrs);
+  
+  attrs = Fcons (Fcons (Qtpgid,   make_fixnum_or_float (proc.ki_tpgid)), attrs);
+  attrs = Fcons (Fcons (Qminflt,  make_fixnum_or_float (proc.ki_rusage.ru_minflt)), attrs);
+  attrs = Fcons (Fcons (Qmajflt,  make_fixnum_or_float (proc.ki_rusage.ru_majflt)), attrs);
+  attrs = Fcons (Fcons (Qcminflt, make_number (proc.ki_rusage_ch.ru_minflt)), attrs);
+  attrs = Fcons (Fcons (Qcmajflt, make_number (proc.ki_rusage_ch.ru_majflt)), attrs);
+
+#define TIMELIST(ts)					\
+  list3 (make_number (EMACS_SECS (ts) >> 16 & 0xffff),	\
+	 make_number (EMACS_SECS (ts) & 0xffff),	\
+	 make_number (EMACS_USECS (ts)))
+
+  attrs = Fcons (Fcons (Qutime, TIMELIST(proc.ki_rusage.ru_utime)), attrs);
+  attrs = Fcons (Fcons (Qstime, TIMELIST(proc.ki_rusage.ru_stime)), attrs);
+  EMACS_ADD_TIME (t, proc.ki_rusage.ru_utime, proc.ki_rusage.ru_stime);
+  attrs = Fcons (Fcons (Qtime,  TIMELIST(t)), attrs);
+
+  attrs = Fcons (Fcons (Qcutime, TIMELIST(proc.ki_rusage_ch.ru_utime)), attrs);
+  attrs = Fcons (Fcons (Qcstime, TIMELIST(proc.ki_rusage_ch.ru_utime)), attrs);
+  EMACS_ADD_TIME (t, proc.ki_rusage_ch.ru_utime, proc.ki_rusage_ch.ru_stime);
+  attrs = Fcons (Fcons (Qctime, TIMELIST(t)), attrs);
+
+  attrs = Fcons (Fcons (Qthcount, make_fixnum_or_float (proc.ki_numthreads)), attrs);
+  attrs = Fcons (Fcons (Qpri,   make_number (proc.ki_pri.pri_native)), attrs);
+  attrs = Fcons (Fcons (Qnice,  make_number (proc.ki_nice)), attrs);
+  attrs = Fcons (Fcons (Qstart, TIMELIST(proc.ki_start)), attrs);
+  attrs = Fcons (Fcons (Qvsize, make_number (proc.ki_size >> 10)), attrs);
+  attrs = Fcons (Fcons (Qrss,   make_number (proc.ki_rssize * pagesize >> 10)), attrs);
+
+  EMACS_GET_TIME (now);
+  EMACS_SUB_TIME (t, now, proc.ki_start);
+  attrs = Fcons (Fcons (Qetime, TIMELIST(t)), attrs);
+
+#undef TIMELIST
+  
+  len = sizeof(fscale);
+  if (sysctlbyname ("kern.fscale", &fscale, &len, NULL, 0) == 0)
+    {
+      float   pcpu;
+      fixpt_t ccpu;
+      len = sizeof (ccpu);
+      if (sysctlbyname ("kern.ccpu", &ccpu, &len, NULL, 0) == 0)
+      	{
+      	  pcpu = 100.0 * ((double) proc.ki_pctcpu / fscale)
+  	    / (1.0 - exp(proc.ki_swtime * log((double) ccpu / fscale)));
+  	  attrs = Fcons (Fcons (Qpcpu, make_fixnum_or_float(pcpu)), attrs);
+      	}
+    }
+
+  len = sizeof(npages);
+  if (sysctlbyname ("hw.availpages", &npages, &len, NULL, 0) == 0)
+    {
+      float pmem = proc.ki_flag & P_INMEM
+  	? 100.0 * ((float) proc.ki_rssize / npages)
+  	: 0.0;
+      attrs = Fcons (Fcons (Qpmem, make_fixnum_or_float(pmem)), attrs);
+    }
+
+  mib[2] = KERN_PROC_ARGS;
+  len = MAXPATHLEN;
+  if (sysctl (mib, 4, args, &len, NULL, 0) == 0)
+    {
+      int i;
+      for (i = 0; i < len; i++)
+	{
+	  if (! args[i] && i < len - 1)
+	    args[i] = ' ';
+	}
+
+      decoded_comm = code_convert_string_norecord
+	(make_unibyte_string (args, strlen (args)),
+	 Vlocale_coding_system, 0);
+
+      attrs = Fcons (Fcons (Qargs, decoded_comm), attrs);
+    }
+  
+  UNGCPRO;
+  return attrs;
+}
+
 /* The WINDOWSNT implementation is in w32.c.
    The MSDOS implementation is in dosfns.c.  */
 #elif !defined (WINDOWSNT) && !defined (MSDOS)
