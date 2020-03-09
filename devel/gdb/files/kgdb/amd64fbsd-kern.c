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

#include "defs.h"
#include "frame-unwind.h"
#include "gdbcore.h"
#include "osabi.h"
#include "regcache.h"
#include "solib.h"
#include "stack.h"
#include "symtab.h"
#include "trad-frame.h"
#include "amd64-tdep.h"
#include "gdbsupport/x86-xstate.h"

#ifdef __amd64__
#include <machine/pcb.h>
#include <machine/frame.h>
#endif

#include "kgdb.h"

static const int amd64fbsd_pcb_offset[] = {
  -1,				/* %rax */
  6 * 8,			/* %rbx */
  -1,				/* %rcx */
  -1,				/* %rdx */
  -1,				/* %rsi */
  -1,				/* %rdi */
  4 * 8,			/* %rbp */
  5 * 8,			/* %rsp */
  -1,				/* %r8 ...  */
  -1,
  -1,
  -1,
  3 * 8,
  2 * 8,
  1 * 8,
  0 * 8,			/* ... %r15 */
  7 * 8,			/* %rip */
  -1,				/* %eflags */
  -1,				/* %cs */
  -1,				/* %ss */
  -1,				/* %ds */
  -1,				/* %es */
  -1,				/* %fs */
  -1				/* %gs */
};

#define	CODE_SEL	(4 << 3)
#define	DATA_SEL	(5 << 3)

static void
amd64fbsd_supply_pcb(struct regcache *regcache, CORE_ADDR pcb_addr)
{
  gdb_byte buf[8];
  int i;

  memset(buf, 0, sizeof(buf));

  /*
   * XXX The PCB may have been swapped out.  Supply a dummy %rip value
   * so as to avoid triggering an exception during stack unwinding.
   */
  regcache->raw_supply(AMD64_RIP_REGNUM, buf);
  for (i = 0; i < ARRAY_SIZE (amd64fbsd_pcb_offset); i++)
    if (amd64fbsd_pcb_offset[i] != -1) {
      if (target_read_memory(pcb_addr + amd64fbsd_pcb_offset[i], buf,
			     sizeof buf) != 0)
	continue;
      regcache->raw_supply(i, buf);
    }

  regcache->raw_supply_unsigned(AMD64_CS_REGNUM, CODE_SEL);
  regcache->raw_supply_unsigned(AMD64_SS_REGNUM, DATA_SEL);
}

static const int amd64fbsd_trapframe_offset[] = {
  6 * 8,			/* %rax */
  7 * 8,			/* %rbx */
  3 * 8,			/* %rcx */
  2 * 8,			/* %rdx */
  1 * 8,			/* %rsi */
  0 * 8,			/* %rdi */
  8 * 8,			/* %rbp */
  22 * 8,			/* %rsp */
  4 * 8,			/* %r8 ...  */
  5 * 8,
  9 * 8,
  10 * 8,
  11 * 8,
  12 * 8,
  13 * 8,
  14 * 8,			/* ... %r15 */
  19 * 8,			/* %rip */
  21 * 8,			/* %eflags */
  20 * 8,			/* %cs */
  23 * 8,			/* %ss */
  -1,				/* %ds */
  -1,				/* %es */
  -1,				/* %fs */
  -1				/* %gs */
};

#define TRAPFRAME_SIZE	192

static struct trad_frame_cache *
amd64fbsd_trapframe_cache (struct frame_info *this_frame, void **this_cache)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  struct trad_frame_cache *cache;
  CORE_ADDR addr, func, pc, sp;
  const char *name;
  int i;

  if (*this_cache != NULL)
    return ((struct trad_frame_cache *)*this_cache);

  cache = trad_frame_cache_zalloc (this_frame);
  *this_cache = cache;

  func = get_frame_func (this_frame);
  sp = get_frame_register_unsigned (this_frame, AMD64_RSP_REGNUM);

  find_pc_partial_function (func, &name, NULL, NULL);
  if (strcmp(name, "fork_trampoline") == 0 && get_frame_pc (this_frame) == func)
    {
      /* fork_exit hasn't been called (kthread has never run), so %rsp
	 in the pcb points to the trapframe.  GDB has auto-adjusted
	 %rsp for this frame to account for the "call" into
	 fork_trampoline, so "undo" the adjustment.  */
      sp += 8;
    }
  
  for (i = 0; i < ARRAY_SIZE (amd64fbsd_trapframe_offset); i++)
    if (amd64fbsd_trapframe_offset[i] != -1)
      trad_frame_set_reg_addr (cache, i, sp + amd64fbsd_trapframe_offset[i]);

  /* Read %rip from trap frame.  */
  addr = sp + amd64fbsd_trapframe_offset[AMD64_RIP_REGNUM];
  pc = read_memory_unsigned_integer (addr, 8, byte_order);

  if (pc == 0 && strcmp(name, "fork_trampoline") == 0)
    {
      /* Initial frame of a kthread; terminate backtrace.  */
      trad_frame_set_id (cache, outer_frame_id);
    }
  else
    {
      /* Construct the frame ID using the function start.  */
      trad_frame_set_id (cache, frame_id_build (sp + TRAPFRAME_SIZE, func));
    }

  return cache;
}

