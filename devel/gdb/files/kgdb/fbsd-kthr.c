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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/proc.h>
#include <stdbool.h>

#include <defs.h>
#include "gdbcore.h"
#include "objfiles.h"
#include "value.h"

#include "kgdb.h"

static CORE_ADDR dumppcb;
static LONGEST dumptid;

static CORE_ADDR stopped_cpus;
static LONGEST mp_maxid;

static struct kthr *first, *last;
struct kthr *curkthr;

static int proc_off_p_pid, proc_off_p_comm, proc_off_p_list, proc_off_p_threads;
static int thread_off_td_tid, thread_off_td_oncpu, thread_off_td_pcb;
static int thread_off_td_name, thread_off_td_plist;
static int thread_oncpu_size;

CORE_ADDR
kgdb_lookup(const char *sym)
{
	struct bound_minimal_symbol msym;

	msym = lookup_minimal_symbol(sym, NULL, NULL);
	if (msym.minsym == NULL)
		return (0);
	return (BMSYMBOL_VALUE_ADDRESS(msym));
}

/*
 * Perform the equivalent of CPU_ISSET() to see if 'cpu' is set in the
 * kernel's stopped_cpus set.  The set contains an array of longs.
 * This function determines the specific long to read and tests the
 * necessary bit in the long.
 */
static bool
cpu_stopped(int cpu)
{
	struct gdbarch *gdbarch = target_gdbarch ();
	CORE_ADDR addr;
	ULONGEST mask;
	int bit, long_bytes, word;

	if (cpu < 0 || cpu > mp_maxid || stopped_cpus == 0)
		return (false);
	bit = cpu % gdbarch_long_bit (gdbarch);
	word = cpu / gdbarch_long_bit (gdbarch);
	long_bytes = gdbarch_long_bit (gdbarch) / 8;
	addr = stopped_cpus + word * long_bytes;
	mask = read_memory_unsigned_integer (addr, long_bytes,
	    gdbarch_byte_order (gdbarch));
	return (mask & ((ULONGEST)1 << bit)) != 0;
}

struct kthr *
kgdb_thr_first(void)
{
	return (first);
}

static void
kgdb_thr_add_procs(CORE_ADDR paddr, CORE_ADDR (*cpu_pcb_addr) (u_int))
{
	struct gdbarch *gdbarch = target_gdbarch ();
	struct type *ptr_type = builtin_type (gdbarch)->builtin_data_ptr;
	enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
	struct kthr *kt;
	CORE_ADDR pcb, pnext, tdaddr, tdnext;
	ULONGEST oncpu;
	LONGEST pid, tid;

	while (paddr != 0) {
		try {
			tdaddr = read_memory_typed_address (paddr +
			    proc_off_p_threads, ptr_type);
			pid = read_memory_integer (paddr + proc_off_p_pid, 4,
			    byte_order);
			pnext = read_memory_typed_address (paddr +
			    proc_off_p_list, ptr_type);
		} catch (const gdb_exception_error &e) {
			break;
		}
		while (tdaddr != 0) {
			try {
				tid = read_memory_integer (tdaddr +
				    thread_off_td_tid, 4, byte_order);
				oncpu = read_memory_unsigned_integer (tdaddr +
				    thread_off_td_oncpu, thread_oncpu_size,
				    byte_order);
				pcb = read_memory_typed_address (tdaddr +
				    thread_off_td_pcb, ptr_type);
				tdnext = read_memory_typed_address (tdaddr +
				    thread_off_td_plist, ptr_type);
			} catch (const gdb_exception_error &e) {
				break;
			}
			kt = XNEW (struct kthr);
			if (last == NULL)
				first = last = kt;
			else
				last->next = kt;
			kt->next = NULL;
			kt->kaddr = tdaddr;
			if (tid == dumptid)
				kt->pcb = dumppcb;
			else if (cpu_stopped(oncpu))
				kt->pcb = cpu_pcb_addr(oncpu);
			else
				kt->pcb = pcb;
			kt->tid = tid;
			kt->pid = pid;
			kt->paddr = paddr;
			kt->cpu = oncpu;
			last = kt;
			tdaddr = tdnext;
		}
		paddr = pnext;
	}
}

