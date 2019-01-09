--- kernel/OS/FreeBSD/wrapper/bsddefs.h.orig	2019-01-06 18:38:02 UTC
+++ kernel/OS/FreeBSD/wrapper/bsddefs.h
@@ -91,7 +91,10 @@ typedef int ddi_iblock_cookie_t;
 extern void oss_udelay (unsigned long t);
 
 #ifdef _KERNEL
+#ifdef memset
+#undef memset
 #define memset oss_memset
+#endif
 extern void *oss_memset (void *t, int val, int l);
 #endif
 
