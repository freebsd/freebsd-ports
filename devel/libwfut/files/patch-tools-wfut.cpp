--- tools/wfut.cpp.orig	2011-01-08 14:51:24 UTC
+++ tools/wfut.cpp
@@ -7,6 +7,8 @@
 #endif
 
 #include <getopt.h>
+#include <stdlib.h>
+#include <unistd.h>
 
 #include <dirent.h>
 #include <sys/stat.h>
