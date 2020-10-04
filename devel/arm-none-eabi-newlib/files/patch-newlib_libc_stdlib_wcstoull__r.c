--- newlib/libc/stdlib/wcstoull_r.c.orig	2020-10-04 20:42:50 UTC
+++ newlib/libc/stdlib/wcstoull_r.c
@@ -43,6 +43,7 @@
 #ifdef __GNUC__
 
 #define _GNU_SOURCE
+#define __LONG_LONG_SUPPORTED
 #include <_ansi.h>
 #include <limits.h>
 #include <wchar.h>
