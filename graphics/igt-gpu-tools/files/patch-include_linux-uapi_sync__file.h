--- include/linux-uapi/sync_file.h.orig	2022-08-31 20:00:01 UTC
+++ include/linux-uapi/sync_file.h
@@ -12,8 +12,16 @@
 #ifndef _LINUX_SYNC_H
 #define _LINUX_SYNC_H
 
+#ifdef __linux__
 #include <linux/ioctl.h>
 #include <linux/types.h>
+#elif defined(__FreeBSD__)
+#include <sys/ioctl.h>
+#include <sys/types.h>
+#define	__s32	int32_t
+#define	__u32	uint32_t
+#define	__u64	uint64_t
+#endif
 
 /**
  * struct sync_merge_data - data passed to merge ioctl
