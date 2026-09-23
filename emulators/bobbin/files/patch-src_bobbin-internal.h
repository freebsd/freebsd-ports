--- src/bobbin-internal.h.orig	2024-07-27 05:20:14 UTC
+++ src/bobbin-internal.h
@@ -11,7 +11,6 @@
 #ifdef _XOPEN_SOURCE
 #undef _XOPEN_SOURCE
 #endif
-#define _XOPEN_SOURCE   700
 
 #include <signal.h>
 #include <stdarg.h>
