$NetBSD: patch-lib_sqlite3_stubs.c,v 1.1 2012/09/16 11:34:46 jaapb Exp $

Correct system-dependent defines
--- lib/sqlite3_stubs.c.orig	2012-07-20 15:39:49.000000000 +0000
+++ lib/sqlite3_stubs.c
@@ -40,7 +40,7 @@
 
 #if __GNUC__ >= 3
 # define inline inline __attribute__ ((always_inline))
-# if !defined(__FreeBSD__) && !__APPLE__
+# if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly) && !__APPLE__
 # define __unused __attribute__ ((unused))
 # endif
 #else
