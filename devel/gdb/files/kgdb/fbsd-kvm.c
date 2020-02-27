/*
 * Copyright (c) 2004 Marcel Moolenaar
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include "defs.h"
#include "command.h"
#include "elf-bfd.h"
#include "filenames.h"
#include "gdbcore.h"
#include "gdbthread.h"
#include "gdb_obstack.h"
#include "inferior.h"
#include "objfiles.h"
#include "osabi.h"
#include "process-stratum-target.h"
#include "solib.h"
#include "target.h"
#include "value.h"
#include "readline/tilde.h"

#include <sys/user.h>
#include <fcntl.h>
#include <kvm.h>

#include "kgdb.h"

static CORE_ADDR stoppcbs;
static LONGEST pcb_size;

static char *vmcore;

/* Per-architecture data key.  */
static struct gdbarch_data *fbsd_vmcore_data;

struct fbsd_vmcore_ops
{
  /* Supply registers for a pcb to a register cache.  */
  void (*supply_pcb)(struct regcache *, CORE_ADDR);

  /* Return address of pcb for thread running on a CPU. */
  CORE_ADDR (*cpu_pcb_addr)(u_int);
};

static void *
fbsd_vmcore_init (struct obstack *obstack)
{
  struct fbsd_vmcore_ops *ops;

  ops = OBSTACK_ZALLOC (obstack, struct fbsd_vmcore_ops);
  return ops;
}

/* Set the function that supplies registers from a pcb
   for architecture GDBARCH to SUPPLY_PCB.  */

void
fbsd_vmcore_set_supply_pcb (struct gdbarch *gdbarch,
			    void (*supply_pcb) (struct regcache *,
						CORE_ADDR))
{
  struct fbsd_vmcore_ops *ops = (struct fbsd_vmcore_ops *)
    gdbarch_data (gdbarch, fbsd_vmcore_data);
  ops->supply_pcb = supply_pcb;
}

/* Set the function that returns the address of the pcb for a thread
   running on a CPU for
   architecture GDBARCH to CPU_PCB_ADDR.  */

void
fbsd_vmcore_set_cpu_pcb_addr (struct gdbarch *gdbarch,
			      CORE_ADDR (*cpu_pcb_addr) (u_int))
{
  struct fbsd_vmcore_ops *ops = (struct fbsd_vmcore_ops *)
    gdbarch_data (gdbarch, fbsd_vmcore_data);
  ops->cpu_pcb_addr = cpu_pcb_addr;
}

static CORE_ADDR kernstart;
static kvm_t *kvm;
int kgdb_quiet;

static ptid_t
fbsd_vmcore_ptid(int tid)
{
	if (kvm == NULL)
		/*
		 * The remote target stores the 'tid' in the lwp
		 * field.
		 */
		return ptid_t(inferior_ptid.pid(), tid, 0);

	/*
	 * This follows the model described in bsd-kvm.c except that
	 * in kernel tids are used as the tid of the ptid instead of a
	 * process ID.
	 */
	return ptid_t(1, 1, tid);
}

#define	MSGBUF_SEQ_TO_POS(size, seq)	((seq) % (size))

static void
kgdb_dmesg(void)
{
	CORE_ADDR bufp;
	int size, rseq, wseq;
	gdb_byte c;

	/*
	 * Display the unread portion of the message buffer. This gives the
	 * user a some initial data to work from.
	 */
	if (kgdb_quiet)
		return;
	TRY {
		bufp = parse_and_eval_address("msgbufp->msg_ptr");
		size = parse_and_eval_long("msgbufp->msg_size");
		rseq = parse_and_eval_long("msgbufp->msg_rseq");
		wseq = parse_and_eval_long("msgbufp->msg_wseq");
	} CATCH(e, RETURN_MASK_ERROR) {
		return;
	} END_CATCH
	rseq = MSGBUF_SEQ_TO_POS(size, rseq);
	wseq = MSGBUF_SEQ_TO_POS(size, wseq);
	if (rseq == wseq)
		return;

	printf("\nUnread portion of the kernel message buffer:\n");
	while (rseq < wseq) {
		read_memory(bufp + rseq, &c, 1);
		putchar(c);
		rseq++;
		if (rseq == size)
			rseq = 0;
	}
	if (c != '\n')
		putchar('\n');
	putchar('\n');
}

