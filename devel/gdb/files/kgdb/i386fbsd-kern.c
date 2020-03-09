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
#include "inferior.h"
#include "osabi.h"
#include "regcache.h"
#include "progspace.h"
#include "solib.h"
#include "trad-frame.h"
#include "i386-tdep.h"

#ifdef __i386__
#include <sys/proc.h>
#include <machine/pcb.h>
#include <machine/frame.h>
#include <machine/segments.h>
#include <machine/tss.h>
#endif

#include "kgdb.h"

struct i386fbsd_info {
	int ofs_fix;
};

/* Per-program-space data key.  */
static const struct program_space_data *i386fbsd_pspace_data;

static void
i386fbsd_pspace_data_cleanup (struct program_space *pspace, void *arg)
{
  struct i386fbsd_info *info = (struct i386fbsd_info *)arg;

  xfree (info);
}

/* Get the current i386fbsd data.  If none is found yet, add it now.  This
   function always returns a valid object.  */

static struct i386fbsd_info *
get_i386fbsd_info (void)
{
  struct i386fbsd_info *info;

  info = (struct i386fbsd_info *)
    program_space_data (current_program_space, i386fbsd_pspace_data);
  if (info != NULL)
    return info;

  info = XCNEW (struct i386fbsd_info);
  set_program_space_data (current_program_space, i386fbsd_pspace_data, info);

  /*
   * In revision 1.117 of i386/i386/exception.S trap handlers
   * were changed to pass trapframes by reference rather than
   * by value.  Detect this by seeing if the first instruction
   * at the 'calltrap' label is a "push %esp" which has the
   * opcode 0x54.
   */
  if (parse_and_eval_long("((char *)calltrap)[0]") == 0x54)
    info->ofs_fix = 4;
  else
    info->ofs_fix = 0;
  return info;
}

/*
 * Even though the pcb contains fields for the segment selectors, only
 * %gs is updated on each context switch.  The other selectors are
 * saved in stoppcbs[], but we just hardcode their known values rather
 * than handling that special case.
 */
static const int i386fbsd_pcb_offset[] = {
  -1,				/* %eax */
  -1,				/* %ecx */
  -1,				/* %edx */
  4 * 4,			/* %ebx */
  3 * 4,			/* %esp */
  2 * 4,			/* %ebp */
  1 * 4,			/* %esi */
  0 * 4,			/* %edi */
  5 * 4,			/* %eip */
  -1,				/* %eflags */
  -1,				/* %cs */
  -1,				/* %ss */
  -1,				/* %ds */
  -1,				/* %es */
  -1,				/* %fs */
  -1,				/* %gs */
};

#define	CODE_SEL	(4 << 3)
#define	DATA_SEL	(5 << 3)
#define	PRIV_SEL	(1 << 3)

static void
i386fbsd_supply_pcb(struct regcache *regcache, CORE_ADDR pcb_addr)
{
  gdb_byte buf[4];
  int i;

  memset(buf, 0, sizeof(buf));

  /*
   * XXX The PCB may have been swapped out.  Supply a dummy %eip value
   * so as to avoid triggering an exception during stack unwinding.
   */
  regcache->raw_supply(I386_EIP_REGNUM, buf);
  for (i = 0; i < ARRAY_SIZE (i386fbsd_pcb_offset); i++)
    if (i386fbsd_pcb_offset[i] != -1) {
      if (target_read_memory(pcb_addr + i386fbsd_pcb_offset[i], buf, sizeof buf)
	  != 0)
	continue;
      regcache->raw_supply(i, buf);
    }
  regcache->raw_supply_unsigned(I386_CS_REGNUM, CODE_SEL);
  regcache->raw_supply_unsigned(I386_DS_REGNUM, DATA_SEL);
  regcache->raw_supply_unsigned(I386_ES_REGNUM, DATA_SEL);
  regcache->raw_supply_unsigned(I386_FS_REGNUM, PRIV_SEL);
  regcache->raw_supply_unsigned(I386_GS_REGNUM, DATA_SEL);
  regcache->raw_supply_unsigned(I386_SS_REGNUM, DATA_SEL);
}

