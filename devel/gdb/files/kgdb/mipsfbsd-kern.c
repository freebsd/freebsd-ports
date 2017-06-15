/*
 * Copyright (c) 2007 Juniper Networks, Inc.
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
 *
 * from: src/gnu/usr.bin/gdb/kgdb/trgt_alpha.c,v 1.2.2.1 2005/09/15 05:32:10 marcel
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/types.h>
#ifdef __mips__
#include <machine/asm.h>
#include <machine/pcb.h>
#include <machine/frame.h>
#endif
#include <string.h>

#include <defs.h>
#include <frame-unwind.h>
//#include <target.h>
//#include <gdbthread.h>
//#include <inferior.h>
#include "osabi.h"
#include <regcache.h>
#include "solib.h"
#include "trad-frame.h"
#include <mips-tdep.h>

#include "kgdb.h"

/* Size of struct trapframe in registers. */
#define	TRAPFRAME_WORDS	74

/* From sys/mips/include/pcb.h.  Offsets in the pcb_context[] array. */
#define	FBSD_PCB_REG_S0	0
#define	FBSD_PCB_REG_S1	1
#define	FBSD_PCB_REG_S2	2
#define	FBSD_PCB_REG_S3	3
#define	FBSD_PCB_REG_S4	4
#define	FBSD_PCB_REG_S5	5
#define	FBSD_PCB_REG_S6	6
#define	FBSD_PCB_REG_S7	7
#define	FBSD_PCB_REG_SP	8
#define	FBSD_PCB_REG_S8	9
#define	FBSD_PCB_REG_RA	10
#define	FBSD_PCB_REG_SR	11
#define	FBSD_PCB_REG_GP	12
#define	FBSD_PCB_REG_PC	13

#ifdef __mips__
_Static_assert(TRAPFRAME_WORDS * sizeof(register_t) ==
	       sizeof(struct trapframe), "TRAPFRAME_WORDS mismatch");
_Static_assert(FBSD_PCB_REG_S0 == PCB_REG_S0, "PCB_REG_S0 mismatch");
_Static_assert(FBSD_PCB_REG_S1 == PCB_REG_S1, "PCB_REG_S1 mismatch");
_Static_assert(FBSD_PCB_REG_S2 == PCB_REG_S2, "PCB_REG_S2 mismatch");
_Static_assert(FBSD_PCB_REG_S3 == PCB_REG_S3, "PCB_REG_S3 mismatch");
_Static_assert(FBSD_PCB_REG_S4 == PCB_REG_S4, "PCB_REG_S4 mismatch");
_Static_assert(FBSD_PCB_REG_S5 == PCB_REG_S5, "PCB_REG_S5 mismatch");
_Static_assert(FBSD_PCB_REG_S6 == PCB_REG_S6, "PCB_REG_S6 mismatch");
_Static_assert(FBSD_PCB_REG_S7 == PCB_REG_S7, "PCB_REG_S7 mismatch");
_Static_assert(FBSD_PCB_REG_SP == PCB_REG_SP, "PCB_REG_SP mismatch");
_Static_assert(FBSD_PCB_REG_S8 == PCB_REG_S8, "PCB_REG_S8 mismatch");
_Static_assert(FBSD_PCB_REG_RA == PCB_REG_RA, "PCB_REG_RA mismatch");
_Static_assert(FBSD_PCB_REG_SR == PCB_REG_SR, "PCB_REG_SR mismatch");
_Static_assert(FBSD_PCB_REG_GP == PCB_REG_GP, "PCB_REG_GP mismatch");
_Static_assert(FBSD_PCB_REG_PC == PCB_REG_PC, "PCB_REG_PC mismatch");
#endif