#define	KERNEL_INTERP		"/red/herring"

enum gdb_osabi
fbsd_kernel_osabi_sniffer(bfd *abfd)
{
	asection *s;
	bfd_byte buf[sizeof(KERNEL_INTERP)];
	bfd_byte *bufp;

	/* First, determine if this is a FreeBSD/ELF binary. */
	switch (elf_elfheader(abfd)->e_ident[EI_OSABI]) {
	case ELFOSABI_FREEBSD:
		break;
	case ELFOSABI_NONE: {
		enum gdb_osabi osabi = GDB_OSABI_UNKNOWN;

		bfd_map_over_sections (abfd,
		    generic_elf_osabi_sniff_abi_tag_sections,
		    &osabi);

		/*
		 * aarch64 kernels don't have the right note tag for
		 * kernels so just look for /red/herring anyway.
		 */
		if (osabi == GDB_OSABI_UNKNOWN &&
		    elf_elfheader(abfd)->e_machine == EM_AARCH64)
			break;
		if (osabi != GDB_OSABI_FREEBSD)
			return (GDB_OSABI_UNKNOWN);
		break;
	}
	default:
		return (GDB_OSABI_UNKNOWN);
	}

	/* FreeBSD ELF kernels have an interpreter path of "/red/herring". */
	bufp = buf;
	s = bfd_get_section_by_name(abfd, ".interp");
	if (s != NULL && bfd_section_size(abfd, s) == sizeof(buf) &&
	    bfd_get_full_section_contents(abfd, s, &bufp) &&
	    memcmp(buf, KERNEL_INTERP, sizeof(buf)) == 0)
		return (GDB_OSABI_FREEBSD_KERNEL);

	return (GDB_OSABI_UNKNOWN);
}

/* The FreeBSD libkvm target.  */

static const target_info fbsd_kvm_target_info = {
  "vmcore",
  N_("Kernel core dump file"),
  N_("Use a vmcore file as a target.\n\
If no filename is specified, /dev/mem is used to examine the running kernel.\n\
target vmcore [-w] [filename]")
};

class fbsd_kvm_target final : public process_stratum_target
{
public:
  fbsd_kvm_target () = default;

  const target_info &info () const override
  { return fbsd_kvm_target_info; }

  void close () override;

  void fetch_registers (struct regcache *, int) override;
  enum target_xfer_status xfer_partial (enum target_object object,
					const char *annex,
					gdb_byte *readbuf,
					const gdb_byte *writebuf,
					ULONGEST offset, ULONGEST len,
					ULONGEST *xfered_len) override;

  void files_info () override;
  bool thread_alive (ptid_t ptid) override;
  void update_thread_list () override;
  const char *pid_to_str (ptid_t) override;
  const char *extra_thread_info (thread_info *) override;

  bool has_all_memory () override { return false; }
  bool has_memory () override;
  bool has_stack () override;
  bool has_registers () override;
  bool has_execution (ptid_t) override { return false; }
};

/* Target ops for libkvm interface.  */
static fbsd_kvm_target fbsd_kvm_ops;

#ifdef HAVE_KVM_OPEN2
static int
kgdb_resolve_symbol(const char *name, kvaddr_t *kva)
{
	struct bound_minimal_symbol ms;

	ms = lookup_minimal_symbol (name, NULL, NULL);
	if (ms.minsym == NULL)
		return (1);
	*kva = BMSYMBOL_VALUE_ADDRESS (ms);
	return (0);
}
#endif

