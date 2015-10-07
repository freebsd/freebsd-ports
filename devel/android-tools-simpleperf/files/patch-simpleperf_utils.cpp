--- simpleperf/utils.cpp.orig	2015-08-12 01:49:40 UTC
+++ simpleperf/utils.cpp
@@ -20,6 +20,7 @@
 #include <errno.h>
 #include <stdarg.h>
 #include <stdio.h>
+#include <string.h> // strcmp
 #include <sys/stat.h>
 #include <unistd.h>
 
