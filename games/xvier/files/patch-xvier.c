--- ./xvier.c.orig	1992-07-29 02:04:33.000000000 +0200
+++ ./xvier.c	2014-03-30 13:14:36.798575126 +0200
@@ -5,10 +5,11 @@
 #include <signal.h>
 #include <sys/types.h>
 #include <sys/time.h>
+#include <string.h>
 
 #include "xvier.h"
 
-char *malloc();
+#include <stdlib.h>     /* malloc, free, rand */
 
 char *displayname = NULL, *geostring = NULL, *fontpattern = NULL;
 int iconic = 0, level = 0;
