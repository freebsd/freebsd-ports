--- src/VF_FNTWV.c.orig	Wed May 30 13:03:47 2001
+++ src/VF_FNTWV.c	Mon Jun  4 16:11:58 2007
@@ -177,13 +177,13 @@
 
 
 
+Private int  ReadCapa();
 Public FontObj*
 CreateFont_FontWave(ent)
   char *ent;
 {
   Font     *font;
   FontObj  *fobj;
-  Private int  ReadCapa();
 
   if ((font = (Font*) malloc(sizeof(Font))) == NULL){
     printf("in CreateFont malloc() Error!\n");
@@ -217,22 +217,20 @@
 }
        
 
+Private int   FNTWVOpenFont();
 Private int
 OpenFont(obj)
   FontObj *obj;
 {
-  Private int   FNTWVOpenFont();
-
   return FNTWVOpenFont((Font*) obj->Locals);
 }
 
 
+Private int   FNTWVCloseFont();
 Private int
 CloseFont(obj)
   FontObj  *obj;
 {
-  Private int   FNTWVCloseFont();
-
   return FNTWVCloseFont((Font*) obj->Locals);
 }
 
