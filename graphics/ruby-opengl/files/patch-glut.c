--- glut.c.orig	Fri Jan  7 01:37:43 2000
+++ glut.c	Thu Aug 21 23:46:38 2003
@@ -15,7 +15,7 @@
 static VALUE _funcname = Qnil; \
 static void glut_ ## _funcname ## Callback(); \
 static VALUE \
-glut_ ## _funcname ## (obj,arg1) \
+glut_ ## _funcname (obj,arg1) \
 VALUE obj,arg1; \
 { \
     int win; \
@@ -25,7 +25,7 @@
     if (win == 0) \
 	rb_raise(rb_eRuntimeError, "GLUT.%s needs current window", #_funcname); \
     rb_ary_store(_funcname, win, arg1); \
-    glut ## _funcname ## (glut_ ## _funcname ## Callback); \
+    glut ## _funcname (glut_ ## _funcname ## Callback); \
     return Qnil; \
 }
 
