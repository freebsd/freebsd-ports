--- config.h.orig	1995-10-21 19:59:55 UTC
+++ config.h
@@ -64,6 +64,11 @@
 #define GUS
 #endif /* GUS */
 
+#elif defined(__FreeBSD__)
+#define BIT_32
+#undef NEAR_FAR_PTR
+#define DSP
+
 #elif defined(MSDOS)
 #define NEAR_FAR_PTR
 #define DSP