static void
mipsfbsd_supply_pcb(struct regcache *regcache, CORE_ADDR pcb_addr)
{
  struct gdbarch *gdbarch = get_regcache_arch (regcache);
  size_t regsize = mips_isa_regsize (gdbarch);
  gdb_byte buf[regsize * (FBSD_PCB_REG_PC + 1)];

  /* Read the entire pcb_context[] array in one go.  The pcb_context[]
     array is after the pcb_regs member which is a trapframe.  */
  if (target_read_memory (pcb_addr + TRAPFRAME_WORDS * regsize, buf,
			  sizeof(buf)) != 0)
    return;

  regcache_raw_supply_unsigned (regcache, MIPS_ZERO_REGNUM, 0);
  regcache_raw_supply (regcache, MIPS_S2_REGNUM - 2,
		       buf + (regsize * FBSD_PCB_REG_S0));
  regcache_raw_supply (regcache, MIPS_S2_REGNUM - 1,
		       buf + (regsize * FBSD_PCB_REG_S1));
  regcache_raw_supply (regcache, MIPS_S2_REGNUM,
		       buf + (regsize * FBSD_PCB_REG_S2));
  regcache_raw_supply (regcache, MIPS_S2_REGNUM + 1,
		       buf + (regsize * FBSD_PCB_REG_S3));
  regcache_raw_supply (regcache, MIPS_S2_REGNUM + 2,
		       buf + (regsize * FBSD_PCB_REG_S4));
  regcache_raw_supply (regcache, MIPS_S2_REGNUM + 3,
		       buf + (regsize * FBSD_PCB_REG_S5));
  regcache_raw_supply (regcache, MIPS_S2_REGNUM + 4,
		       buf + (regsize * FBSD_PCB_REG_S6));
  regcache_raw_supply (regcache, MIPS_S2_REGNUM + 5,
		       buf + (regsize * FBSD_PCB_REG_S7));
  regcache_raw_supply (regcache, MIPS_SP_REGNUM,
		       buf + (regsize * FBSD_PCB_REG_SP));
  regcache_raw_supply (regcache, MIPS_S2_REGNUM + 6,
		       buf + (regsize * FBSD_PCB_REG_S8));
  regcache_raw_supply (regcache, MIPS_RA_REGNUM,
		       buf + (regsize * FBSD_PCB_REG_RA));
  regcache_raw_supply (regcache, MIPS_PS_REGNUM,
		       buf + (regsize * FBSD_PCB_REG_SR));
  regcache_raw_supply (regcache, MIPS_GP_REGNUM,
		       buf + (regsize * FBSD_PCB_REG_GP));
  regcache_raw_supply (regcache, MIPS_EMBED_PC_REGNUM,
		       buf + (regsize * FBSD_PCB_REG_PC));
}

static struct trad_frame_cache *
mipsfbsd_trapframe_cache (struct frame_info *this_frame, void **this_cache)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  size_t regsize = mips_isa_regsize (gdbarch);
  struct trad_frame_cache *cache;
  CORE_ADDR addr, func, pc, sp;
  int regnum;

  if (*this_cache != NULL)
    return ((struct trad_frame_cache *)*this_cache);

  cache = trad_frame_cache_zalloc (this_frame);
  *this_cache = cache;

  func = get_frame_func (this_frame);
  sp = get_frame_register_signed (this_frame,
				  MIPS_SP_REGNUM + gdbarch_num_regs (gdbarch));

  /* Skip over CALLFRAME_SIZ.  */
  addr = sp;
  if (regsize == 8)
    addr += regsize * 4;
  else
    addr += regsize * (4 + 2);

  /* GPRs.  Skip zero.  */
  addr += regsize;
  for (regnum = MIPS_AT_REGNUM; regnum <= MIPS_RA_REGNUM; regnum++)
    {
      trad_frame_set_reg_addr (cache,
			       regnum + gdbarch_num_regs (gdbarch),
			       addr);
      addr += regsize;
    }

  regnum = MIPS_PS_REGNUM;
  trad_frame_set_reg_addr (cache,
			   regnum + gdbarch_num_regs (gdbarch),
			   addr);
  addr += regsize;

  /* HI and LO.  */
  regnum = mips_regnum (gdbarch)->lo;
  trad_frame_set_reg_addr (cache,
			   regnum + gdbarch_num_regs (gdbarch),
			   addr);
  addr += regsize;
  regnum = mips_regnum (gdbarch)->hi;
  trad_frame_set_reg_addr (cache,
			   regnum + gdbarch_num_regs (gdbarch),
			   addr);
  addr += regsize;

  /* BADVADDR.  */
  regnum = mips_regnum (gdbarch)->badvaddr;
  trad_frame_set_reg_addr (cache,
			   regnum + gdbarch_num_regs (gdbarch),
			   addr);
  addr += regsize;

  /* CAUSE.  */
  regnum = mips_regnum (gdbarch)->cause;
  trad_frame_set_reg_addr (cache,
			   regnum + gdbarch_num_regs (gdbarch),
			   addr);
  addr += regsize;

  /* PC.  */
  regnum = mips_regnum (gdbarch)->pc;
  trad_frame_set_reg_addr (cache,
			   regnum + gdbarch_num_regs (gdbarch),
			   addr);
  
  trad_frame_set_id (cache, frame_id_build (sp + TRAPFRAME_WORDS * regsize,
					    func));
  return cache;
}

