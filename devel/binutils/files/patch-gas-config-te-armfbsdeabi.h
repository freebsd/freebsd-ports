--- gas/config/te-armfbsdeabi.h.orig	1970-01-01 00:14:12.000000000 +0000
+++ gas/config/te-armfbsdeabi.h	1970-01-01 00:14:37.000000000 +0000
@@ -0,0 +1,22 @@
+/* Copyright (C) 2004-2014 Free Software Foundation, Inc.
+
+   This file is part of GAS, the GNU Assembler.
+
+   GAS is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as
+   published by the Free Software Foundation; either version 3,
+   or (at your option) any later version.
+
+   GAS is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
+   the GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with GAS; see the file COPYING.  If not, write to the Free
+   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
+   02110-1301, USA.  */
+
+#include "te-freebsd.h"
+
+#define EABI_DEFAULT EF_ARM_EABI_VER5
