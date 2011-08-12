--- src/Motif/menus.C.orig	1999-04-14 23:50:14.000000000 +0900
+++ src/Motif/menus.C	2011-08-11 02:41:55.000000000 +0900
@@ -52,7 +52,7 @@
 {
   w = w; cbs = cbs;
 
-  switch( (int) client_data) {
+  switch( (unsigned long) client_data) {
   case ItemFileQuit:
     quit();
     break;
@@ -64,7 +64,7 @@
 {
   w = w; cbs = cbs;
 
-  switch( (int) client_data) {
+  switch( (unsigned long) client_data) {
   case ItemHelpAbout:
     if (NULL != mythis->about)
       mythis->about->show_dialog();
