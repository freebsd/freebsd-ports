--- lib/igt_kmod.h.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_kmod.h
@@ -24,7 +24,9 @@
 #ifndef IGT_KMOD_H
 #define IGT_KMOD_H
 
+#ifdef __linux__
 #include <libkmod.h>
+#endif
 
 #include "igt_list.h"
 
