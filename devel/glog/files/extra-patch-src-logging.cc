--- src/logging.cc.orig	2008-10-03 13:32:01.000000000 +0800
+++ src/logging.cc	2008-10-14 13:32:03.000000000 +0800
@@ -1566,7 +1566,7 @@
     } else {
       buf[0] = '\000';
 #if defined(OS_MACOSX) || defined(OS_FREEBSD)
-      if (reinterpret_cast<int>(rc) < sys_nerr) {
+      if (reinterpret_cast<long>(rc) < sys_nerr) {
         // This means an error on MacOSX or FreeBSD.
         return -1;
       }
