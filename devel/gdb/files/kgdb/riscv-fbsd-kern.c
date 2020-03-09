/*-
 * Copyright (c) 2018 John Baldwin <jhb@FreeBSD.org>
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
 *
 * $FreeBSD$
 */

/* Target-dependent code for FreeBSD/riscv64 kernels.  */

#include "defs.h"

#include "riscv-tdep.h"
#include "frame-unwind.h"
#include "gdbarch.h"
#include "gdbcore.h"
#include "osabi.h"
#include "regcache.h"
#include "regset.h"
#include "solib.h"
#include "target.h"
#include "trad-frame.h"

#include "kgdb.h"

static const struct regcache_map_entry riscv_fbsd_pcbmap[] =
  {
    { 1, RISCV_RA_REGNUM, 0 },
    { 1, RISCV_SP_REGNUM, 0 },
    { 1, RISCV_GP_REGNUM, 0 },
    { 1, RISCV_TP_REGNUM, 0 },
    { 3, 5, 0 },		/* t0 - t2 */
    { 4, 28, 0 },		/* t3 - t6 */
    { 2, RISCV_FP_REGNUM, 0 },	/* s0 - s1 */
    { 10, 18, 0 },		/* s2 - s11 */
    { 8, RISCV_A0_REGNUM, 0 },	/* a0 - a7 */
    { 0 }
  };

static const struct regset riscv_fbsd_pcbregset =
  {
    riscv_fbsd_pcbmap,
    regcache_supply_regset, regcache_collect_regset
  };

static void
riscv_fbsd_supply_pcb(struct regcache *regcache, CORE_ADDR pcb_addr)
{
  gdb_byte buf[31 * 8];

  /* Always give a value for PC in case the PCB isn't readable. */
  regcache->raw_supply_zeroed (RISCV_PC_REGNUM);
  regcache->raw_supply_zeroed (RISCV_ZERO_REGNUM);
  if (target_read_memory (pcb_addr, buf, sizeof buf) == 0)
    {
      regcache->supply_regset (&riscv_fbsd_pcbregset, -1, buf,
			       sizeof (buf));

      /* Supply the RA as PC as well to simulate the PC as if the
	 thread had just returned. */
      regcache->raw_supply (RISCV_PC_REGNUM, buf);
    }
}

static const struct regcache_map_entry riscv_fbsd_tfmap[] =
  {
    { 1, RISCV_RA_REGNUM, 0 },
    { 1, RISCV_SP_REGNUM, 0 },
    { 1, RISCV_GP_REGNUM, 0 },
    { 1, RISCV_TP_REGNUM, 0 },
    { 3, 5, 0 },		/* t0 - t2 */
    { 4, 28, 0 },		/* t3 - t6 */
    { 2, RISCV_FP_REGNUM, 0 },	/* s0 - s1 */
    { 10, 18, 0 },		/* s2 - s11 */
    { 8, RISCV_A0_REGNUM, 0 },	/* a0 - a7 */
    { 1, RISCV_PC_REGNUM, 0 },
    { 1, RISCV_CSR_SSTATUS_REGNUM, 0 },
    { 1, RISCV_CSR_STVAL_REGNUM, 0 },
    { 1, RISCV_CSR_SCAUSE_REGNUM, 0 },
    { 0 }
  };

static struct trad_frame_cache *
riscv_fbsd_trapframe_cache (struct frame_info *this_frame, void **this_cache)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  struct trad_frame_cache *cache;
  CORE_ADDR func, pc, sp;
  const char *name;
  int xlen;

  if (*this_cache != NULL)
    return ((struct trad_frame_cache *)*this_cache);

  cache = trad_frame_cache_zalloc (this_frame);
  *this_cache = cache;

  sp = get_frame_register_unsigned (this_frame, RISCV_SP_REGNUM);

  xlen = riscv_isa_xlen (gdbarch);
  trad_frame_set_reg_regmap (cache, riscv_fbsd_tfmap, sp, 35 * xlen);

  /* Read $PC from trap frame.  */
  func = get_frame_func (this_frame);
  find_pc_partial_function (func, &name, NULL, NULL);
  pc = read_memory_unsigned_integer (sp + 31 * xlen, xlen, byte_order);

  if (pc == 0 && strcmp(name, "fork_trampoline") == 0)
    {
      /* Initial frame of a kthread; terminate backtrace.  */
      trad_frame_set_id (cache, outer_frame_id);
    }
  else
    {
      /* Construct the frame ID using the function start.  */
      trad_frame_set_id (cache, frame_id_build (sp + 35 * xlen, func));
    }

  return cache;
}

static void
riscv_fbsd_trapframe_this_id (struct frame_info *this_frame,
			     void **this_cache, struct frame_id *this_id)
{
  struct trad_frame_cache *cache =
    riscv_fbsd_trapframe_cache (this_frame, this_cache);
  
  trad_frame_get_id (cache, this_id);
}

static struct value *
riscv_fbsd_trapframe_prev_register (struct frame_info *this_frame,
				   void **this_cache, int regnum)
{
  struct trad_frame_cache *cache =
    riscv_fbsd_trapframe_cache (this_frame, this_cache);

  return trad_frame_get_register (cache, this_frame, regnum);
}

static int
riscv_fbsd_trapframe_sniffer (const struct frame_unwind *self,
				struct frame_info *this_frame,
				void **this_prologue_cache)
{
  const char *name;

  find_pc_partial_function (get_frame_func (this_frame), &name, NULL, NULL);
  return (name != NULL
	  && ((strcmp (name, "cpu_exception_handler_user") == 0) ||
	      (strcmp (name, "cpu_exception_handler_supervisor") == 0)));
}

static const struct frame_unwind riscv_fbsd_trapframe_unwind = {
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  riscv_fbsd_trapframe_this_id,
  riscv_fbsd_trapframe_prev_register,
  NULL,
  riscv_fbsd_trapframe_sniffer
};

/* Implement the 'init_osabi' method of struct gdb_osabi_handler.  */

static void
riscv_fbsd_kernel_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  frame_unwind_prepend_unwinder (gdbarch, &riscv_fbsd_trapframe_unwind);

  set_solib_ops (gdbarch, &kld_so_ops);

  set_gdbarch_software_single_step (gdbarch, riscv_software_single_step);

  fbsd_vmcore_set_supply_pcb (gdbarch, riscv_fbsd_supply_pcb);
  fbsd_vmcore_set_cpu_pcb_addr (gdbarch, kgdb_trgt_stop_pcb);
}

/* Provide a prototype to silence -Wmissing-prototypes.  */
extern initialize_file_ftype _initialize_riscv_kgdb_tdep;

void
_initialize_riscv_kgdb_tdep (void)
{
  gdbarch_register_osabi_sniffer(bfd_arch_riscv,
				 bfd_target_elf_flavour,
				 fbsd_kernel_osabi_sniffer);
  gdbarch_register_osabi (bfd_arch_riscv, 0, GDB_OSABI_FREEBSD_KERNEL,
			  riscv_fbsd_kernel_init_abi);
}
