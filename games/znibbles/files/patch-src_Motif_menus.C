--- src/Motif/menus.C.orig	1999-04-14 14:50:14 UTC
+++ src/Motif/menus.C
@@ -52,7 +52,7 @@ void Menus::file_handler(Widget w, XtPoi
 {
   w = w; cbs = cbs;
 
-  switch( (int) client_data) {
+  switch( (unsigned long) client_data) {
   case ItemFileQuit:
     quit();
     break;
@@ -64,7 +64,7 @@ void Menus::help_handler(Widget w, XtPoi
 {
   w = w; cbs = cbs;
 
-  switch( (int) client_data) {
+  switch( (unsigned long) client_data) {
   case ItemHelpAbout:
     if (NULL != mythis->about)
       mythis->about->show_dialog();
