--- src/mesa/drivers/dri/sis/sis_context.h.orig	2010-12-14 22:43:15.000000000 +0100
+++ src/mesa/drivers/dri/sis/sis_context.h	2011-07-27 09:58:22.000000000 +0200
@@ -400,10 +400,18 @@
 #define MMIO_READ(reg) *(volatile GLint *)(smesa->IOBase + (reg))
 #define MMIO_READf(reg) *(volatile GLfloat *)(smesa->IOBase + (reg))
 
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__i386__) || defined(__x86_64__) || defined(__amd64__)
 #define MMIO_WMB()	__asm __volatile("" : : : "memory")
 #elif defined(__ia64__)
 #define MMIO_WMB()	__asm __volatile("mf" : : : "memory")
+#elif defined(__powerpc__)
+#define MMIO_WMB()	__asm __volatile("eieio" : : : "memory")
+#elif defined(__sparc64__)
+/*
+ * #StoreStore probably would be sufficient for this driver at the
+ * time of this writing but we use #Sync for safety.
+ */
+#define MMIO_WMB()	__asm __volatile("membar #Sync" : : : "memory")
 #else
 #error platform needs WMB
 #endif
