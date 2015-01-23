--- src/1os/os_posix.cc.orig	2015-01-23 22:50:40.837448364 +0800
+++ src/1os/os_posix.cc	2015-01-23 22:51:34.327606541 +0800
@@ -277,7 +277,7 @@
     throw Exception(HAM_IO_ERROR);
 }
 
-uint64_t
+size_t
 File::tell()
 {
   uint64_t offset = lseek(m_fd, 0, SEEK_CUR);
@@ -287,7 +287,7 @@
   return (offset);
 }
 
-uint64_t
+size_t
 File::get_file_size()
 {
   seek(0, kSeekEnd);
