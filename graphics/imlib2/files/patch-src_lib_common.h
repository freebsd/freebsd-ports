--- src/lib/common.h.orig	2010-12-14 19:39:16.000000000 -0800
+++ src/lib/common.h	2010-12-14 19:39:34.000000000 -0800
@@ -16,10 +16,12 @@
 #include <sys/types.h>
 #endif
 
-#if defined(__GNUC__) && (__GNUC__ >= 4)
-#define __hidden __attribute__((visibility("hidden")))
-#else
-#define __hidden
+#ifndef __hidden
+# if defined(__GNUC__) && (__GNUC__ >= 4)
+#  define __hidden __attribute__((visibility("hidden")))
+# else
+#  define __hidden
+# endif
 #endif
 
 #define DATABIG unsigned long long
