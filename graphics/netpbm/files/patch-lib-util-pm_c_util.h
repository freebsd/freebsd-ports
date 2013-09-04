--- lib/util/pm_c_util.h.orig	2006-08-19 05:12:28.000000000 +0200
+++ lib/util/pm_c_util.h	2013-08-30 13:58:20.918173431 +0200
@@ -50,6 +50,7 @@
 #ifndef __cplusplus
   #ifndef HAVE_BOOL
     #define HAVE_BOOL 1
+    #undef bool
     typedef int bool;
     #endif
   #ifndef true
