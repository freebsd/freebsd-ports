--- export.c.orig	2007-05-24 07:20:04.000000000 +0200
+++ export.c	2010-03-30 14:44:05.000000000 +0200
@@ -116,8 +116,8 @@
   atext[1].compression = PNG_TEXT_COMPRESSION_NONE;
 
 #ifdef PNG_iTXt_SUPPORTED
-  text_ptr[0].lang = NULL;
-  text_ptr[1].lang = NULL;
+//  text_ptr[0].lang = NULL;
+//  text_ptr[1].lang = NULL;
 #endif
   png_set_text (ppng, pinfo, atext, 2);
 
