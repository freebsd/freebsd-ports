--- lib/database/src/so/nodes/SoText2.c++.orig	2018-11-05 17:54:41 UTC
+++ lib/database/src/so/nodes/SoText2.c++
SoText2.c++
@@ -889,7 +889,7 @@ SoBitmapFontCache::createUniFontList(con
     fontNums = new SbPList;
       
     while (s1 = (char *)strchr(s, ';')) {
-       *s1 = (char)NULL;  /* font name is pointed to s */
+       *s1 = 0;  /* font name is pointed to s */
 
        if ((fn = flCreateFont((const GLubyte*)s, mat, 0, NULL)) == (FLfontNumber)0) {
 #ifdef DEBUG
