--- getc_putc.cpp.orig	Sun Dec  9 06:50:24 2001
+++ getc_putc.cpp	Wed Mar  5 14:32:58 2003
@@ -17,6 +17,12 @@
 #include "duration.h"
 #include "getc_putc.h"
 
+#if defined(__alpha__) || defined(__sparc64__) || defined(__amd64__) || defined(__ia64__)
+/* Work around for: line 168, no matching function for call to `min(long unsigned int, unsigned int)' */
+#include <sys/param.h>
+#define min MIN
+#endif
+
 static void usage()
 {
   fprintf(stderr, "usage:\n"
