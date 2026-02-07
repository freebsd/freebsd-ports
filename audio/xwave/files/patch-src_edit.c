--- src/edit.c.orig	1998-11-08 23:22:55 UTC
+++ src/edit.c
@@ -54,6 +54,7 @@ extern char begin_text[MAX_NUMLENGTH];
 extern bool button_2;
 
 /* these conversion routines are also in graphics.c */
+/* Commented out. M. Kraft 2000-06-28
 int mg_sel_leftsample(float step,int x)
 {
   return(ceil(step*x-0.5));
@@ -73,7 +74,7 @@ int mg_sel_rightpixel(float step,int x)
 {
   return((int)(((float)x+0.5)/step));
 } 
-
+*/
 
 void begin_up(Widget w, XtPointer client_data, XtPointer call_data)
 {
