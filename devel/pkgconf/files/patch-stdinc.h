--- ./stdinc.h.orig	2012-07-26 04:13:43.000000000 +0200
+++ ./stdinc.h	2012-07-29 11:31:53.000000000 +0200
@@ -23,6 +23,10 @@
 #include <stdbool.h>
 #include <string.h>
 #include <libgen.h>
+#include <dirent.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
 
 #ifdef _WIN32
 # define WIN32_LEAN_AND_MEAN
