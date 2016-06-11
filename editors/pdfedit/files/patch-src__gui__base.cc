--- src/gui/base.cc.orig	2010-02-22 01:17:40 UTC
+++ src/gui/base.cc
@@ -688,7 +688,20 @@ boost::shared_ptr<pdfobjects::CPdf> Base
  if (openMode=="readonly") mode=CPdf::ReadOnly;
  if (openMode=="readwrite") mode=CPdf::ReadWrite;
  //Basic mode without asking a password (we do not know how)
- return CPdf::getInstance(util::convertFromUnicode(filename,util::NAME).c_str(),mode);
+ boost::shared_ptr<pdfobjects::CPdf> pdf;
+ do {
+   try {
+     pdf = CPdf::getInstance(util::convertFromUnicode(filename,util::NAME).c_str(),mode);
+   }catch(PdfOpenException &e) {
+     // try to fallback to readonly mode
+     if (mode >= CPdf::ReadWrite) {
+       mode = CPdf::ReadOnly;
+       continue;
+     }
+     throw e;
+   }
+ }while(!pdf);
+ return pdf;
 }
 
 /** \copydoc loadFromFile */