static void
amd64fbsd_trapframe_this_id (struct frame_info *this_frame,
			     void **this_cache, struct frame_id *this_id)
{
  struct trad_frame_cache *cache =
    amd64fbsd_trapframe_cache (this_frame, this_cache);
  
  trad_frame_get_id (cache, this_id);
}

static struct value *
amd64fbsd_trapframe_prev_register (struct frame_info *this_frame,
				   void **this_cache, int regnum)
{
  struct trad_frame_cache *cache =
    amd64fbsd_trapframe_cache (this_frame, this_cache);

  return trad_frame_get_register (cache, this_frame, regnum);
}

static int
amd64fbsd_trapframe_sniffer (const struct frame_unwind *self,
			     struct frame_info *this_frame,
			     void **this_prologue_cache)
{
  const char *name;

  find_pc_partial_function (get_frame_func (this_frame), &name, NULL, NULL);
  return (name && ((strcmp (name, "calltrap") == 0)
		   || (strcmp (name, "fast_syscall_common") == 0)
		   || (strcmp (name, "fork_trampoline") == 0)
		   || (strcmp (name, "mchk_calltrap") == 0)
		   || (strcmp (name, "nmi_calltrap") == 0)
		   || (name[0] == 'X' && name[1] != '_')));
}

static const struct frame_unwind amd64fbsd_trapframe_unwind = {
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  amd64fbsd_trapframe_this_id,
  amd64fbsd_trapframe_prev_register,
  NULL,
  amd64fbsd_trapframe_sniffer
};

static void
amd64fbsd_kernel_init_abi(struct gdbarch_info info, struct gdbarch *gdbarch)
{

	amd64_init_abi(info, gdbarch,
		       amd64_target_description (X86_XSTATE_SSE_MASK, true));

	frame_unwind_prepend_unwinder(gdbarch, &amd64fbsd_trapframe_unwind);

	set_solib_ops(gdbarch, &kld_so_ops);

	fbsd_vmcore_set_supply_pcb(gdbarch, amd64fbsd_supply_pcb);
	fbsd_vmcore_set_cpu_pcb_addr(gdbarch, kgdb_trgt_stop_pcb);
}

void
_initialize_amd64_kgdb_tdep(void)
{
	gdbarch_register_osabi (bfd_arch_i386, bfd_mach_x86_64,
	    GDB_OSABI_FREEBSD_KERNEL, amd64fbsd_kernel_init_abi);

#ifdef __amd64__
	gdb_assert(offsetof(struct pcb, pcb_rbx)
		   == amd64fbsd_pcb_offset[AMD64_RBX_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_rbp)
		   == amd64fbsd_pcb_offset[AMD64_RBP_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_rsp)
		   == amd64fbsd_pcb_offset[AMD64_RSP_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_r12)
		   == amd64fbsd_pcb_offset[AMD64_R12_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_r13)
		   == amd64fbsd_pcb_offset[AMD64_R13_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_r14)
		   == amd64fbsd_pcb_offset[AMD64_R14_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_r15)
		   == amd64fbsd_pcb_offset[AMD64_R15_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_rip)
		   == amd64fbsd_pcb_offset[AMD64_RIP_REGNUM]);
	gdb_assert(CODE_SEL == GSEL(GCODE_SEL, SEL_KPL));
	gdb_assert(DATA_SEL == GSEL(GDATA_SEL, SEL_KPL));
	gdb_assert(sizeof(struct trapframe) == TRAPFRAME_SIZE);
	gdb_assert(offsetof(struct trapframe, tf_rax)
		   == amd64fbsd_trapframe_offset[AMD64_RAX_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rbx)
		   == amd64fbsd_trapframe_offset[AMD64_RBX_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rcx)
		   == amd64fbsd_trapframe_offset[AMD64_RCX_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rdx)
		   == amd64fbsd_trapframe_offset[AMD64_RDX_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rsi)
		   == amd64fbsd_trapframe_offset[AMD64_RSI_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rdi)
		   == amd64fbsd_trapframe_offset[AMD64_RDI_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rbp)
		   == amd64fbsd_trapframe_offset[AMD64_RBP_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rsp)
		   == amd64fbsd_trapframe_offset[AMD64_RSP_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_r8)
		   == amd64fbsd_trapframe_offset[AMD64_R8_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_r9)
		   == amd64fbsd_trapframe_offset[AMD64_R9_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_r10)
		   == amd64fbsd_trapframe_offset[AMD64_R10_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_r11)
		   == amd64fbsd_trapframe_offset[AMD64_R11_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_r12)
		   == amd64fbsd_trapframe_offset[AMD64_R12_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_r13)
		   == amd64fbsd_trapframe_offset[AMD64_R13_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_r14)
		   == amd64fbsd_trapframe_offset[AMD64_R14_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_r15)
		   == amd64fbsd_trapframe_offset[AMD64_R15_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rip)
		   == amd64fbsd_trapframe_offset[AMD64_RIP_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_rflags)
		   == amd64fbsd_trapframe_offset[AMD64_EFLAGS_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_cs)
		   == amd64fbsd_trapframe_offset[AMD64_CS_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_ss)
		   == amd64fbsd_trapframe_offset[AMD64_SS_REGNUM]);
#endif
}
