--- ../pr/src/io/prprf.c	Thu Jan 23 09:03:22 2003
+++ ../pr/src/io/prprf.c	Thu Oct 16 23:14:36 2003
@@ -52,5 +52,8 @@
 ** and requires array notation.
 */
-#if (defined(LINUX) && defined(__powerpc__)) || \
+#if defined(__amd64__)
+#include <stdarg.h>
+#define VARARGS_ASSIGN(foo, bar) va_copy((foo), (bar))
+#elif (defined(LINUX) && defined(__powerpc__)) || \
     (defined(LINUX) && defined(__s390__)) || \
     (defined(LINUX) && defined(__s390x__)) || \
