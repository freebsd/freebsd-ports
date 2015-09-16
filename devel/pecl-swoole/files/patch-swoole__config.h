--- swoole_config.h.orig	2015-09-03 15:27:08 UTC
+++ swoole_config.h
@@ -19,7 +19,7 @@
 #ifndef __clang__
 //gcc version check
 #if defined(__GNUC__) && (__GNUC__ < 3 || (__GNUC__ == 4 && __GNUC_MINOR__ < 4))
-#error "GCC 4.4 or later required."
+//#error "GCC 4.4 or later required."
 #endif
 #endif
 
