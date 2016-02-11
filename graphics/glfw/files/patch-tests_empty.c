--- tests/empty.c.orig	2015-01-20 03:12:31 UTC
+++ tests/empty.c
@@ -34,6 +34,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/time.h> /* CLOCK_REALTIME */
 
 static volatile GLboolean running = GL_TRUE;
 
