--- liboil/dct/dct.h.orig	Sat Nov 13 11:34:25 2004
+++ liboil/dct/dct.h	Sat Nov 13 11:34:55 2004
@@ -21,6 +21,10 @@
 
 #include <liboil/liboilfunction.h>
 
+#ifdef __FreeBSD__
+#define M_PI 3.14159265358979323846
+#endif
+
 OIL_DECLARE_CLASS(dct12_f32);
 OIL_DECLARE_CLASS(dct36_f32);
 OIL_DECLARE_CLASS(fdct8_f64);
