/* Kernel core dump functions below target vector, for GDB on FreeBSD/Alpha.
   Copyright 1986, 1987, 1989, 1991, 1992, 1993, 1994, 1995
   Free Software Foundation, Inc.

This file is part of GDB.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

__FBSDID("$FreeBSD$");

#include "alpha/tm-alpha.h"
#include "alpha-tdep.h"

#ifndef S0_REGNUM
#define S0_REGNUM (ALPHA_T7_REGNUM+1)
#endif

static void
fetch_kcore_registers (struct pcb *pcbp)
{

  /* First clear out any garbage.  */
  memset (deprecated_registers, '\0', DEPRECATED_REGISTER_BYTES);

  /* SP */
  *(long *) &deprecated_registers[DEPRECATED_REGISTER_BYTE (SP_REGNUM)] =
    pcbp->pcb_hw.apcb_ksp;

  /* S0 through S6 */
  memcpy (&deprecated_registers[DEPRECATED_REGISTER_BYTE (S0_REGNUM)],
          &pcbp->pcb_context[0], 7 * sizeof (long));

  /* PC */
  *(long *) &deprecated_registers[DEPRECATED_REGISTER_BYTE (PC_REGNUM)] =
    pcbp->pcb_context[7];

  deprecated_registers_fetched ();
}


#if __FreeBSD_version >= 500032
CORE_ADDR
fbsd_kern_frame_saved_pc (struct frame_info *fi)
{
  struct minimal_symbol *sym;
  CORE_ADDR this_saved_pc;

  this_saved_pc = DEPRECATED_FRAME_SAVED_PC(fi);

  sym = lookup_minimal_symbol_by_pc (this_saved_pc);

  if (sym != NULL &&
      (strcmp (DEPRECATED_SYMBOL_NAME (sym), "XentArith") == 0 ||
       strcmp (DEPRECATED_SYMBOL_NAME (sym), "XentIF") == 0 ||
       strcmp (DEPRECATED_SYMBOL_NAME (sym), "XentInt") == 0 ||
       strcmp (DEPRECATED_SYMBOL_NAME (sym), "XentMM") == 0 ||
       strcmp (DEPRECATED_SYMBOL_NAME (sym), "XentSys") == 0 ||
       strcmp (DEPRECATED_SYMBOL_NAME (sym), "XentUna") == 0 ||
       strcmp (DEPRECATED_SYMBOL_NAME (sym), "XentRestart") == 0))
    {
      return (read_memory_integer (get_frame_base (fi) + 32 * 8, 8));
    }
  else
    {
      return (this_saved_pc);
    }
}
#endif	// __FreeBSD_version >= 500032
