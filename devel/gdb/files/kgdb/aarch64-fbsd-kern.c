/*-
 * Copyright (c) 2017 John Baldwin <jhb@FreeBSD.org>
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

/* Target-dependent code for FreeBSD/aarch64 kernels.  */

#include "defs.h"

#include "aarch64-tdep.h"
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

struct aarch64fbsd_info
{
  int osreldate;
};

/* Per-program-space data key.  */
static const registry<program_space>::key<aarch64fbsd_info> aarch64fbsd_pspace_data;

static void
aarch64fbsd_pspace_data_cleanup (struct program_space *pspace, void *arg)
{
  struct aarch64fbsd_info *info = (struct aarch64fbsd_info *)arg;

  xfree (info);
}

/* Get the current aarch64_fbsd data.  If none is found yet, add it
   now.  This function always returns a valid object.  */

static struct aarch64fbsd_info *
get_aarch64fbsd_info (void)
{
  struct aarch64fbsd_info *info;

  info = aarch64fbsd_pspace_data.get (current_program_space);
  if (info != nullptr)
    return info;

  info = aarch64fbsd_pspace_data.emplace (current_program_space);

  info->osreldate = parse_and_eval_long ("osreldate");
  return info;
}

static const struct regcache_map_entry aarch64_fbsd_pcbmap[] =
  {
    { 11, AARCH64_X0_REGNUM + 19, 8 }, /* x19 ... x29 */
    { 1, AARCH64_PC_REGNUM, 8 },
    { 1, AARCH64_SP_REGNUM, 8 },
    { 0 }
  };

static const struct regset aarch64_fbsd_pcbregset =
  {
    aarch64_fbsd_pcbmap,
    regcache_supply_regset, regcache_collect_regset
  };

/* In kernels prior to __FreeBSD_version 1400084, struct pcb used an
   alternate layout.  */

static const struct regcache_map_entry aarch64_fbsd13_pcbmap[] =
  {
    { 30, AARCH64_X0_REGNUM, 8 }, /* x0 ... x29 */
    { 1, AARCH64_PC_REGNUM, 8 },
    { 1, REGCACHE_MAP_SKIP, 8 },
    { 1, AARCH64_SP_REGNUM, 8 },
    { 0 }
  };

static const struct regset aarch64_fbsd13_pcbregset =
  {
    aarch64_fbsd13_pcbmap,
    regcache_supply_regset, regcache_collect_regset
  };

static void
aarch64_fbsd_supply_pcb(struct regcache *regcache, CORE_ADDR pcb_addr)
{
  const struct regset *pcbregset;
  struct aarch64fbsd_info *info = get_aarch64fbsd_info();
  gdb_byte buf[8 * 33];

  if (info->osreldate >= 1400084)
    pcbregset = &aarch64_fbsd_pcbregset;
  else
    pcbregset = &aarch64_fbsd13_pcbregset;

  if (target_read_memory (pcb_addr, buf, sizeof buf) == 0)
    regcache_supply_regset (pcbregset, regcache, -1, buf,
			    sizeof (buf));
}

static const struct regcache_map_entry aarch64_fbsd_trapframe_map[] =
  {
    { 1, AARCH64_SP_REGNUM, 8 },
    { 1, AARCH64_LR_REGNUM, 8 },
    { 1, AARCH64_PC_REGNUM, 8 },
    { 1, AARCH64_CPSR_REGNUM, 8 },
    { 1, REGCACHE_MAP_SKIP, 8 },	/* esr */
    { 1, REGCACHE_MAP_SKIP, 8 },	/* far */
    { 30, AARCH64_X0_REGNUM, 8 },	/* x0 ... x29 */
    { 0 },
  };

/* In kernels prior to __FreeBSD_version 1400084, struct trapframe
   used an alternate layout.  */

static const struct regcache_map_entry aarch64_fbsd13_trapframe_map[] =
  {
    { 1, AARCH64_SP_REGNUM, 8 },
    { 1, AARCH64_LR_REGNUM, 8 },
    { 1, AARCH64_PC_REGNUM, 8 },
    { 1, AARCH64_CPSR_REGNUM, 4 },
    { 1, REGCACHE_MAP_SKIP, 4 },	/* esr */
    { 30, AARCH64_X0_REGNUM, 8 },	/* x0 ... x29 */
    { 0 },
  };

