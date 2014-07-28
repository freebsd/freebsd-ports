--- src/edit.c.orig	Mon Nov  9 08:22:55 1998
+++ src/edit.c	Fri Jun 30 20:48:28 2000
@@ -54,6 +54,7 @@
 extern bool button_2;
 
 /* these conversion routines are also in graphics.c */
+/* Commented out. M. Kraft 2000-06-28
 int mg_sel_leftsample(float step,int x)
 {
   return(ceil(step*x-0.5));
@@ -73,7 +74,7 @@
 {
   return((int)(((float)x+0.5)/step));
 } 
-
+*/
 
 void begin_up(Widget w, XtPointer client_data, XtPointer call_data)
 {
