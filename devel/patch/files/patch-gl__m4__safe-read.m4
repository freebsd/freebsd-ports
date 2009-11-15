--- ./gl/m4/safe-read.m4.orig	2009-11-15 15:34:14.000000000 -0500
+++ ./gl/m4/safe-read.m4	2009-11-15 15:37:34.000000000 -0500
@@ -0,0 +1,18 @@
+# safe-read.m4 serial 5
+dnl Copyright (C) 2002, 2003, 2005, 2006 Free Software Foundation, Inc.
+dnl This file is free software; the Free Software Foundation
+dnl gives unlimited permission to copy and/or distribute it,
+dnl with or without modifications, as long as this notice is preserved.
+
+AC_DEFUN([gl_SAFE_READ],
+[
+  AC_LIBOBJ([safe-read])
+
+  gl_PREREQ_SAFE_READ
+])
+
+# Prerequisites of lib/safe-read.c.
+AC_DEFUN([gl_PREREQ_SAFE_READ],
+[
+  AC_REQUIRE([gt_TYPE_SSIZE_T])
+])
