--- src/ansi-c/library/stdio.c.orig	2026-06-20 15:25:39 UTC
+++ src/ansi-c/library/stdio.c
@@ -6,8 +6,8 @@
 #define __CPROVER_STDIO_H_INCLUDED
 #endif

-/* undefine macros in OpenBSD's stdio.h that are problematic to the checker. */
-#if defined(__OpenBSD__)
+/* undefine macros in FreeBSD's and OpenBSD's stdio.h that are problematic to the checker. */
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
 #undef getchar
 #undef putchar
 #undef getc
