--- php_mysqli_structs.h.orig	2010-07-26 15:52:54.000000000 +0200
+++ php_mysqli_structs.h	2010-07-26 15:53:14.000000000 +0200
@@ -54,6 +54,7 @@
 #define WE_HAD_MBSTATE_T
 #endif
 
+#define HAVE_ULONG 1
 #include <my_global.h>
 
 #if !defined(HAVE_MBRLEN) && defined(WE_HAD_MBRLEN)
