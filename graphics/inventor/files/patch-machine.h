--- lib/database/include/machine.h.orig	2003-07-12 00:40:53.000000000 +0200
+++ lib/database/include/machine.h	2011-06-08 14:30:26.000000000 +0200
@@ -143,7 +143,7 @@
  * Linux i386/ia64 machine dependent setup
  */
 
-#if __i386__ || __ia64__
+#if __i386__ || __ia64__ || __amd64__
 
 #define MACHINE_WORD_FORMAT	DGL_LITTLE_ENDIAN
 #define MACHINE_FLOAT_FORMAT	DGL_NON_IEEE
@@ -152,6 +152,18 @@
 
 
 /*
+ * Alpha under FreeBSD
+ */
+
+#if __alpha__ && __FreeBSD__
+
+#define MACHINE_WORD_FORMAT	DGL_LITTLE_ENDIAN
+#define MACHINE_FLOAT_FORMAT	DGL_NON_IEEE
+
+#endif /* __alpha__ && __FreeBSD__ */
+
+
+/*
  * Apple Darwin (Mac OS X) machine dependent setup
  */
 
@@ -321,7 +333,7 @@
  */
 
 #if MACHINE_FLOAT_FORMAT == DGL_NON_IEEE
-#if __i386__ || __ia64__
+#if __i386__ || __ia64__ || __amd64__
 void mem_hton_float(float *t, float *f);
 void mem_ntoh_float(float *t, float *f);
 void mem_hton_double(double *t, double *f);
