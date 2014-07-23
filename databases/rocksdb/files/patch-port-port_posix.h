--- port/port_posix.h.orig	2014-06-20 07:40:32.000000000 +0800
+++ port/port_posix.h	2014-07-22 22:10:43.906820844 +0800
@@ -26,10 +26,22 @@
   #else
     #define PLATFORM_IS_LITTLE_ENDIAN false
   #endif
-#elif defined(OS_FREEBSD) || defined(OS_OPENBSD) || defined(OS_NETBSD) ||\
-      defined(OS_DRAGONFLYBSD) || defined(OS_ANDROID)
+#elif defined(OS_FREEBSD)
   #include <sys/types.h>
   #include <sys/endian.h>
+  #define PLATFORM_IS_LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#elif defined(OS_OPENBSD) || defined(OS_NETBSD) ||\
+      defined(OS_DRAGONFLYBSD)
+  #include <sys/types.h>
+  #include <sys/endian.h>
+#elif defined(OS_HPUX)
+  #define PLATFORM_IS_LITTLE_ENDIAN false
+#elif defined(OS_ANDROID)
+  // Due to a bug in the NDK x86 <sys/endian.h> definition,
+  // _BYTE_ORDER must be used instead of __BYTE_ORDER on Android.
+  // See http://code.google.com/p/android/issues/detail?id=39824
+  #include <endian.h>
+  #define PLATFORM_IS_LITTLE_ENDIAN  (_BYTE_ORDER == _LITTLE_ENDIAN)
 #else
   #include <endian.h>
 #endif
