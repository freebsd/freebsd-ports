
$FreeBSD$

--- options.c.orig	Mon Sep 24 16:12:31 2001
+++ options.c	Mon Sep 24 16:12:47 2001
@@ -28,9 +28,9 @@
 #include "mpg321.h"
 #include "getopt.h"
 
-#include <sys/types.h>
-#include <unistd.h>
+#include <sys/time.h>
 #include <sys/resource.h>
+#include <unistd.h>
 #include <string.h>
 
 void parse_options(int argc, char *argv[], playlist *pl)
