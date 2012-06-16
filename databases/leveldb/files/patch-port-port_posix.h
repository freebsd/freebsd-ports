--- port/port_posix.h.orig	2012-05-31 00:56:59.000000000 +0800
+++ port/port_posix.h	2012-06-15 15:07:41.274868153 +0800
@@ -25,6 +25,11 @@
       defined(OS_DRAGONFLYBSD) || defined(OS_ANDROID)
   #include <sys/types.h>
   #include <sys/endian.h>
+  #ifdef _LITTLE_ENDIAN
+    #define PLATFORM_IS_LITTLE_ENDIAN true
+  #else
+    #define PLATFORM_IS_LITTLE_ENDIAN false
+  #endif
 #else
   #include <endian.h>
 #endif
