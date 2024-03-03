--- plugins/builtin/source/content/providers/disk_provider.cpp.orig	2024-02-25 20:54:48 UTC
+++ plugins/builtin/source/content/providers/disk_provider.cpp
@@ -28,7 +28,6 @@
 #elif defined(OS_LINUX)
     #include <fcntl.h>
     #include <unistd.h>
-    #include <linux/fs.h>
     #include <sys/stat.h>
     #include <sys/ioctl.h>
     #include <sys/types.h>
@@ -41,8 +40,11 @@
     #include <sys/disk.h>
 #endif
 
-#if defined(OS_LINUX)
+#if !defined(__FreeBSD__)
 #define lseek lseek64
+#else
+#include <sys/disk.h>
+#define DEFAULT_SECTOR_SIZE 512
 #endif
 
 namespace hex::plugin::builtin {
@@ -77,9 +79,9 @@ namespace hex::plugin::builtin {
     }
 
 #if defined (OS_LINUX)
-    #ifdef BLKSSZGET
+    #ifdef DIOCGSECTORSIZE
         int blkdev_get_sector_size(int fd, int *sector_size) {
-            if (ioctl(fd, BLKSSZGET, sector_size) < 0)
+            if (ioctl(fd, DIOCGSECTORSIZE, sector_size) < 0)
                 return -1;
             return 0;
         }
@@ -91,9 +93,9 @@ namespace hex::plugin::builtin {
         }
     #endif
 
-    #ifdef BLKGETSIZE64
+    #ifdef DIOCGMEDIASIZE
         int blkdev_get_size(int fd, u64 *bytes) {
-            if (ioctl(fd, BLKGETSIZE64, bytes) < 0)
+            if (ioctl(fd, DIOCGMEDIASIZE, bytes) < 0)
                 return -1;
             return 0;
         }
@@ -107,7 +109,7 @@ namespace hex::plugin::builtin {
             if (st.st_size == 0) {
                 // Try BLKGETSIZE
                 unsigned long long bytes64;
-                if (ioctl(fd, BLKGETSIZE, &bytes64) >= 0) {
+                if (ioctl(fd, DIOCGMEDIASIZE, &bytes64) >= 0) {
                     *bytes = bytes64;
                     return 0;
                 }
