--- kernel/OS/FreeBSD/wrapper/bsddefs.h.orig	2019-01-12 19:57:42 UTC
+++ kernel/OS/FreeBSD/wrapper/bsddefs.h
@@ -91,6 +91,9 @@ typedef int ddi_iblock_cookie_t;
 extern void oss_udelay (unsigned long t);
 
 #ifdef _KERNEL
+#ifdef memset
+#undef memset
+#endif
 #define memset oss_memset
 extern void *oss_memset (void *t, int val, int l);
 #endif
