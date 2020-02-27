/*-
 * Copyright (c) 2006 Marcel Moolenaar
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
#include "frame-unwind.h"
#include "gdbcore.h"
#include "osabi.h"
#include "regcache.h"
#include "solib.h"
#include "symtab.h"
#include "trad-frame.h"
#include "ppc-tdep.h"
#include "ppc64-tdep.h"

#ifdef __powerpc__
#include <machine/pcb.h>
#include <machine/frame.h>
#endif

#include "kgdb.h"

#define	PCB_OFF_R12	0
#define	PCB_OFF_CR	20
#define	PCB_OFF_SP	21
#define	PCB_OFF_TOC	22
#define	PCB_OFF_LR	23

#ifdef __powerpc__
_Static_assert(offsetof(struct pcb, pcb_context)
	       == PCB_OFF_R12 * sizeof(register_t), "r12 offset");
_Static_assert(offsetof(struct pcb, pcb_cr) == PCB_OFF_CR * sizeof(register_t),
	       "cr offset");
_Static_assert(offsetof(struct pcb, pcb_sp) == PCB_OFF_SP * sizeof(register_t),
	       "sp offset");
_Static_assert(offsetof(struct pcb, pcb_toc) == PCB_OFF_TOC * sizeof(register_t),
	       "toc offset");
_Static_assert(offsetof(struct pcb, pcb_lr) == PCB_OFF_LR * sizeof(register_t),
	       "lr offset");
#endif

static void
ppcfbsd_supply_pcb(struct regcache *regcache, CORE_ADDR pcb_addr)
{
  struct gdbarch_tdep *tdep = gdbarch_tdep (regcache->arch ());
  gdb_byte buf[24 * tdep->wordsize];
  int i;

  /* Always give a value for PC in case the PCB isn't readable. */
  regcache->raw_supply_zeroed (PPC_PC_REGNUM);
  if (target_read_memory (pcb_addr, buf, sizeof buf) != 0)
    return;

  /* r12 - r31 */
  for (i = 0; i < 20; i++)
    regcache->raw_supply (tdep->ppc_gp0_regnum + 12 + i,
			  buf + tdep->wordsize * i);

  /* r1 is saved in the sp field */
  regcache->raw_supply (tdep->ppc_gp0_regnum + 1,
			buf + tdep->wordsize * PCB_OFF_SP);

  if (tdep->wordsize == 8)
    /* r2 is saved in the toc field */
    regcache->raw_supply (tdep->ppc_gp0_regnum + 2,
			  buf + tdep->wordsize * PCB_OFF_TOC);

  regcache->raw_supply (tdep->ppc_lr_regnum, buf + tdep->wordsize * PCB_OFF_LR);
  regcache->raw_supply (PPC_PC_REGNUM, buf + tdep->wordsize * PCB_OFF_LR);
  regcache->raw_supply (tdep->ppc_cr_regnum, buf + tdep->wordsize * PCB_OFF_CR);
}

#define	OFF_FIXREG	0
#define	OFF_LR		32
#define	OFF_CR		33
#define	OFF_XER		34
#define	OFF_CTR		35
#define	OFF_SRR0	36
#define	TRAPFRAME_SIZE	42

#ifdef __powerpc__
_Static_assert(sizeof(struct trapframe) == TRAPFRAME_SIZE * sizeof(register_t),
	       "trapframe size");
_Static_assert(offsetof(struct trapframe, fixreg)
	       == OFF_FIXREG * sizeof(register_t), "fixreg offset");
_Static_assert(offsetof(struct trapframe, lr) == OFF_LR * sizeof(register_t),
	       "lr offset");
_Static_assert(offsetof(struct trapframe, cr) == OFF_CR * sizeof(register_t),
	       "cr offset");
_Static_assert(offsetof(struct trapframe, xer) == OFF_XER * sizeof(register_t),
	       "xer offset");
_Static_assert(offsetof(struct trapframe, ctr) == OFF_CTR * sizeof(register_t),
	       "ctr offset");
_Static_assert(offsetof(struct trapframe, srr0)
	       == OFF_SRR0 * sizeof(register_t), "srr0 offset");
#endif

