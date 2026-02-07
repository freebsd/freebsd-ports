--- crengine/src/lvstream/lvfilestream.cpp.orig
+++ crengine/src/lvstream/lvfilestream.cpp
@@ -179,7 +179,7 @@ extern "C" {
 // it is logical to define our own wrapper function 'lseek'.
 static inline lvpos_t cr3_lseek(int fd, lvoffset_t offset, int whence) {
 #if LVLONG_FILE_SUPPORT == 1
-    return (lvpos_t)::lseek64(fd, (off64_t)offset, whence);
+    return (lvpos_t)::lseek(fd, (off64_t)offset, whence);
 #else
     return (lvpos_t)::lseek(fd, (off_t)offset, whence);
 #endif
