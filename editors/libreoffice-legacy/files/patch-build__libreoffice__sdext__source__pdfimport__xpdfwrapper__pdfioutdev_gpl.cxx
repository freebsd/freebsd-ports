--- ./build/libreoffice/sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2010-11-11 16:03:29.000000000 +0000
+++ ./build/libreoffice/sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx	2011-10-29 17:46:20.000000000 +0000
@@ -150,7 +150,7 @@
 void writeJpeg_( OutputBuffer& o_rOutputBuf, Stream* str, bool bWithLinefeed )
 {
     // dump JPEG file as-is
-    str = ((DCTStream *)str)->getRawStream();
+    str = str->getBaseStream();
     str->reset();
 
     int c;
@@ -489,7 +489,7 @@
     printf("endPage\n");
 }
 
-void PDFOutDev::processLink(Link* link, Catalog*)
+void PDFOutDev::processLink(AnnotLink* link, Catalog*)
 {
     assert(link);
 
