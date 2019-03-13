--- kernel/OS/FreeBSD/wrapper/bsddefs.h.orig	2019-03-06 07:52:21 UTC
+++ kernel/OS/FreeBSD/wrapper/bsddefs.h
@@ -93,8 +93,8 @@ extern void oss_udelay (unsigned long t);
 #ifdef _KERNEL
 #ifdef memset
 #undef memset
-#define memset oss_memset
 #endif
+#define memset oss_memset
 extern void *oss_memset (void *t, int val, int l);
 #endif
 
