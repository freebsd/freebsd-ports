--- main.cpp.orig	2013-09-13 20:14:07.890226440 +0400
+++ main.cpp	2013-09-13 20:14:24.001226100 +0400
@@ -31,6 +31,7 @@
 #include <vector>
 #include <sys/time.h>
 #include <sys/stat.h>
+#include <unistd.h> // for usleep()
 
 #include <dirent.h>
 
@@ -1420,7 +1421,7 @@
 //Leaves an trail of the ball
 class tracer {
   private:
-    GLfloat x[100], y[100], r[100], g[100], b[100], a[100],s[100], cr,cg,cb,;
+    GLfloat x[100], y[100], r[100], g[100], b[100], a[100],s[100], cr,cg,cb;
     bool active[100];
     int color;
     GLfloat lastX, lastY; //Last position where we spawned one
