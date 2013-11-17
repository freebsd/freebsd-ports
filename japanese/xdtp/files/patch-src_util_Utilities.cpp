--- src/util/Utilities.cpp.orig	2013-10-06 03:57:39.000000000 +0900
+++ src/util/Utilities.cpp	2013-10-06 03:57:55.000000000 +0900
@@ -37,7 +37,9 @@
 
 #include <stdio.h>
 #include <fcntl.h>
+#include <unistd.h>
 #include <sys/errno.h>
+#include <sys/types.h>
 
 #ifdef __linux__
 #include <sys/file.h>