static void
fbsd_kvm_target_open (const char *args, int from_tty)
{
	struct fbsd_vmcore_ops *ops = (struct fbsd_vmcore_ops *)
	    gdbarch_data (target_gdbarch(), fbsd_vmcore_data);
	char kvm_err[_POSIX2_LINE_MAX];
	struct inferior *inf;
	struct cleanup *old_chain;
	struct kthr *kt;
	kvm_t *nkvm;
	char *temp, *kernel, *filename;
	bool writeable;

	if (ops == NULL || ops->supply_pcb == NULL || ops->cpu_pcb_addr == NULL)
		error ("ABI doesn't support a vmcore target");

	target_preopen (from_tty);
	kernel = get_exec_file (1);
	if (kernel == NULL)
		error ("Can't open a vmcore without a kernel");

	writeable = false;
	filename = NULL;
	if (args != NULL) {
		gdb_argv built_argv (args);

		for (char **argv = built_argv.get (); *argv != NULL; argv++) {
			if (**argv == '-') {
				if (strcmp (*argv, "-w") == 0)
					writeable = true;
				else
					error (_("Invalid argument"));
			} else {
				if (filename != NULL)
					error (_("Invalid argument"));

				filename = tilde_expand (*argv);
				if (!IS_ABSOLUTE_PATH (filename)) {
					temp = concat (current_directory, "/",
					    filename, NULL);
					xfree(filename);
					filename = temp;
				}
			}
		}
	}

	old_chain = make_cleanup (xfree, filename);

#ifdef HAVE_KVM_OPEN2
	nkvm = kvm_open2(kernel, filename,
	    writeable ? O_RDWR : O_RDONLY, kvm_err, kgdb_resolve_symbol);
#else
	nkvm = kvm_openfiles(kernel, filename, NULL,
	    writeable ? O_RDWR : O_RDONLY, kvm_err);
#endif
	if (nkvm == NULL)
		error ("Failed to open vmcore: %s", kvm_err);

	/* Don't free the filename now and close any previous vmcore. */
	discard_cleanups(old_chain);
	unpush_target(&fbsd_kvm_ops);

#ifdef HAVE_KVM_DISP
	/* Relocate kernel objfile if needed. */
	if (symfile_objfile &&
	    (bfd_get_file_flags(symfile_objfile->obfd) &
	      (EXEC_P | DYNAMIC)) != 0) {
		struct section_offsets *new_offsets;
		int i;
		CORE_ADDR displacement;

		displacement = kvm_kerndisp(nkvm);
		if (displacement != 0) {
			new_offsets = XALLOCAVEC (struct section_offsets,
				symfile_objfile->num_sections);

			for (i = 0; i < symfile_objfile->num_sections; i++)
				new_offsets->offsets[i] = displacement;

			objfile_relocate(symfile_objfile, new_offsets);
		}
	}
#endif

	/*
	 * Determine the first address in KVA.  Newer kernels export
	 * VM_MAXUSER_ADDRESS and the first kernel address can be
	 * determined by adding one.  Older kernels do not provide a
	 * symbol that is valid on all platforms, but kernbase is close
	 * for most platforms.
	 */
	TRY {
		kernstart = parse_and_eval_address("vm_maxuser_address") + 1;
	} CATCH(e, RETURN_MASK_ERROR) {
		kernstart = kgdb_lookup("kernbase");
	} END_CATCH

	/*
	 * Lookup symbols needed for stoppcbs[] handling, but don't
	 * fail if they aren't present.
	 */
	stoppcbs = kgdb_lookup("stoppcbs");
	TRY {
		pcb_size = parse_and_eval_long("pcb_size");
	} CATCH(e, RETURN_MASK_ERROR) {
		pcb_size = 0;
	} END_CATCH

	if (pcb_size == 0) {
		TRY {
			pcb_size = parse_and_eval_long("sizeof(struct pcb)");
		} CATCH(e, RETURN_MASK_ERROR) {
#ifdef HAVE_KVM_OPEN2
			if (kvm_native(nkvm))
				pcb_size = sizeof(struct pcb);
			else
				pcb_size = 0;
#else
			pcb_size = sizeof(struct pcb);
#endif
		} END_CATCH
	}

	kvm = nkvm;
	vmcore = filename;
	push_target (&fbsd_kvm_ops);

	kgdb_dmesg();

	inf = current_inferior();
	if (inf->pid == 0) {
		inferior_appeared(inf, 1);
		inf->fake_pid_p = 1;
	}
	solib_create_inferior_hook(0);
	init_thread_list();
	kt = kgdb_thr_init(ops->cpu_pcb_addr);
	while (kt != NULL) {
		add_thread_silent(fbsd_vmcore_ptid(kt->tid));
		kt = kgdb_thr_next(kt);
	}
	if (curkthr != 0)
		inferior_ptid = fbsd_vmcore_ptid(curkthr->tid);

	target_fetch_registers (get_current_regcache (), -1);

	reinit_frame_cache ();
	print_stack_frame (get_selected_frame (NULL), 0, SRC_AND_LOC, 1);
}

