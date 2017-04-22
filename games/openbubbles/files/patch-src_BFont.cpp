--- src/BFont.cpp.orig	2005-02-27 14:29:13 UTC
+++ src/BFont.cpp
@@ -314,7 +314,7 @@ int BFont_TextWidthFont(BFont_Info *Font
 /* counts the spaces of the strings */
 static int count (const char *text)
 {
-    char *p = NULL;
+    const char *p = NULL;
     int pos = -1;
     int i   = 0;
 
@@ -339,7 +339,7 @@ void BFont_JustifiedPutStringFont(SDL_Su
     int dif;
 
     char *strtmp;
-    char *p;
+    const char *p;
     int pos = -1;
     int xpos = 0;
 
