--- Modules/_sre.c	26 Jun 2003 14:41:08 -0000	2.99
+++ Modules/_sre.c	27 Sep 2003 18:13:15 -0000
@@ -71,9 +71,14 @@
    Win64 (MS_WIN64), Linux64 (__LP64__), Monterey (64-bit AIX) (_LP64) */
 /* FIXME: maybe the limit should be 40000 / sizeof(void*) ? */
 #define USE_RECURSION_LIMIT 7500
-#else
 
-#if defined(__GNUC__) && defined(WITH_THREAD) && defined(__FreeBSD__)
+#elif defined(__FreeBSD__)
+/* FreeBSD/amd64 and /sparc64 requires even smaller limit */
+#if defined(__amd64__)
+#define USE_RECURSION_LIMIT 6000
+#elif defined(__sparc64__)
+#define USE_RECURSION_LIMIT 3000
+#elif defined(__GNUC__) && defined(WITH_THREAD)
 /* the pthreads library on FreeBSD has a fixed 1MB stack size for the
  * initial (or "primary") thread, which is insufficient for the default
  * recursion limit.  gcc 3.x at the default optimisation
