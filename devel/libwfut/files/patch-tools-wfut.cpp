--- tools/wfut.cpp.orig	2013-12-07 12:23:30.000000000 +0100
+++ tools/wfut.cpp	2013-12-07 12:23:32.000000000 +0100
@@ -7,6 +7,8 @@
 #endif
 
 #include <getopt.h>
+#include <stdlib.h>
+#include <unistd.h>
 
 #include <dirent.h>
 #include <sys/stat.h>
