--- config.h.orig	Sat Oct 21 20:59:55 1995
+++ config.h	Sun Dec 29 10:50:41 2002
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
