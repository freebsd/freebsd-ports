--- src/xmlconf.c.orig	Thu Oct 14 00:54:03 2004
+++ src/xmlconf.c	Thu Oct 14 00:55:28 2004
@@ -3,9 +3,9 @@
 void
 debugPrintLangIM (langim *langIM) {
 
-    if(!isDebugMode()) return;
-    
     imnodes *node;
+    
+    if(!isDebugMode()) return;
     
     if(langIM->lang)
         printf("lang: %s\n", langIM->lang);
