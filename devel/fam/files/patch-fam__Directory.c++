--- ./fam/Directory.c++.orig	2003-04-15 06:21:29.000000000 +0200
+++ ./fam/Directory.c++	2014-01-03 02:35:10.000000000 +0100
@@ -26,7 +26,7 @@
 #include <errno.h>
 #include <string.h>
 #include <stdio.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <unistd.h>