#ifdef __i386__
/* TODO: Make this cross-debugger friendly. */
static const int i386fbsd_tss_offset[] = {
  10 * 4,			/* %eax */
  11 * 4,			/* %ecx */
  12 * 4,			/* %edx */
  13 * 4,			/* %ebx */
  14 * 4,			/* %esp */
  15 * 4,			/* %ebp */
  16 * 4,			/* %esi */
  17 * 4,			/* %edi */
  8 * 4,			/* %eip */
  9 * 4,			/* %eflags */
  19 * 4,			/* %cs */
  20 * 4,			/* %ss */
  21 * 4,			/* %ds */
  18 * 4,			/* %es */
  22 * 4,			/* %fs */
  23 * 4,			/* %gs */
};

/*
 * If the current thread is executing on a CPU, fetch the common_tss
 * for that CPU.
 *
 * This is painful because 'struct pcpu' is variant sized, so we can't
 * use it.  Instead, we lookup the GDT selector for this CPU and
 * extract the base of the TSS from there.
 */
static CORE_ADDR
i386fbsd_fetch_tss(void)
{
	struct kthr *kt;
	struct segment_descriptor sd;
	CORE_ADDR addr, cpu0prvpage, tss;

	kt = kgdb_thr_lookup_tid(inferior_ptid.tid());
	if (kt == NULL || kt->cpu == NOCPU || kt->cpu < 0)
		return (0);

	addr = kgdb_lookup("gdt");
	if (addr == 0)
		return (0);
	addr += (kt->cpu * NGDT + GPROC0_SEL) * sizeof(sd);
	if (target_read_memory(addr, (gdb_byte *)&sd, sizeof(sd)) != 0)
		return (0);
	if (sd.sd_type != SDT_SYS386BSY) {
		warning ("descriptor is not a busy TSS");
		return (0);
	}
	tss = sd.sd_hibase << 24 | sd.sd_lobase;

	/*
	 * In SMP kernels, the TSS is stored as part of the per-CPU
	 * data.  On older kernels, the CPU0's private page
	 * is stored at an address that isn't mapped in minidumps.
	 * However, the data is mapped at the alternate cpu0prvpage
	 * address.  Thus, if the TSS is at the invalid address,
	 * change it to be relative to cpu0prvpage instead.
	 */ 
	if (trunc_page(tss) == 0xffc00000) {
		try {
			cpu0prvpage = parse_and_eval_address("cpu0prvpage");
		} catch (const gdb_exception_error &e) {
			return (0);
		}
		tss = cpu0prvpage + (tss & PAGE_MASK);
	}
	return (tss);
}

static struct trad_frame_cache *
i386fbsd_dblfault_cache (struct frame_info *this_frame, void **this_cache)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  struct trad_frame_cache *cache;
  CORE_ADDR addr, func, tss;
  int i;

  if (*this_cache != NULL)
    return (struct trad_frame_cache *)(*this_cache);

  cache = trad_frame_cache_zalloc (this_frame);
  *this_cache = cache;

  func = get_frame_func (this_frame);
  tss = i386fbsd_fetch_tss ();

  for (i = 0; i < ARRAY_SIZE (i386fbsd_tss_offset); i++)
    if (i386fbsd_tss_offset[i] != -1)
      trad_frame_set_reg_addr (cache, i, tss + i386fbsd_tss_offset[i]);

  /* Construct the frame ID using the function start.  */
  /* XXX: Stack address should be dbfault_stack + PAGE_SIZE. */
  trad_frame_set_id (cache, frame_id_build (tss + sizeof(struct i386tss),
					    func));

  return cache;
}

static void
i386fbsd_dblfault_this_id (struct frame_info *this_frame,
			     void **this_cache, struct frame_id *this_id)
{
  struct trad_frame_cache *cache =
    i386fbsd_dblfault_cache (this_frame, this_cache);
  
  trad_frame_get_id (cache, this_id);
}