void
fbsd_kvm_target::close()
{

	if (kvm != NULL) {
		clear_solib();
		if (kvm_close(kvm) != 0)
			warning("cannot close \"%s\": %s", vmcore,
			    kvm_geterr(kvm));
		kvm = NULL;
		xfree(vmcore);
		vmcore = NULL;
	}

	inferior_ptid = null_ptid;
}

#if 0
static void
kgdb_trgt_detach(struct target_ops *ops, const char *args, int from_tty)
{

	if (args)
		error ("Too many arguments");
	unpush_target(&kgdb_trgt_ops);
	reinit_frame_cache();
	if (from_tty)
		printf_filtered("No vmcore file now.\n");
}
#endif

const char *
fbsd_kvm_target::extra_thread_info(thread_info *ti)
{

	return (kgdb_thr_extra_thread_info(ti->ptid.tid()));
}

bool
fbsd_kvm_target::has_memory ()
{
  return (kvm != NULL);
}

bool
fbsd_kvm_target::has_stack ()
{
  return (kvm != NULL);
}

bool
fbsd_kvm_target::has_registers ()
{
  return (kvm != NULL);
}

void
fbsd_kvm_target::files_info()
{

	printf_filtered ("\t`%s', ", vmcore);
	wrap_here ("        ");
	printf_filtered ("file type %s.\n", "FreeBSD kernel vmcore");
}

void
fbsd_kvm_target::update_thread_list()
{
	/*
	 * XXX: We should probably rescan the thread list here and update
	 * it if there are any changes.  One nit though is that we'd have
	 * to detect exited threads.
	 */
	gdb_assert(kvm != NULL);
#if 0
	prune_threads();
#endif
#if 0
	struct target_ops *tb;
	
	if (kvm != NULL)
		return;

	tb = find_target_beneath(ops);
	if (tb->to_update_thread_list != NULL)
		tb->to_update_thread_list(tb);
#endif
}

const char *
fbsd_kvm_target::pid_to_str(ptid_t ptid)
{
	static char buf[33];

	snprintf(buf, sizeof(buf), "Thread %ld", ptid.tid());
	return (buf);
}

bool
fbsd_kvm_target::thread_alive(ptid_t ptid)
{
	return (kgdb_thr_lookup_tid(ptid.tid()) != NULL);
}

void
fbsd_kvm_target::fetch_registers(struct regcache *regcache, int regnum)
{
	struct fbsd_vmcore_ops *ops = (struct fbsd_vmcore_ops *)
	    gdbarch_data (target_gdbarch(), fbsd_vmcore_data);
	struct kthr *kt;

	if (ops->supply_pcb == NULL)
		return;
	kt = kgdb_thr_lookup_tid(inferior_ptid.tid());
	if (kt == NULL)
		return;
	ops->supply_pcb(regcache, kt->pcb);
}

