--- src/VF_FNTWV.c.orig	Fri Jan 19 03:46:07 2007
+++ src/VF_FNTWV.c	Fri Jan 19 03:47:04 2007
@@ -175,7 +175,9 @@
 Private int    read_word();
 Private long   read_long();
 
-
+Private int   ReadCapa();
+Private int   FNTWVOpenFont();
+Private int   FNTWVCloseFont();
 
 Public FontObj*
 CreateFont_FontWave(ent)
@@ -183,7 +185,6 @@
 {
   Font     *font;
   FontObj  *fobj;
-  Private int  ReadCapa();
 
   if ((font = (Font*) malloc(sizeof(Font))) == NULL){
     printf("in CreateFont malloc() Error!\n");
@@ -221,8 +222,6 @@
 OpenFont(obj)
   FontObj *obj;
 {
-  Private int   FNTWVOpenFont();
-
   return FNTWVOpenFont((Font*) obj->Locals);
 }
 
@@ -231,8 +230,6 @@
 CloseFont(obj)
   FontObj  *obj;
 {
-  Private int   FNTWVCloseFont();
-
   return FNTWVCloseFont((Font*) obj->Locals);
 }
 
