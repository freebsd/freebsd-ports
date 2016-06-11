--- src/gui/base.cc.orig	2010-02-22 10:17:40.000000000 +0900
+++ src/gui/base.cc	2011-03-21 20:36:57.000000000 +0900
@@ -688,7 +688,20 @@
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