static struct trad_frame_cache *
ppcfbsd_trapframe_cache (struct frame_info *this_frame, void **this_cache)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
  struct trad_frame_cache *cache;
  CORE_ADDR base;
  int i;

  if (*this_cache)
    return (struct trad_frame_cache *)*this_cache;

  cache = trad_frame_cache_zalloc (this_frame);
  *this_cache = cache;

  base = get_frame_register_unsigned (this_frame, gdbarch_sp_regnum (gdbarch));
  if (tdep->wordsize == 8)
    base += 48;
  else
    base += 8;

  for (i = 0; i < ppc_num_gprs; i++)
    trad_frame_set_reg_addr (cache, tdep->ppc_gp0_regnum + i, base
			     + (OFF_FIXREG + i) * tdep->wordsize);
  trad_frame_set_reg_addr (cache, tdep->ppc_lr_regnum, base
			   + OFF_LR * tdep->wordsize);
  trad_frame_set_reg_addr (cache, tdep->ppc_cr_regnum, base
			   + OFF_CR * tdep->wordsize);
  trad_frame_set_reg_addr (cache, tdep->ppc_xer_regnum, base
			   + OFF_XER * tdep->wordsize);
  trad_frame_set_reg_addr (cache, tdep->ppc_ctr_regnum, base
			   + OFF_CTR * tdep->wordsize);
  /* SRR0?  */
  trad_frame_set_reg_addr (cache, gdbarch_pc_regnum (gdbarch), base
			   + OFF_SRR0 * tdep->wordsize);

  /* Construct the frame ID using the function start.  */
  trad_frame_set_id (cache, frame_id_build (base, get_frame_func (this_frame)));

  return cache;
}

static void
ppcfbsd_trapframe_this_id (struct frame_info *this_frame,
			       void **this_cache, struct frame_id *this_id)
{
  struct trad_frame_cache *cache =
    ppcfbsd_trapframe_cache (this_frame, this_cache);

  trad_frame_get_id (cache, this_id);
}

static struct value *
ppcfbsd_trapframe_prev_register (struct frame_info *this_frame,
				     void **this_cache, int regnum)
{
  struct trad_frame_cache *cache =
    ppcfbsd_trapframe_cache (this_frame, this_cache);

  return trad_frame_get_register (cache, this_frame, regnum);
}

static int
ppcfbsd_trapframe_sniffer (const struct frame_unwind *self,
			       struct frame_info *this_frame,
			       void **this_cache)
{
  CORE_ADDR pc;
  const char *name;

  pc = get_frame_func (this_frame);
  find_pc_partial_function (pc, &name, NULL, NULL);
  if (name && (strcmp(name, "trapagain") == 0
	       || strcmp(name, "trapexit") == 0
	       || strcmp(name, "dbtrap") == 0))
    return 1;

  return 0;
}

static const struct frame_unwind ppcfbsd_trapframe_unwind =
{
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  ppcfbsd_trapframe_this_id,
  ppcfbsd_trapframe_prev_register,
  NULL,
  ppcfbsd_trapframe_sniffer
};

static void
ppcfbsd_kernel_init_abi(struct gdbarch_info info, struct gdbarch *gdbarch)
{
  struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);

  frame_unwind_prepend_unwinder(gdbarch, &ppcfbsd_trapframe_unwind);

  set_solib_ops(gdbarch, &kld_so_ops);

  fbsd_vmcore_set_supply_pcb(gdbarch, ppcfbsd_supply_pcb);
  fbsd_vmcore_set_cpu_pcb_addr(gdbarch, kgdb_trgt_stop_pcb);

  /* FreeBSD doesn't support the 128-bit `long double' from the psABI.  */
  set_gdbarch_long_double_bit (gdbarch, 64);
  set_gdbarch_long_double_format (gdbarch, floatformats_ieee_double);

  if (tdep->wordsize == 4)
    {
      set_gdbarch_return_value (gdbarch, ppc_sysv_abi_broken_return_value);
    }

  if (tdep->wordsize == 8)
    {
      set_gdbarch_convert_from_func_ptr_addr
	(gdbarch, ppc64_convert_from_func_ptr_addr);
      set_gdbarch_elf_make_msymbol_special (gdbarch,
					    ppc64_elf_make_msymbol_special);
    }
}

void
_initialize_ppc_kgdb_tdep(void)
{
	gdbarch_register_osabi_sniffer(bfd_arch_powerpc,
				       bfd_target_elf_flavour,
				       fbsd_kernel_osabi_sniffer);
	gdbarch_register_osabi (bfd_arch_powerpc, bfd_mach_ppc,
	    GDB_OSABI_FREEBSD_KERNEL, ppcfbsd_kernel_init_abi);
	gdbarch_register_osabi (bfd_arch_powerpc, bfd_mach_ppc64,
	    GDB_OSABI_FREEBSD_KERNEL, ppcfbsd_kernel_init_abi);

	/* Not sure about this one. */
	gdbarch_register_osabi_sniffer(bfd_arch_rs6000,
				       bfd_target_elf_flavour,
				       fbsd_kernel_osabi_sniffer);
	gdbarch_register_osabi (bfd_arch_rs6000, 0,
	    GDB_OSABI_FREEBSD_KERNEL, ppcfbsd_kernel_init_abi);
}
