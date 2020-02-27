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

/* Target-dependent code for FreeBSD/arm kernels.  */

#include "defs.h"

#include "arm-tdep.h"
#include "frame-unwind.h"
#include "gdbcore.h"
#include "osabi.h"
#include "regcache.h"
#include "regset.h"
#include "solib.h"
#include "target.h"
#include "trad-frame.h"

#include "kgdb.h"

static const struct regcache_map_entry arm_fbsd_pcbmap[] =
  {
    { 9, 4, 4 }, /* r4 ... r12 */
    { 1, ARM_SP_REGNUM, 4 },
    { 1, ARM_LR_REGNUM, 4 },
    { 1, ARM_PC_REGNUM, 4 },
    { 0 }
  };

static const struct regset arm_fbsd_pcbregset =
  {
    arm_fbsd_pcbmap,
    regcache_supply_regset, regcache_collect_regset
  };

static void
arm_fbsd_supply_pcb(struct regcache *regcache, CORE_ADDR pcb_addr)
{
  gdb_byte buf[4 * 12];

  if (target_read_memory (pcb_addr, buf, sizeof buf) == 0)
    regcache->supply_regset (&arm_fbsd_pcbregset, -1, buf, sizeof (buf));

  /*
   * XXX: This is a gross hack, but the ARM frame unwinders need the value
   * of xPSR to determine if Thumb mode is active.  FreeBSD's kernels never
   * use Thumb.
   */
  regcache->raw_supply_unsigned(ARM_PS_REGNUM, 0);
}

static struct trad_frame_cache *
arm_fbsd_trapframe_cache (struct frame_info *this_frame, void **this_cache)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  struct trad_frame_cache *cache;
  CORE_ADDR func, pc, sp;
  const char *name;
  int i;

  if (*this_cache != NULL)
    return ((struct trad_frame_cache *)*this_cache);

  cache = trad_frame_cache_zalloc (this_frame);
  *this_cache = cache;

  func = get_frame_func (this_frame);
  sp = get_frame_register_unsigned (this_frame, ARM_SP_REGNUM);

  find_pc_partial_function (func, &name, NULL, NULL);

  for (i = 0; i <= 12; i++)
    trad_frame_set_reg_addr (cache, ARM_A1_REGNUM + i, sp + 4 + i * 4);
  trad_frame_set_reg_addr (cache, ARM_SP_REGNUM, sp + 14 * 4);
  trad_frame_set_reg_addr (cache, ARM_LR_REGNUM, sp + 15 * 4);
  trad_frame_set_reg_addr (cache, ARM_PC_REGNUM, sp + 18 * 4);
  trad_frame_set_reg_addr (cache, ARM_PS_REGNUM, sp);

  /* Read $PC from trap frame.  */
  pc = read_memory_unsigned_integer (sp + 18 * 4, 4, byte_order);

  if (pc == 0 && strcmp(name, "swi_entry") == 0)
    {
      /* Initial frame of a kthread; terminate backtrace.  */
      trad_frame_set_id (cache, outer_frame_id);
    }
  else
    {
      /* Construct the frame ID using the function start.  */
      trad_frame_set_id (cache, frame_id_build (sp + 4 * 19, func));
    }

  return cache;
}

static void
arm_fbsd_trapframe_this_id (struct frame_info *this_frame,
			     void **this_cache, struct frame_id *this_id)
{
  struct trad_frame_cache *cache =
    arm_fbsd_trapframe_cache (this_frame, this_cache);
  
  trad_frame_get_id (cache, this_id);
}

static struct value *
arm_fbsd_trapframe_prev_register (struct frame_info *this_frame,
				   void **this_cache, int regnum)
{
  struct trad_frame_cache *cache =
    arm_fbsd_trapframe_cache (this_frame, this_cache);

  return trad_frame_get_register (cache, this_frame, regnum);
}

static int
arm_fbsd_trapframe_sniffer (const struct frame_unwind *self,
				struct frame_info *this_frame,
				void **this_prologue_cache)
{
  const char *name;

  find_pc_partial_function (get_frame_func (this_frame), &name, NULL, NULL);
  return (name && ((strcmp (name, "data_abort_entry") == 0)
		   || (strcmp (name, "prefetch_abort_entry") == 0)
		   || (strcmp (name, "undefined_entry") == 0)
		   || (strcmp (name, "exception_exit") == 0)
		   || (strcmp (name, "irq_entry") == 0)
		   || (strcmp (name, "swi_entry") == 0)
		   || (strcmp (name, "swi_exit") == 0)));
}

static const struct frame_unwind arm_fbsd_trapframe_unwind = {
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  arm_fbsd_trapframe_this_id,
  arm_fbsd_trapframe_prev_register,
  NULL,
  arm_fbsd_trapframe_sniffer
};

/* Implement the 'init_osabi' method of struct gdb_osabi_handler.  */

static void
arm_fbsd_kernel_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);

  frame_unwind_prepend_unwinder (gdbarch, &arm_fbsd_trapframe_unwind);

  set_solib_ops (gdbarch, &kld_so_ops);

  tdep->jb_pc = 24;
  tdep->jb_elt_size = 4;

  fbsd_vmcore_set_supply_pcb (gdbarch, arm_fbsd_supply_pcb);
  fbsd_vmcore_set_cpu_pcb_addr (gdbarch, kgdb_trgt_stop_pcb);

  /* Single stepping.  */
  set_gdbarch_software_single_step (gdbarch, arm_software_single_step);
}

/* Provide a prototype to silence -Wmissing-prototypes.  */
extern initialize_file_ftype _initialize_arm_kgdb_tdep;

void
_initialize_arm_kgdb_tdep (void)
{
  gdbarch_register_osabi_sniffer(bfd_arch_arm,
				 bfd_target_elf_flavour,
				 fbsd_kernel_osabi_sniffer);
  gdbarch_register_osabi (bfd_arch_arm, 0, GDB_OSABI_FREEBSD_KERNEL,
			  arm_fbsd_kernel_init_abi);
}
