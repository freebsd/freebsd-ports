--- include/vg_kerneliface.h.orig	Fri Jul 16 19:35:22 2004
+++ include/vg_kerneliface.h	Wed Feb 15 18:24:26 2006
@@ -177,6 +177,10 @@
 
 #ifdef __FreeBSD__
 
+#ifdef si_band
+#undef si_band
+#endif
+
 typedef
    struct {
       Int si_signo;
@@ -975,6 +979,8 @@
 	unsigned long long rlim_max;
 } vki_rlimit;
 
+#define VKI_RLIMIT_DATA   2
+#define VKI_RLIMIT_CORE   4
 #define VKI_RLIMIT_NOFILE 8
 #endif
 
