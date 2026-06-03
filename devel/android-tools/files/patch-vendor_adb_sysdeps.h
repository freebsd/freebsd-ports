--- vendor/adb/sysdeps.h	2024-08-29 19:46:57.000000000 +0200
+++ vendor/adb/sysdeps.h	2026-03-21 13:49:16.038468000 +0100
@@ -526,7 +526,7 @@
 }
 
 static inline int adb_pread(borrowed_fd fd, void* buf, size_t len, off64_t offset) {
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
     return TEMP_FAILURE_RETRY(pread(fd.get(), buf, len, offset));
 #else
     return TEMP_FAILURE_RETRY(pread64(fd.get(), buf, len, offset));
@@ -548,7 +548,7 @@
 }
 
 static inline int adb_pwrite(int fd, const void* buf, size_t len, off64_t offset) {
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
     return TEMP_FAILURE_RETRY(pwrite(fd, buf, len, offset));
 #else
     return TEMP_FAILURE_RETRY(pwrite64(fd, buf, len, offset));
@@ -563,7 +563,7 @@
 #define pwrite ___xxx_pwrite
 
 static inline int64_t adb_lseek(borrowed_fd fd, int64_t pos, int where) {
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
     return lseek(fd.get(), pos, where);
 #else
     return lseek64(fd.get(), pos, where);
