--- src/tools/pdf_to_text.cc.orig	2010-04-23 15:58:36.000000000 +0900
+++ src/tools/pdf_to_text.cc	2011-03-21 20:37:12.000000000 +0900
@@ -47,6 +47,14 @@
 	struct _textify {
 		string operator () (shared_ptr<CPage> page)
 		{
+			// Update display params to use media box not default page rect (DEFAULT_PAGE_RX, DEFAULT_PAGE_RY)
+			// TODO upsidedown? get/set
+			DisplayParams dp;
+			dp.useMediaBox = gTrue;
+			dp.crop = gFalse;
+			dp.rotate = page->getRotation ();
+			page->setDisplayParams (dp);
+
 			string text;
 			static const std::string encoding="UTF-8";
 			page->getText (text, &encoding);
