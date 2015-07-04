--- port/port_posix.h.orig	2015-06-11 22:49:11 UTC
+++ port/port_posix.h
@@ -25,12 +25,11 @@
   #else
     #define PLATFORM_IS_LITTLE_ENDIAN false
   #endif
-#elif defined(OS_FREEBSD)
+#elif defined(OS_FREEBSD) || defined(OS_DRAGONFLYBSD)
   #include <sys/endian.h>
   #include <sys/types.h>
   #define PLATFORM_IS_LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
-#elif defined(OS_OPENBSD) || defined(OS_NETBSD) ||\
-      defined(OS_DRAGONFLYBSD) || defined(OS_ANDROID)
+#elif defined(OS_OPENBSD) || defined(OS_NETBSD) || defined(OS_ANDROID)
   #include <sys/types.h>
   #include <sys/endian.h>
 #else
