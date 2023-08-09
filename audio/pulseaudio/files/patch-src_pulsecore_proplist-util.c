--- src/pulsecore/proplist-util.c.orig	2022-06-21 10:54:48 UTC
+++ src/pulsecore/proplist-util.c
@@ -24,6 +24,10 @@
 #include <string.h>
 #include <locale.h>
 
+#ifdef __FreeBSD__
+#include <dlfcn.h>
+#endif
+
 #ifdef ENABLE_NLS
 #include <libintl.h>
 #endif
