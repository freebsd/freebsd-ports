--- kernel/OS/FreeBSD/wrapper/bsddefs.h.orig	2021-10-19 08:38:32.843953000 -0700
+++ kernel/OS/FreeBSD/wrapper/bsddefs.h	2021-10-19 08:41:58.476795000 -0700
@@ -32,7 +32,11 @@
 #endif
 extern int oss_get_uid (void);
 
+#if __FreeBSD_version > 1400009
+typedef struct _device dev_info_t;
+#else
 typedef struct device dev_info_t;
+#endif
 typedef long long oss_int64_t;			/* Signed 64 bit integer */
 typedef unsigned long long oss_uint64_t;	/* Unsigned 64 bit integer */
 typedef unsigned long offset_t;
@@ -93,8 +97,8 @@
 #ifdef _KERNEL
 #ifdef memset
 #undef memset
-#define memset oss_memset
 #endif
+#define memset oss_memset
 extern void *oss_memset (void *t, int val, int l);
 #endif
 
