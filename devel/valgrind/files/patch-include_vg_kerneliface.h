--- include/vg_kerneliface.h.orig	Mon Sep 19 21:20:22 2005
+++ include/vg_kerneliface.h	Mon Sep 19 21:22:41 2005
@@ -975,6 +975,8 @@
 	unsigned long long rlim_max;
 } vki_rlimit;
 
+#define VKI_RLIMIT_DATA   2
+#define VKI_RLIMIT_CORE   4
 #define VKI_RLIMIT_NOFILE 8
 #endif
 