static void
mipsfbsd_trapframe_this_id (struct frame_info *this_frame,
			    void **this_cache, struct frame_id *this_id)
{
  struct trad_frame_cache *cache =
    mipsfbsd_trapframe_cache (this_frame, this_cache);
  
  trad_frame_get_id (cache, this_id);
}

static struct value *
mipsfbsd_trapframe_prev_register (struct frame_info *this_frame,
				  void **this_cache, int regnum)
{
  struct trad_frame_cache *cache =
    mipsfbsd_trapframe_cache (this_frame, this_cache);

  return trad_frame_get_register (cache, this_frame, regnum);
}

static int
mipsfbsd_trapframe_sniffer (const struct frame_unwind *self,
			    struct frame_info *this_frame,
			    void **this_prologue_cache)
{
  const char *name;

  find_pc_partial_function (get_frame_func (this_frame), &name, NULL, NULL);
  return (name && ((strcmp(name, "MipsKernIntr") == 0) ||
		   (strcmp(name, "MipsKernGenException") == 0) ||
		   (strcmp(name, "MipsTLBInvalidException") == 0)));
}

static const struct frame_unwind mipsfbsd_trapframe_unwind = {
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  mipsfbsd_trapframe_this_id,
  mipsfbsd_trapframe_prev_register,
  NULL,
  mipsfbsd_trapframe_sniffer
};

static void
mipsfbsd_kernel_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  enum mips_abi abi = mips_abi (gdbarch);

  set_gdbarch_software_single_step (gdbarch, mips_software_single_step);

  switch (abi)
    {
      case MIPS_ABI_O32:
	break;
      case MIPS_ABI_N32:
	set_gdbarch_long_double_bit (gdbarch, 128);
	/* These floatformats should probably be renamed.  MIPS uses
	   the same 128-bit IEEE floating point format that IA-64 uses,
	   except that the quiet/signalling NaN bit is reversed (GDB
	   does not distinguish between quiet and signalling NaNs).  */
	set_gdbarch_long_double_format (gdbarch, floatformats_ia64_quad);
	break;
      case MIPS_ABI_N64:
	set_gdbarch_long_double_bit (gdbarch, 128);
	/* These floatformats should probably be renamed.  MIPS uses
	   the same 128-bit IEEE floating point format that IA-64 uses,
	   except that the quiet/signalling NaN bit is reversed (GDB
	   does not distinguish between quiet and signalling NaNs).  */
	set_gdbarch_long_double_format (gdbarch, floatformats_ia64_quad);
	break;
    }

  frame_unwind_prepend_unwinder (gdbarch, &mipsfbsd_trapframe_unwind);

  set_solib_ops (gdbarch, &kld_so_ops);

  fbsd_vmcore_set_supply_pcb (gdbarch, mipsfbsd_supply_pcb);
  fbsd_vmcore_set_cpu_pcb_addr (gdbarch, kgdb_trgt_stop_pcb);
}

void _initialize_mips_kgdb_tdep (void);

void
_initialize_mips_kgdb_tdep (void)
{
  gdbarch_register_osabi_sniffer(bfd_arch_mips,
				 bfd_target_elf_flavour,
				 fbsd_kernel_osabi_sniffer);
  gdbarch_register_osabi (bfd_arch_mips, 0, GDB_OSABI_FREEBSD_ELF_KERNEL,
			  mipsfbsd_kernel_init_abi);
}
