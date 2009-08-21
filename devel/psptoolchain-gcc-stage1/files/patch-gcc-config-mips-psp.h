--- gcc/config/mips/psp.h.orig	1970-01-01 01:00:00.000000000 +0100
+++ gcc/config/mips/psp.h	2006-05-07 13:27:43.000000000 +0100
@@ -0,0 +1,31 @@
+/* Support for Sony's Playstation Portable (PSP).
+   Copyright (C) 2005 Free Software Foundation, Inc.
+   Contributed by Marcus R. Brown <mrbrown@ocgnet.org>
+
+This file is part of GCC.
+
+GCC is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2, or (at your option)
+any later version.
+
+GCC is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with GCC; see the file COPYING.  If not, write to
+the Free Software Foundation, 59 Temple Place - Suite 330,
+Boston, MA 02111-1307, USA.  */
+
+/* Override the startfile spec to include crt0.o. */
+#undef STARTFILE_SPEC
+#define STARTFILE_SPEC "crt0%O%s crti%O%s crtbegin%O%s"
+
+#undef SUBTARGET_CPP_SPEC
+#define SUBTARGET_CPP_SPEC "-DPSP=1 -D__psp__=1 -D_PSP=1"
+
+/* Get rid of the .pdr section. */
+#undef SUBTARGET_ASM_SPEC
+#define SUBTARGET_ASM_SPEC "-mno-pdr"
