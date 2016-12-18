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

#include <sys/types.h>
#ifdef __sparc64__
#include <machine/asm.h>
#include <machine/pcb.h>
#include <machine/frame.h>
#endif
#include <string.h>

#include <defs.h>
#include "gdbcore.h"
#include "osabi.h"
#include "regcache.h"
#include <target.h>
#include <frame-unwind.h>
#include "solib.h"
#include "trad-frame.h"

#include <sparc-tdep.h>
#include <sparc64-tdep.h>

#include "kgdb.h"

#ifdef __sparc64__
static void
sparc64fbsd_supply_pcb(struct regcache *regcache, CORE_ADDR pcb_addr)
{
	struct pcb pcb;

	if (target_read_memory(pcb_addr, &pcb, sizeof(pcb)) != 0)
		memset(&pcb, 0, sizeof(pcb));

	regcache_raw_supply(regcache, SPARC_SP_REGNUM, (char *)&pcb.pcb_sp);
	sparc_supply_rwindow(regcache, pcb.pcb_sp, -1);
	regcache_raw_supply(regcache, SPARC64_PC_REGNUM, (char *)&pcb.pcb_pc);
	pcb.pcb_pc += 4;
	regcache_raw_supply(regcache, SPARC64_NPC_REGNUM, (char *)&pcb.pcb_pc);
}
#endif

#define	OFF_TF_SP	(14 * 8)
#define	OFF_TF_TPC	(25 * 8)
#define	OFF_TF_TNPC	(24 * 8)
#define	OFF_TF_OUT	(8 * 8)
#define	TRAPFRAME_SIZE	(32 * 8)

#ifdef __sparc64__
_Static_assert(sizeof(struct trapframe) == TRAPFRAME_SIZE, "trapframe size");
_Static_assert(offsetof(struct trapframe, tf_sp) == OFF_TF_SP, "tf_sp offset");
_Static_assert(offsetof(struct trapframe, tf_tpc) == OFF_TF_TPC,
	       "tf_tpc offset");
_Static_assert(offsetof(struct trapframe, tf_tnpc) == OFF_TF_TNPC,
	       "tf_tnpc offset");
_Static_assert(offsetof(struct trapframe, tf_out) == OFF_TF_OUT,
	       "tf_out offset");
#endif

static struct sparc_frame_cache *
sparc64fbsd_trapframe_cache (struct frame_info *this_frame, void **this_cache)
{
  struct sparc_frame_cache *cache;
  CORE_ADDR fp, sp, trapframe_addr;
  int regnum;

  if (*this_cache)
    return (struct sparc_frame_cache *)*this_cache;

  cache = sparc_frame_cache (this_frame, this_cache);
  gdb_assert (cache == *this_cache);

  fp = get_frame_register_unsigned (this_frame, SPARC_FP_REGNUM);
  trapframe_addr = fp + BIAS - TRAPFRAME_SIZE;
  sp = get_frame_register_unsigned (this_frame, SPARC_SP_REGNUM);

  cache->saved_regs = trad_frame_alloc_saved_regs (this_frame);

  cache->saved_regs[SPARC_SP_REGNUM].addr = trapframe_addr + OFF_TF_SP;
#ifdef notyet
  cache->saved_regs[SPARC64_STATE_REGNUM].addr = trapframe_addr + OFF_TF_TSTATE;
#endif
  cache->saved_regs[SPARC64_PC_REGNUM].addr = trapframe_addr + OFF_TF_TPC;
  cache->saved_regs[SPARC64_NPC_REGNUM].addr = trapframe_addr + OFF_TF_TNPC;
  for (regnum = SPARC_O0_REGNUM; regnum <= SPARC_O7_REGNUM; regnum++)
    cache->saved_regs[regnum].addr =
      trapframe_addr + OFF_TF_OUT + (regnum - SPARC_O0_REGNUM) * 8;
  for (regnum = SPARC_L0_REGNUM; regnum <= SPARC_I7_REGNUM; regnum++)
    cache->saved_regs[regnum].addr =
      sp + BIAS + (regnum - SPARC_L0_REGNUM) * 8;

  return cache;
}

static void
sparc64fbsd_trapframe_this_id (struct frame_info *this_frame,
			       void **this_cache, struct frame_id *this_id)
{
  struct sparc_frame_cache *cache =
    sparc64fbsd_trapframe_cache (this_frame, this_cache);

  (*this_id) = frame_id_build (cache->base, cache->pc);
}

static struct value *
sparc64fbsd_trapframe_prev_register (struct frame_info *this_frame,
				     void **this_cache, int regnum)
{
  struct sparc_frame_cache *cache =
    sparc64fbsd_trapframe_cache (this_frame, this_cache);

  return trad_frame_get_prev_register (this_frame, cache->saved_regs, regnum);
}

static int
sparc64fbsd_trapframe_sniffer (const struct frame_unwind *self,
			       struct frame_info *this_frame,
			       void **this_cache)
{
  CORE_ADDR pc;
  const char *name;

  pc = get_frame_address_in_block (this_frame);
  find_pc_partial_function (pc, &name, NULL, NULL);
  if (name && (strcmp(name, "tl0_intr") == 0
	       || strcmp(name, "tl0_trap") == 0
	       || strcmp(name, "tl1_intr") == 0
	       || strcmp(name, "tl1_trap") == 0))
    return 1;

  return 0;
}

static const struct frame_unwind sparc64fbsd_trapframe_unwind =
{
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  sparc64fbsd_trapframe_this_id,
  sparc64fbsd_trapframe_prev_register,
  NULL,
  sparc64fbsd_trapframe_sniffer
};

