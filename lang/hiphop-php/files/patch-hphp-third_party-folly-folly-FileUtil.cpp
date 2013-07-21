--- hphp/third_party/folly/folly/FileUtil.cpp.orig	2013-07-21 12:17:10.950456554 +0200
+++ hphp/third_party/folly/folly/FileUtil.cpp	2013-07-21 12:17:51.135882548 +0200
@@ -53,10 +53,12 @@
 }
 
 int fdatasyncNoInt(int fd) {
-#ifndef __APPLE__
-  return wrapNoInt(fdatasync, fd);
-#else
+#if defined(__APPLE__)
   return wrapNoInt(fcntl, fd, F_FULLFSYNC);
+#elif defined(__FreeBSD__)
+  return wrapNoInt(fsync, fd);
+#else
+  return wrapNoInt(fdatasync, fd);
 #endif
 }
 
