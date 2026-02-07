--- xworm.c.orig	1997-05-07 18:25:57.000000000 +0200
+++ xworm.c	2011-12-20 20:08:25.012174397 +0100
@@ -3,13 +3,20 @@
  
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#endif
 #include <time.h>
 #include <string.h>
 #include <stdio.h>
 
-#define gridfile "xworm.grid"
-#define fontfile "xworm.font"
-#define logofile "xworm.raw"
+#ifndef PREFIX
+#define PREFIX "."
+#endif
+
+#define gridfile XWORMDIR "/xworm.grid"
+#define fontfile XWORMDIR "/xworm.font"
+#define logofile XWORMDIR "/xworm.raw"
 
 #define maxQ 5000    /* max queue */
 #define NCOLORS 15   /* number of colours */
@@ -137,7 +144,7 @@
 int vec_wrline(char *,int,int,int);
 int vec_wrlineX(char *,int,int,int,float);
 
-void main(int argc, char **argv) {
+int main(int argc, char **argv) {
 
  memset(&timeout, 0, sizeof(struct timeval));
 