static struct value *
i386fbsd_dblfault_prev_register (struct frame_info *this_frame,
				   void **this_cache, int regnum)
{
  struct trad_frame_cache *cache =
    i386fbsd_dblfault_cache (this_frame, this_cache);

  return trad_frame_get_register (cache, this_frame, regnum);
}

static int
i386fbsd_dblfault_sniffer (const struct frame_unwind *self,
			     struct frame_info *this_frame,
			     void **this_prologue_cache)
{
  const char *name;

  find_pc_partial_function (get_frame_func (this_frame), &name, NULL, NULL);
  return (name && strcmp (name, "dblfault_handler") == 0);
}

static const struct frame_unwind i386fbsd_dblfault_unwind = {
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  i386fbsd_dblfault_this_id,
  i386fbsd_dblfault_prev_register,
  NULL,
  i386fbsd_dblfault_sniffer
};
#endif

static const int i386fbsd_trapframe_offset[] = {
  10 * 4,			/* %eax */
  9 * 4,			/* %ecx */
  8 * 4,			/* %edx */
  7 * 4,			/* %ebx */
  16 * 4,			/* %esp */
  5 * 4,			/* %ebp */
  4 * 4,			/* %esi */
  3 * 4,			/* %edi */
  13 * 4,			/* %eip */
  15 * 4,			/* %eflags */
  14 * 4,			/* %cs */
  17 * 4,			/* %ss */
  2 * 4,			/* %ds */
  1 * 4,			/* %es */
  0 * 4,			/* %fs */
  -1				/* %gs */
};

#define	TRAPFRAME_SIZE		72

static struct trad_frame_cache *
i386fbsd_trapframe_cache (struct frame_info *this_frame, void **this_cache)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  struct trad_frame_cache *cache;
  struct i386fbsd_info *info;
  CORE_ADDR addr, cs, func, pc, sp;
  const char *name;
  int i;

  if (*this_cache != NULL)
    return ((struct trad_frame_cache *)*this_cache);

  info = get_i386fbsd_info();
  cache = trad_frame_cache_zalloc (this_frame);
  *this_cache = cache;

  func = get_frame_func (this_frame);
  sp = get_frame_register_unsigned (this_frame, I386_ESP_REGNUM);

  find_pc_partial_function (func, &name, NULL, NULL);
  if (strcmp(name, "calltrap") == 0 ||
      strcmp(name, "Xlcall_syscall") == 0 ||
      strcmp(name, "Xint0x80_syscall") == 0)
    /* Traps in later kernels pass the trap frame by reference. */
    sp += info->ofs_fix;
  else if (strcmp(name, "Xtimerint") == 0)
    /* Timer interrupts also pass the trap frame by reference. */
    sp += info->ofs_fix;
  else if (strcmp(name, "Xcpustop") == 0 ||
	   strcmp(name, "Xrendezvous") == 0 ||
	   strcmp(name, "Xipi_intr_bitmap_handler") == 0 ||
	   strcmp(name, "Xlazypmap") == 0)
    /* These handlers push a trap frame only. */
    ;
  else if (strcmp(name, "fork_trampoline") == 0)
    if (get_frame_pc (this_frame) == func)
      {
	/* fork_exit hasn't been called (kthread has never run), so
	   %esp in the pcb points to the word above the trapframe.  */
	sp += 4;
      }
    else
      {
	/* fork_exit has been called, so %esp in fork_exit's
	   frame is &tf - 12.  */
	sp += 12;
      }
  else {
    /* Interrupt frames pass the IDT vector in addition to the trap frame. */
    sp += info->ofs_fix + 4;
  }

  addr = sp + i386fbsd_trapframe_offset[I386_CS_REGNUM];
  cs = read_memory_unsigned_integer (addr, 4, byte_order);
  for (i = 0; i < ARRAY_SIZE (i386fbsd_trapframe_offset); i++)
    {
      /* %ss/%esp are only present in the trapframe for a trap from
          userland.  */
      if ((cs & I386_SEL_RPL) == I386_SEL_KPL)
	{
	  if (i == I386_SS_REGNUM)
	    continue;
	  if (i == I386_ESP_REGNUM)
	    {
	      trad_frame_set_reg_value (cache, i, sp + TRAPFRAME_SIZE - 8);
	      continue;
	    }
	}
      if (i386fbsd_trapframe_offset[i] != -1)
	trad_frame_set_reg_addr (cache, i, sp + i386fbsd_trapframe_offset[i]);
    }

  /* Read %eip from trap frame.  */
  addr = sp + i386fbsd_trapframe_offset[I386_EIP_REGNUM];
  pc = read_memory_unsigned_integer (addr, 4, byte_order);

  if (pc == 0 && strcmp(name, "fork_trampoline") == 0)
    {
      /* Initial frame of a kthread; terminate backtrace.  */
      trad_frame_set_id (cache, outer_frame_id);
    }
  else
    {
      /* Construct the frame ID using the function start.  */
      sp += TRAPFRAME_SIZE;
      if ((cs & I386_SEL_RPL) == I386_SEL_KPL)
	sp -= 8;
      trad_frame_set_id (cache, frame_id_build (sp, func));
    }

  return cache;
}

