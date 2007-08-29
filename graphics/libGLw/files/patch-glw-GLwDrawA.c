--- src/glw/GLwDrawA.c.orig	Tue Mar 13 21:11:41 2007
+++ src/glw/GLwDrawA.c	Tue Mar 13 21:12:38 2007
@@ -668,7 +668,7 @@
 #endif
 
 
-#ifndef __GLX_MOTIF
+#ifdef __GLX_MOTIF
 
 /* Make context current */
 void GLwDrawingAreaMakeCurrent(Widget w,GLXContext ctx){
