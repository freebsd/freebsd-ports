$NetBSD: patch-src_libmojave-external_cutil_fam__pseudo.h,v 1.1 2012/11/16 00:46:04 joerg Exp $

--- src/libmojave-external/cutil/fam_pseudo.h.orig	2012-11-08 22:16:13.000000000 +0000
+++ src/libmojave-external/cutil/fam_pseudo.h
@@ -43,7 +43,10 @@
 /*
  * Maximum file name length.
  */
+#include <limits.h>
+#ifndef NAME_MAX
 #define NAME_MAX                1024
+#endif
 
 /*
  * Possible events.
