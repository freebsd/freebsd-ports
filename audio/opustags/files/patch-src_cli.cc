--- src/cli.cc.orig	2020-11-10 07:49:07 UTC
+++ src/cli.cc
@@ -12,6 +12,7 @@
 #include <errno.h>
 #include <getopt.h>
 #include <limits.h>
+#include <unistd.h>
 #include <string.h>
 #include <sys/stat.h>
 
