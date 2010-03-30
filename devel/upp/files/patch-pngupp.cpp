--- uppsrc/plugin/png/pngupp.cpp.orig	2008-07-28 23:01:14.000000000 +0200
+++ uppsrc/plugin/png/pngupp.cpp	2010-03-30 09:55:38.000000000 +0200
@@ -427,7 +427,7 @@
 //	text_ptr[0].text = "Mona Lisa";
 //	text_ptr[0].compression = PNG_TEXT_COMPRESSION_NONE;
 	#ifdef PNG_iTXt_SUPPORTED
-	text_ptr[0].lang = NULL;
+//	text_ptr[0].lang = NULL;
 	#endif
 //	png_set_text(png_ptr, info_ptr, text_ptr, 1);
 
