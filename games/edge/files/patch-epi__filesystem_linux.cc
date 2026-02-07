--- ./epi/filesystem_linux.cc.orig	Sat Oct 14 05:10:39 2006
+++ ./epi/filesystem_linux.cc	Wed Dec  5 23:19:09 2007
@@ -29,6 +29,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <limits.h>	// for PATH_MAX
 
 #define MAX_MODE_CHARS 3
 