struct kthr *
kgdb_thr_init(CORE_ADDR (*cpu_pcb_addr) (u_int))
{
	struct gdbarch *gdbarch = target_gdbarch ();
	struct type *ptr_type = builtin_type (gdbarch)->builtin_data_ptr;
	struct kthr *kt;
	CORE_ADDR addr, paddr;
	
	while (first != NULL) {
		kt = first;
		first = kt->next;
		free(kt);
	}
	last = NULL;

	addr = kgdb_lookup("allproc");
	if (addr == 0)
		return (NULL);
	try {
		paddr = read_memory_typed_address (addr, ptr_type);
	} catch (const gdb_exception_error &e) {
		return (NULL);
	}

	dumppcb = kgdb_lookup("dumppcb");
	if (dumppcb == 0)
		return (NULL);

	try {
		dumptid = parse_and_eval_long("dumptid");
	} catch (const gdb_exception_error &e) {
		dumptid = -1;
	}

	try {
		mp_maxid = parse_and_eval_long("mp_maxid");
	} catch (const gdb_exception_error &e) {
		mp_maxid = 0;
	}
	stopped_cpus = kgdb_lookup("stopped_cpus");

	/*
	 * Newer kernels export a set of global variables with the offsets
	 * of certain members in struct proc and struct thread.  For older
	 * kernels, try to extract these offsets using debug symbols.  If
	 * that fails, use native values.
	 */
	try {
		proc_off_p_pid = parse_and_eval_long("proc_off_p_pid");
		proc_off_p_comm = parse_and_eval_long("proc_off_p_comm");
		proc_off_p_list = parse_and_eval_long("proc_off_p_list");
		proc_off_p_threads = parse_and_eval_long("proc_off_p_threads");
		thread_off_td_tid = parse_and_eval_long("thread_off_td_tid");
		thread_off_td_name = parse_and_eval_long("thread_off_td_name");
		thread_off_td_oncpu = parse_and_eval_long("thread_off_td_oncpu");
		thread_off_td_pcb = parse_and_eval_long("thread_off_td_pcb");
		thread_off_td_plist = parse_and_eval_long("thread_off_td_plist");
		thread_oncpu_size = 4;
	} catch (const gdb_exception_error &e) {
		try {
			struct symbol *proc_sym =
			    lookup_symbol_in_language ("struct proc", NULL,
				STRUCT_DOMAIN, language_c, NULL).symbol;
			if (proc_sym == NULL)
				error (_("Unable to find struct proc symbol"));

			proc_off_p_pid =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym), "p_pid",
				0).offset / 8;
			proc_off_p_comm =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym), "p_comm",
				0).offset / 8;
			proc_off_p_list =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym), "p_list",
				0).offset / 8;
			proc_off_p_threads =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym),
				"p_threads", 0).offset / 8;

			struct symbol *thread_sym =
			    lookup_symbol_in_language ("struct thread", NULL,
				STRUCT_DOMAIN, language_c, NULL).symbol;
			if (thread_sym == NULL)
				error (_("Unable to find struct thread symbol"));

			thread_off_td_tid =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym), "td_tid",
				0).offset / 8;
			thread_off_td_name =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym), "td_name",
				0).offset / 8;
			thread_off_td_pcb =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym), "td_pcb",
				0).offset / 8;
			thread_off_td_plist =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym), "td_plist",
				0).offset / 8;

			struct_elt td_oncpu =
			    lookup_struct_elt (SYMBOL_TYPE (proc_sym), "td_oncpu",
				0);
			thread_off_td_oncpu = td_oncpu.offset / 8;
			thread_oncpu_size = FIELD_BITSIZE(*td_oncpu.field) / 8;
		} catch (const gdb_exception_error &e2) {
			proc_off_p_pid = offsetof(struct proc, p_pid);
			proc_off_p_comm = offsetof(struct proc, p_comm);
			proc_off_p_list = offsetof(struct proc, p_list);
			proc_off_p_threads = offsetof(struct proc, p_threads);
			thread_off_td_tid = offsetof(struct thread, td_tid);
			thread_off_td_name = offsetof(struct thread, td_name);
			thread_off_td_oncpu = offsetof(struct thread, td_oncpu);
			thread_off_td_pcb = offsetof(struct thread, td_pcb);
			thread_off_td_plist = offsetof(struct thread, td_plist);
			thread_oncpu_size =
			    sizeof(((struct thread *)0)->td_oncpu);
		}
	}

	kgdb_thr_add_procs(paddr, cpu_pcb_addr);
	addr = kgdb_lookup("zombproc");
	if (addr != 0) {
		try {
			paddr = read_memory_typed_address (addr, ptr_type);
			kgdb_thr_add_procs(paddr, cpu_pcb_addr);
		} catch (const gdb_exception_error &e) {
		}
	}
	curkthr = kgdb_thr_lookup_tid(dumptid);
	if (curkthr == NULL)
		curkthr = first;
	return (first);
}

struct kthr *
kgdb_thr_lookup_tid(int tid)
{
	struct kthr *kt;

	kt = first;
	while (kt != NULL && kt->tid != tid)
		kt = kt->next;
	return (kt);
}

struct kthr *
kgdb_thr_lookup_taddr(uintptr_t taddr)
{
	struct kthr *kt;

	kt = first;
	while (kt != NULL && kt->kaddr != taddr)
		kt = kt->next;
	return (kt);
}

struct kthr *
kgdb_thr_lookup_pid(int pid)
{
	struct kthr *kt;

	kt = first;
	while (kt != NULL && kt->pid != pid)
		kt = kt->next;
	return (kt);
}

struct kthr *
kgdb_thr_lookup_paddr(uintptr_t paddr)
{
	struct kthr *kt;

	kt = first;
	while (kt != NULL && kt->paddr != paddr)
		kt = kt->next;
	return (kt);
}

struct kthr *
kgdb_thr_next(struct kthr *kt)
{
	return (kt->next);
}

const char *
kgdb_thr_extra_thread_info(int tid)
{
	char comm[MAXCOMLEN + 1];
	char td_name[MAXCOMLEN + 1];
	struct kthr *kt;
	static char buf[64];

	kt = kgdb_thr_lookup_tid(tid);
	if (kt == NULL)
		return (NULL);	
	snprintf(buf, sizeof(buf), "PID=%d", kt->pid);
	try {
		read_memory_string (kt->paddr + proc_off_p_comm, comm,
		    sizeof(comm));
		strlcat(buf, ": ", sizeof(buf));
		strlcat(buf, comm, sizeof(buf));
		read_memory_string (kt->kaddr + thread_off_td_name, td_name,
		    sizeof(td_name));
		if (strcmp(comm, td_name) != 0) {
			strlcat(buf, "/", sizeof(buf));
			strlcat(buf, td_name, sizeof(buf));
		}
	} catch (const gdb_exception_error &e) {
	}
	return (buf);
}
