--- third_party/libsync/src/sync.c.orig	2023-10-19 19:59:52 UTC
+++ third_party/libsync/src/sync.c
@@ -17,8 +17,8 @@
  */
 
 #include <fcntl.h>
-#include <malloc.h>
 #include <stdint.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <poll.h>
@@ -29,6 +29,12 @@
 
 #include <sync/sync.h>
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+typedef __uint8_t __u8;
+typedef __uint32_t __u32;
+typedef __int32_t __s32;
+#define ETIME ETIMEDOUT
+#endif
 
 struct sw_sync_create_fence_data {
   __u32 value;
