--- ./zupdate.cc.orig	2014-02-22 09:12:36.000000000 -0300
+++ ./zupdate.cc	2014-02-22 09:12:57.000000000 -0300
@@ -32,6 +32,7 @@
 #include <unistd.h>
 #include <utime.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #if defined(__MSVCRT__) || defined(__OS2__)
 #include <io.h>
 #endif
