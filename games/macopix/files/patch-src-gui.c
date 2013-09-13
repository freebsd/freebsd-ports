--- src/gui.c.orig	2008-06-24 06:44:20.000000000 +0200
+++ src/gui.c	2013-09-13 14:36:40.096276204 +0200
@@ -4557,7 +4557,7 @@
   gchar *dest_file;
 
   if(flagChildDialog){
-    return;
+    return(NULL);
   }
   else{
     flagChildDialog=TRUE;
@@ -4637,7 +4637,7 @@
   char win_title[64];
 
   if(flagChildDialog){
-    return;
+    return(NULL);
   }
   else{
     flagChildDialog=TRUE;
