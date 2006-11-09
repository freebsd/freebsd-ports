--- src/pcm-cdr.cc.orig	Sun Oct 29 20:50:05 2006
+++ src/pcm-cdr.cc	Sun Oct 29 20:50:43 2006
@@ -12,6 +12,8 @@
 #include <errno.h>
 #include <string.h>
 #include <iostream>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 using std::cerr;
 