static struct trad_frame_cache *
aarch64_fbsd_trapframe_cache (frame_info_ptr this_frame, void **this_cache)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  struct aarch64fbsd_info *info = get_aarch64fbsd_info();
  struct trad_frame_cache *cache;
  CORE_ADDR func, pc, sp;
  const char *name;
  int i, tf_size;

  if (*this_cache != NULL)
    return ((struct trad_frame_cache *)*this_cache);

  const struct regcache_map_entry *trapframe_map;

  if (info->osreldate >= 1400084)
    {
      trapframe_map = aarch64_fbsd_trapframe_map;
    }
  else
    {
      trapframe_map = aarch64_fbsd13_trapframe_map;
    }

  cache = trad_frame_cache_zalloc (this_frame);
  *this_cache = cache;

  func = get_frame_func (this_frame);
  sp = get_frame_register_unsigned (this_frame, AARCH64_SP_REGNUM);

  find_pc_partial_function (func, &name, NULL, NULL);

  tf_size = regcache_map_entry_size (trapframe_map);
  trad_frame_set_reg_regmap (cache, trapframe_map, sp, tf_size);

  /* Read $PC from trap frame.  */
  pc = read_memory_unsigned_integer (sp + 2 * 8, 8, byte_order);

  if (pc == 0 && strcmp(name, "fork_trampoline") == 0)
    {
      /* Initial frame of a kthread; terminate backtrace.  */
      trad_frame_set_id (cache, outer_frame_id);
    }
  else
    {
      /* Construct the frame ID using the function start.  */
      trad_frame_set_id (cache, frame_id_build (sp + tf_size, func));
    }

  return cache;
}

static void
aarch64_fbsd_trapframe_this_id (frame_info_ptr this_frame,
				void **this_cache, struct frame_id *this_id)
{
  struct trad_frame_cache *cache =
    aarch64_fbsd_trapframe_cache (this_frame, this_cache);
  
  trad_frame_get_id (cache, this_id);
}

static struct value *
aarch64_fbsd_trapframe_prev_register (frame_info_ptr this_frame,
				      void **this_cache, int regnum)
{
  struct trad_frame_cache *cache =
    aarch64_fbsd_trapframe_cache (this_frame, this_cache);

  return trad_frame_get_register (cache, this_frame, regnum);
}

static int
aarch64_fbsd_trapframe_sniffer (const struct frame_unwind *self,
				frame_info_ptr this_frame,
				void **this_prologue_cache)
{
  const char *name;

  find_pc_partial_function (get_frame_func (this_frame), &name, NULL, NULL);
  return (name && ((strcmp (name, "handle_el1h_sync") == 0)
		   || (strcmp (name, "handle_el1h_irq") == 0)
		   || (strcmp (name, "handle_el0_sync") == 0)
		   || (strcmp (name, "handle_el0_irq") == 0)
		   || (strcmp (name, "handle_el0_error") == 0)
		   || (strcmp (name, "fork_trampoline") == 0)));
}

static const struct frame_unwind aarch64_fbsd_trapframe_unwind = {
  "aarch64 FreeBSD kernel trap",
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  aarch64_fbsd_trapframe_this_id,
  aarch64_fbsd_trapframe_prev_register,
  NULL,
  aarch64_fbsd_trapframe_sniffer
};

/* Implement the 'init_osabi' method of struct gdb_osabi_handler.  */

static void
aarch64_fbsd_kernel_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  aarch64_gdbarch_tdep *tdep = gdbarch_tdep<aarch64_gdbarch_tdep> (gdbarch);

  frame_unwind_prepend_unwinder (gdbarch, &aarch64_fbsd_trapframe_unwind);

  set_gdbarch_so_ops (gdbarch, &kld_so_ops);

  /* Enable longjmp.  */
  tdep->jb_pc = 13;

  fbsd_vmcore_set_supply_pcb (gdbarch, aarch64_fbsd_supply_pcb);
  fbsd_vmcore_set_cpu_pcb_addr (gdbarch, kgdb_trgt_stop_pcb);
}

void _initialize_aarch64_kgdb_tdep ();
void
_initialize_aarch64_kgdb_tdep ()
{
  gdbarch_register_osabi_sniffer(bfd_arch_aarch64,
				 bfd_target_elf_flavour,
				 fbsd_kernel_osabi_sniffer);
  gdbarch_register_osabi (bfd_arch_aarch64, 0, GDB_OSABI_FREEBSD_KERNEL,
			  aarch64_fbsd_kernel_init_abi);
}
