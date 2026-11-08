--- third_party/libsync/src/sync.c.orig	2026-04-28 21:06:17 UTC
+++ third_party/libsync/src/sync.c
@@ -18,7 +18,11 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#if __has_include(<malloc.h>)
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 #include <poll.h>
 #include <stdatomic.h>
 #include <stdint.h>
@@ -30,6 +34,10 @@
 
 #include <android/sync.h>
 
+#define __u32 uint32_t
+#define	__s32 int32_t
+#define ETIME ETIMEDOUT
+
 /* Prototypes for deprecated functions that used to be declared in the legacy
  * android/sync.h. They've been moved here to make sure new code does not use
  * them, but the functions are still defined to avoid breaking existing
@@ -153,6 +161,7 @@ static int legacy_sync_merge(const char *name, int fd1
 
 static int legacy_sync_merge(const char *name, int fd1, int fd2)
 {
+#if 0
     struct sync_legacy_merge_data data;
     int ret;
 
@@ -162,10 +171,14 @@ static int legacy_sync_merge(const char *name, int fd1
     if (ret < 0)
         return ret;
     return data.fence;
+#else
+    return 0;
+#endif
 }
 
 static int modern_sync_merge(const char *name, int fd1, int fd2)
 {
+#if 0
     struct sync_merge_data data;
     int ret;
 
@@ -178,10 +191,14 @@ static int modern_sync_merge(const char *name, int fd1
     if (ret < 0)
         return ret;
     return data.fence;
+#else
+    return 0;
+#endif
 }
 
 int sync_merge(const char *name, int fd1, int fd2)
 {
+#if 0
     int uapi;
     int ret;
 
@@ -204,10 +221,14 @@ int sync_merge(const char *name, int fd1, int fd2)
                               memory_order_release);
     }
     return ret;
+#else
+    return 0;
+#endif
 }
 
 static struct sync_fence_info_data *legacy_sync_fence_info(int fd)
 {
+#if 0
     struct sync_fence_info_data *legacy_info;
     struct sync_pt_info *legacy_pt_info;
     int err;
@@ -223,10 +244,14 @@ static struct sync_fence_info_data *legacy_sync_fence_
         return NULL;
     }
     return legacy_info;
+#else
+    return NULL;
+#endif
 }
 
 static struct sync_file_info *modern_sync_file_info(int fd)
 {
+#if 0
     struct sync_file_info local_info;
     struct sync_file_info *info;
     int err;
@@ -251,11 +276,15 @@ static struct sync_file_info *modern_sync_file_info(in
     }
 
     return info;
+#else
+    return NULL;
+#endif
 }
 
 static struct sync_fence_info_data *sync_file_info_to_legacy_fence_info(
     const struct sync_file_info *info)
 {
+#if 0
     struct sync_fence_info_data *legacy_info;
     struct sync_pt_info *legacy_pt_info;
     const struct sync_fence_info *fence_info = sync_get_fence_info(info);
@@ -281,11 +310,15 @@ static struct sync_fence_info_data *sync_file_info_to_
     }
 
     return legacy_info;
+#else
+    return NULL;
+#endif
 }
 
 static struct sync_file_info* legacy_fence_info_to_sync_file_info(
                                     struct sync_fence_info_data *legacy_info)
 {
+#if 0
     struct sync_file_info *info;
     struct sync_pt_info *pt;
     struct sync_fence_info *fence;
@@ -320,10 +353,14 @@ static struct sync_file_info* legacy_fence_info_to_syn
     }
 
     return info;
+#else
+    return NULL;
+#endif
 }
 
 struct sync_fence_info_data *sync_fence_info(int fd)
 {
+#if 0
     struct sync_fence_info_data *legacy_info;
     int uapi;
 
@@ -351,10 +388,14 @@ struct sync_fence_info_data *sync_fence_info(int fd)
     legacy_info = sync_file_info_to_legacy_fence_info(file_info);
     sync_file_info_free(file_info);
     return legacy_info;
+#else
+    return NULL;
+#endif
 }
 
 struct sync_file_info* sync_file_info(int32_t fd)
 {
+#if 0
     struct sync_file_info *info;
     int uapi;
 
@@ -382,11 +423,15 @@ struct sync_file_info* sync_file_info(int32_t fd)
     info = legacy_fence_info_to_sync_file_info(legacy_info);
     sync_fence_info_free(legacy_info);
     return info;
+#else
+    return NULL;
+#endif
 }
 
 struct sync_pt_info *sync_pt_info(struct sync_fence_info_data *info,
                                   struct sync_pt_info *itr)
 {
+#if 0
     if (itr == NULL)
         itr = (struct sync_pt_info *) info->pt_info;
     else
@@ -396,6 +441,9 @@ struct sync_pt_info *sync_pt_info(struct sync_fence_in
         return NULL;
 
     return itr;
+#else
+    return NULL;
+#endif
 }
 
 void sync_fence_info_free(struct sync_fence_info_data *info)
