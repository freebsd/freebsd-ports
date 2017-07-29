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
 *
 * $FreeBSD$
 */

#ifndef _KGDB_H_
#define	_KGDB_H_

struct kthr {
	struct kthr	*next;
	CORE_ADDR	paddr;
	CORE_ADDR	kaddr;
	CORE_ADDR	pcb;
	int		tid;
	int		pid;
	int		cpu;
};

extern struct kthr *curkthr;
extern struct target_so_ops kld_so_ops;
extern struct target_ops kgdb_trgt_ops;
extern int kgdb_quiet;

CORE_ADDR kgdb_trgt_stop_pcb(u_int);

struct kthr *kgdb_thr_first(void);
struct kthr *kgdb_thr_init(CORE_ADDR (*cpu_pcb_addr) (u_int));
struct kthr *kgdb_thr_lookup_tid(int);
struct kthr *kgdb_thr_lookup_pid(int);
struct kthr *kgdb_thr_lookup_paddr(uintptr_t);
struct kthr *kgdb_thr_lookup_taddr(uintptr_t);
struct kthr *kgdb_thr_next(struct kthr *);
const char  *kgdb_thr_extra_thread_info(int);

enum gdb_osabi fbsd_kernel_osabi_sniffer(bfd *abfd);
void fbsd_vmcore_set_supply_pcb (struct gdbarch *gdbarch,
				 void (*supply_pcb) (struct regcache *,
						     CORE_ADDR));
void fbsd_vmcore_set_cpu_pcb_addr (struct gdbarch *gdbarch,
				   CORE_ADDR (*cpu_pcb_addr) (u_int));

CORE_ADDR kgdb_lookup(const char *sym);

#endif /* _KGDB_H_ */
