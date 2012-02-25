/* Native-dependent code for amd64 BSD's.

   Copyright (C) 2011 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef AMD64BSD_NAT_H
#define AMD64BSD_NAT_H

/* Create a prototype *BSD/amd64 target.  The client can override it
   with local methods.  */

extern struct target_ops *amd64bsd_target (void);

/* low level amd64 debug register functions used in amd64fbsd-nat.c.  */

extern void amd64bsd_dr_set_control (unsigned long control);

extern void amd64bsd_dr_set_addr (int regnum, CORE_ADDR addr);

extern void amd64bsd_dr_reset_addr (int regnum);

extern unsigned long amd64bsd_dr_get_status (void);

#endif /* amd64bsd-nat.h */
