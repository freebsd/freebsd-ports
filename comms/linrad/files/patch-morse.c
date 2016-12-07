--- morse.c.orig	2016-12-07 15:17:38 UTC
+++ morse.c
@@ -80,7 +80,7 @@ int i, j;
 float r1;
 if(charbits > 6)
   {
-  chr=243;
+  chr=(char)243;
   }
 else
   {
