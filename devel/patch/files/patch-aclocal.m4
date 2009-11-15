--- ./aclocal.m4.orig	2009-11-03 07:46:26.000000000 -0500
+++ ./aclocal.m4	2009-11-15 15:45:29.000000000 -0500
@@ -1,7 +1,7 @@
-# generated automatically by aclocal 1.11 -*- Autoconf -*-
+# generated automatically by aclocal 1.10.1 -*- Autoconf -*-
 
 # Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
-# 2005, 2006, 2007, 2008, 2009  Free Software Foundation, Inc.
+# 2005, 2006, 2007, 2008  Free Software Foundation, Inc.
 # This file is free software; the Free Software Foundation
 # gives unlimited permission to copy and/or distribute it,
 # with or without modifications, as long as this notice is preserved.
@@ -34,6 +34,8 @@
 m4_include([gl/m4/ssize_t.m4])
 m4_include([gl/m4/stdbool.m4])
 m4_include([gl/m4/strcase.m4])
+m4_include([gl/m4/strndup.m4])
+m4_include([gl/m4/strnlen.m4])
 m4_include([gl/m4/unlocked-io.m4])
 m4_include([gl/m4/utimbuf.m4])
 m4_include([gl/m4/xalloc.m4])
