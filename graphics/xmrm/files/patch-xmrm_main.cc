--- xmrm_main.cc.orig	Tue Mar 10 00:00:00 1998
+++ xmrm_main.cc	Fri Nov 29 17:42:05 2002
@@ -6,7 +6,6 @@
 #include <tiffio.h>
 #include <stdlib.h>
 #include <unistd.h>
-#include <malloc.h> //****************
 #include "xmrm.h"
 #include "io.h"
 #include "const.h"
@@ -115,7 +114,7 @@
 // CREDITS_post_handler
 int CREDITS_post_handler(FL_OBJECT *ob, int event, FL_Coord mx, FL_Coord my, int key, void *xev)
 {
-  char s[] = "Starts NETSCAPE !";
+  char s[] = BROWSER_MSG;
 
   if (ob == fd_CREDITS->BT_Drop)
   {
@@ -170,10 +169,11 @@
     s="Morph Source Image into Destination Image according to your settings !";
   else if (ob == fd_MRM->BT_Drop)
   {
-    s = "Click this pixmap to start Netscape and visit the Institute of Computer Graphics !";
+    s = "Click this pixmap to visit the Institute of Computer Graphics !";
     if (event == FL_ENTER)
     {
-      fl_show_oneliner("Starts NETSCAPE !", ob->form->x + ob->x, ob->form->y + ob->y + ob->h + 1);
+      fl_show_oneliner("Visit Institute of Computer Graphics", ob->form->x + ob->x, ob->form->y + ob->y + ob->h + 1);
+      
       fl_set_pixmapbutton_pixmap(ob, xpm_drop_shadow, 0);
       fl_redraw_object(ob);
     }
@@ -308,7 +308,7 @@
   control.debug = 0;
   
   /* Init control: */
-  control.ControlClass(); // call constructor
+  control.ControlClassInit(); // call constructor
   temp = control.URL_manual;
 
   while( (c=getopt(argc, argv, "hdm:p:")) != -1)
