--- ./fam/Log.c++.orig	2003-04-15 06:21:36.000000000 +0200
+++ ./fam/Log.c++	2014-01-03 02:35:10.000000000 +0100
@@ -28,9 +28,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
-#include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
 #ifdef HAVE_AUDIT
