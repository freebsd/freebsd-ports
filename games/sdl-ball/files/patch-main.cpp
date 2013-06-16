--- main.cpp.orig	2009-01-11 19:09:56.000000000 +0300
+++ main.cpp	2013-05-30 21:59:20.884120034 +0400
@@ -1420,7 +1420,7 @@
 //Leaves an trail of the ball
 class tracer {
   private:
-    GLfloat x[100], y[100], r[100], g[100], b[100], a[100],s[100], cr,cg,cb,;
+    GLfloat x[100], y[100], r[100], g[100], b[100], a[100],s[100], cr,cg,cb;
     bool active[100];
     int color;
     GLfloat lastX, lastY; //Last position where we spawned one
