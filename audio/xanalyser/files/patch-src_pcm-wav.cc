--- src/pcm-wav.cc.orig	Sun Oct 29 20:52:28 2006
+++ src/pcm-wav.cc	Sun Oct 29 20:52:38 2006
@@ -12,6 +12,8 @@
 #include <errno.h>
 #include <string.h>
 #include <iostream>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 using std::cerr;
 
