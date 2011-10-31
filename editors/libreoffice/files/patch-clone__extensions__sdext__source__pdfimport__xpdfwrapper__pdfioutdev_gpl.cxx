--- clone/extensions/sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2011-10-26 13:23:40.000000000 +0000
+++ clone/extensions/sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx	2011-10-26 13:23:57.000000000 +0000
@@ -489,7 +489,7 @@ void PDFOutDev::endPage()
     printf("endPage\n");
 }
 
-void PDFOutDev::processLink(Link* link, Catalog*)
+void PDFOutDev::processLink(AnnotLink* link, Catalog*)
 {
     assert(link);
 
