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

static struct kthr *first;
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
		TRY {
			tdaddr = read_memory_typed_address (paddr +
			    proc_off_p_threads, ptr_type);
			pid = read_memory_integer (paddr + proc_off_p_pid, 4,
			    byte_order);
			pnext = read_memory_typed_address (paddr +
			    proc_off_p_list, ptr_type);
		} CATCH(e, RETURN_MASK_ERROR) {
			break;
		} END_CATCH
		while (tdaddr != 0) {
			TRY {
				tid = read_memory_integer (tdaddr +
				    thread_off_td_tid, 4, byte_order);
				oncpu = read_memory_unsigned_integer (tdaddr +
				    thread_off_td_oncpu, thread_oncpu_size,
				    byte_order);
				pcb = read_memory_typed_address (tdaddr +
				    thread_off_td_pcb, ptr_type);
				tdnext = read_memory_typed_address (tdaddr +
				    thread_off_td_plist, ptr_type);
			} CATCH(e, RETURN_MASK_ERROR) {
				break;
			} END_CATCH
			kt = XNEW (struct kthr);
			kt->next = first;
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
			first = kt;
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
	enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
	struct kthr *kt;
	CORE_ADDR addr, paddr;
	
	while (first != NULL) {
		kt = first;
		first = kt->next;
		free(kt);
	}

	addr = kgdb_lookup("allproc");
	if (addr == 0)
		return (NULL);
	TRY {
		paddr = read_memory_typed_address (addr, ptr_type);
	} CATCH(e, RETURN_MASK_ERROR) {
		return (NULL);
	} END_CATCH

	dumppcb = kgdb_lookup("dumppcb");
	if (dumppcb == 0)
		return (NULL);

#if 1
	TRY {
		dumptid = parse_and_eval_long("dumptid");
	} CATCH(e, RETURN_MASK_ERROR) {
		dumptid = -1;
	} END_CATCH
#else
	addr = kgdb_lookup("dumptid");
	if (addr != 0) {
		TRY {
			dumptid = read_memory_integer (addr, 4, byte_order);
		} CATCH(e, RETURN_MASK_ERROR) {
			dumptid = -1;
		} END_CATCH
	} else
		dumptid = -1;
#endif

	TRY {
		mp_maxid = parse_and_eval_long("mp_maxid");
	} CATCH(e, RETURN_MASK_ERROR) {
		mp_maxid = 0;
	} END_CATCH
	stopped_cpus = kgdb_lookup("stopped_cpus");

	/*
	 * Newer kernels export a set of global variables with the offsets
	 * of certain members in struct proc and struct thread.  For older
	 * kernels, try to extract these offsets using debug symbols.  If
	 * that fails, use native values.
	 */
	TRY {
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
	} CATCH(e, RETURN_MASK_ERROR) {
		TRY {
			proc_off_p_pid = parse_and_eval_address(
			    "&((struct proc *)0)->p_pid");
			proc_off_p_comm = parse_and_eval_address(
			    "&((struct proc *)0)->p_comm");
			proc_off_p_list = parse_and_eval_address(
			    "&((struct proc *)0)->p_list");
			proc_off_p_threads = parse_and_eval_address(
			    "&((struct proc *)0)->p_threads");
			thread_off_td_tid = parse_and_eval_address(
			    "&((struct thread *)0)->td_tid");
			thread_off_td_name = parse_and_eval_address(
			    "&((struct thread *)0)->td_name");
			thread_off_td_oncpu = parse_and_eval_address(
			    "&((struct thread *)0)->td_oncpu");
			thread_off_td_pcb = parse_and_eval_address(
			    "&((struct thread *)0)->td_pcb");
			thread_off_td_plist = parse_and_eval_address(
			    "&((struct thread *)0)->td_plist");
			thread_oncpu_size = parse_and_eval_long(
			    "sizeof(((struct thread *)0)->td_oncpu)");
		} CATCH(e, RETURN_MASK_ERROR) {
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
		} END_CATCH
	} END_CATCH

	kgdb_thr_add_procs(paddr, cpu_pcb_addr);
	addr = kgdb_lookup("zombproc");
	if (addr != 0) {
		TRY {
			paddr = read_memory_typed_address (addr, ptr_type);
			kgdb_thr_add_procs(paddr, cpu_pcb_addr);
		} CATCH(e, RETURN_MASK_ERROR) {
		} END_CATCH
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

char *
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
	TRY {
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
	} CATCH(e, RETURN_MASK_ERROR) {
	} END_CATCH
	return (buf);
}
