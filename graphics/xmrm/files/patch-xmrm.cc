--- xmrm.cc.orig	Fri Nov 29 18:03:08 2002
+++ xmrm.cc	Fri Nov 29 17:41:19 2002
@@ -362,7 +362,7 @@
 //    fl_set_object_boxtype(obj,FL_NO_BOX);
     fl_set_object_lsize(obj,FL_NORMAL_SIZE);
     fl_set_object_lstyle(obj,FL_BOLD_STYLE);
-    fl_set_menu(obj, "HTML-Manual (Netscape)%l|ABOUT");
+    fl_set_menu(obj, "HTML-Manual%l|ABOUT");
     fl_set_object_callback(obj,callback_Menus,3);
 
 //******************************** SLIDERS *************************************************************
