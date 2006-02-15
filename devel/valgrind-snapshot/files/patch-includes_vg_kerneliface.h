--- include/vg_kerneliface.h.orig	Wed Feb 15 18:39:37 2006
+++ include/vg_kerneliface.h	Wed Feb 15 18:39:03 2006
@@ -177,6 +177,10 @@
 
 #ifdef __FreeBSD__
 
+#ifdef si_band
+#undef si_band
+#endif
+
 typedef
    struct {
       Int si_signo;
