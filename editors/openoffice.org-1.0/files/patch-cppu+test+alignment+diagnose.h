--- cppu/test/alignment/diagnose.h.orig	Sat Jul 20 23:54:59 2002
+++ cppu/test/alignment/diagnose.h	Sat Jul 20 23:55:06 2002
@@ -64,7 +64,7 @@
 #include <sal/types.h>
 #include <stdio.h>
 
-#if defined(__GNUC__) && defined(LINUX) && defined(INTEL)
+#if defined(__GNUC__) && (defined(LINUX) || defined(FREEBSD)) && defined(INTEL)
 #define __ALIGNMENT__(s, n) __alignof__ (s)
 #else
 #define __ALIGNMENT__(s, n) n