#if 0
struct kgdb_frame_cache {
	CORE_ADDR	pc;
	CORE_ADDR	sp;
	CORE_ADDR	fp;
};

static struct kgdb_frame_cache *
kgdb_trgt_frame_cache(struct frame_info *next_frame, void **this_cache)
{
	char buf[MAX_REGISTER_SIZE];
	struct kgdb_frame_cache *cache;

	cache = *this_cache;
	if (cache == NULL) {
		cache = FRAME_OBSTACK_ZALLOC(struct kgdb_frame_cache);
		*this_cache = cache;
		cache->pc = frame_func_unwind(next_frame);
		frame_unwind_register(next_frame, SPARC_SP_REGNUM, buf);
		cache->sp = extract_unsigned_integer(buf,
		    register_size(current_gdbarch, SPARC_SP_REGNUM));
		frame_unwind_register(next_frame, SPARC_FP_REGNUM, buf);
		cache->fp = extract_unsigned_integer(buf,
		    register_size(current_gdbarch, SPARC_FP_REGNUM));
		cache->fp += BIAS - sizeof(struct trapframe);
	}
	return (cache);
}

static void
kgdb_trgt_trapframe_this_id(struct frame_info *next_frame, void **this_cache,
    struct frame_id *this_id)
{
	struct kgdb_frame_cache *cache;

	cache = kgdb_trgt_frame_cache(next_frame, this_cache);
	*this_id = frame_id_build(cache->sp, cache->pc);
}

static void
kgdb_trgt_trapframe_prev_register(struct frame_info *next_frame,
    void **this_cache, int regnum, int *optimizedp, enum lval_type *lvalp,
    CORE_ADDR *addrp, int *realnump, void *valuep)
{
	char dummy_valuep[MAX_REGISTER_SIZE];
	struct kgdb_frame_cache *cache;
	int ofs, regsz;

	regsz = register_size(current_gdbarch, regnum);

	if (valuep == NULL)
		valuep = dummy_valuep;
	memset(valuep, 0, regsz);
	*optimizedp = 0;
	*addrp = 0;
	*lvalp = not_lval;
	*realnump = -1;

	cache = kgdb_trgt_frame_cache(next_frame, this_cache);

	switch (regnum) {
	case SPARC_SP_REGNUM:
		ofs = offsetof(struct trapframe, tf_sp);
		break;
	case SPARC64_PC_REGNUM:
		ofs = offsetof(struct trapframe, tf_tpc);
		break;
	case SPARC64_NPC_REGNUM:
		ofs = offsetof(struct trapframe, tf_tnpc);
		break;
	case SPARC_O0_REGNUM:
	case SPARC_O1_REGNUM:
	case SPARC_O2_REGNUM:
	case SPARC_O3_REGNUM:
	case SPARC_O4_REGNUM:
	case SPARC_O5_REGNUM:
	case SPARC_O7_REGNUM:
		ofs = offsetof(struct trapframe, tf_out) +
		    (regnum - SPARC_O0_REGNUM) * 8;
		break;
	default:
		if (regnum >= SPARC_L0_REGNUM && regnum <= SPARC_I7_REGNUM) {
			ofs = (regnum - SPARC_L0_REGNUM) * 8;
			*addrp = cache->sp + BIAS + ofs;
			*lvalp = lval_memory;
			target_read_memory(*addrp, valuep, regsz);
		}
		return;
	}

	*addrp = cache->fp + ofs;
	*lvalp = lval_memory;
	target_read_memory(*addrp, valuep, regsz);
}

static const struct frame_unwind kgdb_trgt_trapframe_unwind = {
        UNKNOWN_FRAME,
        &kgdb_trgt_trapframe_this_id,
        &kgdb_trgt_trapframe_prev_register
};

const struct frame_unwind *
kgdb_trgt_trapframe_sniffer(struct frame_info *next_frame)
{
	char *pname;
	CORE_ADDR pc;

	pc = frame_func_unwind(next_frame);
	pname = NULL;
	find_pc_partial_function(pc, &pname, NULL, NULL);
	if (pname == NULL)
		return (NULL);
	if (strcmp(pname, "tl0_intr") == 0 ||
	    strcmp(pname, "tl0_trap") == 0 ||
	    strcmp(pname, "tl1_intr") == 0 ||
	    strcmp(pname, "tl1_trap") == 0)
		return (&kgdb_trgt_trapframe_unwind);
	/* printf("%s: %lx =%s\n", __func__, pc, pname); */
	return (NULL);
}
#endif

static void
sparc64fbsd_kernel_init_abi(struct gdbarch_info info, struct gdbarch *gdbarch)
{

	sparc64_init_abi(info, gdbarch);

	frame_unwind_prepend_unwinder(gdbarch, &sparc64fbsd_trapframe_unwind);

	set_solib_ops(gdbarch, &kld_so_ops);

#ifdef __sparc64__
	fbsd_vmcore_set_supply_pcb(gdbarch, sparc64fbsd_supply_pcb);
	fbsd_vmcore_set_cpu_pcb_addr(gdbarch, kgdb_trgt_stop_pcb);
#endif
}

void _initialize_sparc64_kgdb_tdep(void);

void
_initialize_sparc64_kgdb_tdep(void)
{
	gdbarch_register_osabi_sniffer(bfd_arch_sparc,
				       bfd_target_elf_flavour,
				       fbsd_kernel_osabi_sniffer);
	gdbarch_register_osabi (bfd_arch_sparc, bfd_mach_sparc_v9,
	    GDB_OSABI_FREEBSD_ELF_KERNEL, sparc64fbsd_kernel_init_abi);
}

