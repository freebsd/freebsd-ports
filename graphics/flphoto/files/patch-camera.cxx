--- camera.cxx.orig	2008-09-15 21:32:33.000000000 +0800
+++ camera.cxx	2008-09-15 21:33:49.000000000 +0800
@@ -42,6 +42,7 @@
 #  define fl_mkdir(p)	mkdir(p)
 #else
 #  include <unistd.h>
+#  include <sys/stat.h>
 #  define fl_mkdir(p)	mkdir(p, 0777)
 #endif // WIN32 && !__CYGWIN__
 #include <errno.h>
