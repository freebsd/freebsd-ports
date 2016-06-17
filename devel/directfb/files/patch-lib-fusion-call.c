--- lib/fusion/call.c.orig	2012-05-23 13:43:12 UTC
+++ lib/fusion/call.c
@@ -31,6 +31,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <errno.h>
+#include <sys/stat.h>
 
 #include <fusion/build.h>
 
