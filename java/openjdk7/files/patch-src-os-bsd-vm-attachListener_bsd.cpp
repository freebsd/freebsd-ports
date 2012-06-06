$FreeBSD$

--- hotspot/src/os/bsd/vm/attachListener_bsd.cpp.orig	2012-06-05 23:51:31.000000000 -0700
+++ hotspot/src/os/bsd/vm/attachListener_bsd.cpp	2012-06-05 23:54:28.000000000 -0700
@@ -208,7 +208,10 @@
   if (res == 0) {
       RESTARTABLE(::chmod(initial_path, S_IREAD|S_IWRITE), res);
       if (res == 0) {
-          res = ::rename(initial_path, path);
+          RESTARTABLE(::chown(initial_path, geteuid(), getegid()), res);
+          if (res == 0) {
+              res = ::rename(initial_path, path);
+          }
       }
   }
   if (res == -1) {