enum target_xfer_status
fbsd_kvm_target::xfer_partial(enum target_object object,
		       const char *annex, gdb_byte *readbuf,
		       const gdb_byte *writebuf,
		       ULONGEST offset, ULONGEST len, ULONGEST *xfered_len)
{
	ssize_t nbytes;

	gdb_assert(kvm != NULL);
	switch (object) {
	case TARGET_OBJECT_MEMORY:
		nbytes = len;
		if (readbuf != NULL)
#ifdef HAVE_KVM_OPEN2
			nbytes = kvm_read2(kvm, offset, readbuf, len);
#else
			nbytes = kvm_read(kvm, offset, readbuf, len);
#endif
		if (writebuf != NULL && len > 0)
			nbytes = kvm_write(kvm, offset, writebuf, len);
		if (nbytes < 0)
			return TARGET_XFER_E_IO;
		if (nbytes == 0)
			return TARGET_XFER_EOF;
		*xfered_len = nbytes;
		return TARGET_XFER_OK;
	default:
		return TARGET_XFER_E_IO;
	}
}

#if 0
static int
kgdb_trgt_insert_breakpoint(struct target_ops *ops, struct gdbarch *gdbarch,
    struct bp_target_info *bp_tgt)
{

	return 0;
}

static int
kgdb_trgt_remove_breakpoint(struct target_ops *ops, struct gdbarch *gdbarch,
    struct bp_target_info *bp_tgt, enum remove_bp_reason reason)
{

	return 0;
}
#endif

static void
kgdb_switch_to_thread(const char *arg, int tid)
{
  struct thread_info *tp;

  tp = find_thread_ptid (fbsd_vmcore_ptid (tid));
  if (tp == NULL)
    error ("invalid tid");
  thread_select (arg, tp);
}

static void
kgdb_set_proc_cmd (const char *arg, int from_tty)
{
	CORE_ADDR addr;
	struct kthr *thr;

	if (!arg)
		error_no_arg ("proc address for the new context");

	if (kvm == NULL)
		error ("only supported for core file target");

	addr = parse_and_eval_address (arg);

	if (addr < kernstart) {
		thr = kgdb_thr_lookup_pid((int)addr);
		if (thr == NULL)
			error ("invalid pid");
	} else {
		thr = kgdb_thr_lookup_paddr(addr);
		if (thr == NULL)
			error("invalid proc address");
	}
	kgdb_switch_to_thread(arg, thr->tid);
}

static void
kgdb_set_tid_cmd (const char *arg, int from_tty)
{
	CORE_ADDR addr;
	struct kthr *thr;

	if (!arg)
		error_no_arg ("TID or thread address for the new context");

	addr = (CORE_ADDR) parse_and_eval_address (arg);

	if (kvm != NULL && addr >= kernstart) {
		thr = kgdb_thr_lookup_taddr(addr);
		if (thr == NULL)
			error("invalid thread address");
		addr = thr->tid;
	}
	kgdb_switch_to_thread(arg, addr);
}

void
_initialize_kgdb_target(void)
{

	add_target(fbsd_kvm_target_info, fbsd_kvm_target_open);

	fbsd_vmcore_data = gdbarch_data_register_pre_init(fbsd_vmcore_init);

	add_com ("proc", class_obscure, kgdb_set_proc_cmd,
	   "Set current process context");
	add_com ("tid", class_obscure, kgdb_set_tid_cmd,
	   "Set current thread context");
}

CORE_ADDR
kgdb_trgt_stop_pcb(u_int cpuid)
{

	if (stoppcbs == 0 || pcb_size == 0)
		return 0;

	return (stoppcbs + pcb_size * cpuid);
}