static void
i386fbsd_trapframe_this_id (struct frame_info *this_frame,
			     void **this_cache, struct frame_id *this_id)
{
  struct trad_frame_cache *cache =
    i386fbsd_trapframe_cache (this_frame, this_cache);
  
  trad_frame_get_id (cache, this_id);
}

static struct value *
i386fbsd_trapframe_prev_register (struct frame_info *this_frame,
				   void **this_cache, int regnum)
{
  struct trad_frame_cache *cache =
    i386fbsd_trapframe_cache (this_frame, this_cache);

  return trad_frame_get_register (cache, this_frame, regnum);
}

static int
i386fbsd_trapframe_sniffer (const struct frame_unwind *self,
			     struct frame_info *this_frame,
			     void **this_prologue_cache)
{
  const char *name;

  find_pc_partial_function (get_frame_func (this_frame), &name, NULL, NULL);
  return (name && ((strcmp (name, "calltrap") == 0)
		   || (strcmp (name, "fork_trampoline") == 0)
		   || (name[0] == 'X' && name[1] != '_')));
}

static const struct frame_unwind i386fbsd_trapframe_unwind = {
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  i386fbsd_trapframe_this_id,
  i386fbsd_trapframe_prev_register,
  NULL,
  i386fbsd_trapframe_sniffer
};

static void
i386fbsd_kernel_init_abi(struct gdbarch_info info, struct gdbarch *gdbarch)
{

	i386_elf_init_abi(info, gdbarch);

#ifdef __i386__
	frame_unwind_prepend_unwinder(gdbarch, &i386fbsd_dblfault_unwind);
#endif
	frame_unwind_prepend_unwinder(gdbarch, &i386fbsd_trapframe_unwind);

	set_solib_ops(gdbarch, &kld_so_ops);

	fbsd_vmcore_set_supply_pcb(gdbarch, i386fbsd_supply_pcb);
	fbsd_vmcore_set_cpu_pcb_addr(gdbarch, kgdb_trgt_stop_pcb);
}

