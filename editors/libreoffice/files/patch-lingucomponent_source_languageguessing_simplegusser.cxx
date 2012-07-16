--- lingucomponent/source/languageguessing/simpleguesser.cxx.orig	2012-05-22 14:48:18.000000000 +0200
+++ lingucomponent/source/languageguessing/simpleguesser.cxx	2012-07-16 12:16:53.864632299 +0200
@@ -118,7 +118,7 @@
         return guesses;
 
     //calculate le number of unicode charcters (symbols)
-    int len = utfstrlen(text);
+    int len = utf8_strlen(text);
 
     if (len > MAX_STRING_LENGTH_TO_ANALYSE)
         len = MAX_STRING_LENGTH_TO_ANALYSE;