void
_initialize_i386_kgdb_tdep(void)
{
	/* This is used for both i386 and amd64, but amd64 always
	   includes this target, so just include it here.  */
	gdbarch_register_osabi_sniffer(bfd_arch_i386,
				       bfd_target_elf_flavour,
				       fbsd_kernel_osabi_sniffer);
	gdbarch_register_osabi (bfd_arch_i386, 0,
	    GDB_OSABI_FREEBSD_KERNEL, i386fbsd_kernel_init_abi);

	i386fbsd_pspace_data = register_program_space_data_with_cleanup (NULL,
	    i386fbsd_pspace_data_cleanup);

#ifdef __i386__
	/*
	 * FreeBSD/i386 kernels prior to the introduction of AVX
	 * support used a different layout for the PCB.  If gdb is
	 * compiled on these systems, these asserts will fail.  The
	 * package builders build packages on older systems which are
	 * then run on newer systems.  These binaries trip over these
	 * assertions even when debugging user programs and even
	 * though the running kernel is new enough.  To cope, disable
	 * the assertion checks unless gdb is built against a new
	 * enough world.  Note that this means kgdb is not going to
	 * parse PCBs correctly on FreeBSD/i386 kernels before AVX was
	 * merged.
	 */
#if __FreeBSD_version >= 1001505
	gdb_assert(offsetof(struct pcb, pcb_ebx)
		   == i386fbsd_pcb_offset[I386_EBX_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_esp)
		   == i386fbsd_pcb_offset[I386_ESP_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_ebp)
		   == i386fbsd_pcb_offset[I386_EBP_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_esi)
		   == i386fbsd_pcb_offset[I386_ESI_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_edi)
		   == i386fbsd_pcb_offset[I386_EDI_REGNUM]);
	gdb_assert(offsetof(struct pcb, pcb_eip)
		   == i386fbsd_pcb_offset[I386_EIP_REGNUM]);
#endif
	gdb_assert(CODE_SEL == GSEL(GCODE_SEL, SEL_KPL));
	gdb_assert(DATA_SEL == GSEL(GDATA_SEL, SEL_KPL));
	gdb_assert(PRIV_SEL == GSEL(GPRIV_SEL, SEL_KPL));
	gdb_assert(sizeof(struct trapframe) == TRAPFRAME_SIZE);
	gdb_assert(offsetof(struct trapframe, tf_eax)
		   == i386fbsd_trapframe_offset[I386_EAX_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_ecx)
		   == i386fbsd_trapframe_offset[I386_ECX_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_edx)
		   == i386fbsd_trapframe_offset[I386_EDX_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_ebx)
		   == i386fbsd_trapframe_offset[I386_EBX_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_esp)
		   == i386fbsd_trapframe_offset[I386_ESP_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_ebp)
		   == i386fbsd_trapframe_offset[I386_EBP_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_esi)
		   == i386fbsd_trapframe_offset[I386_ESI_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_edi)
		   == i386fbsd_trapframe_offset[I386_EDI_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_eip)
		   == i386fbsd_trapframe_offset[I386_EIP_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_eflags)
		   == i386fbsd_trapframe_offset[I386_EFLAGS_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_cs)
		   == i386fbsd_trapframe_offset[I386_CS_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_ss)
		   == i386fbsd_trapframe_offset[I386_SS_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_ds)
		   == i386fbsd_trapframe_offset[I386_DS_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_es)
		   == i386fbsd_trapframe_offset[I386_ES_REGNUM]);
	gdb_assert(offsetof(struct trapframe, tf_fs)
		   == i386fbsd_trapframe_offset[I386_FS_REGNUM]);

	gdb_assert(offsetof(struct i386tss, tss_eax)
		   == i386fbsd_tss_offset[I386_EAX_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_ecx)
		   == i386fbsd_tss_offset[I386_ECX_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_edx)
		   == i386fbsd_tss_offset[I386_EDX_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_ebx)
		   == i386fbsd_tss_offset[I386_EBX_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_esp)
		   == i386fbsd_tss_offset[I386_ESP_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_ebp)
		   == i386fbsd_tss_offset[I386_EBP_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_esi)
		   == i386fbsd_tss_offset[I386_ESI_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_edi)
		   == i386fbsd_tss_offset[I386_EDI_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_eip)
		   == i386fbsd_tss_offset[I386_EIP_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_eflags)
		   == i386fbsd_tss_offset[I386_EFLAGS_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_cs)
		   == i386fbsd_tss_offset[I386_CS_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_ss)
		   == i386fbsd_tss_offset[I386_SS_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_ds)
		   == i386fbsd_tss_offset[I386_DS_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_es)
		   == i386fbsd_tss_offset[I386_ES_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_fs)
		   == i386fbsd_tss_offset[I386_FS_REGNUM]);
	gdb_assert(offsetof(struct i386tss, tss_gs)
		   == i386fbsd_tss_offset[I386_GS_REGNUM]);
#endif
}
