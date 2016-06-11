--- src/gui/pdfutil.cc.orig	2009-04-07 00:24:47.000000000 +0900
+++ src/gui/pdfutil.cc	2011-03-21 20:36:57.000000000 +0900
@@ -451,7 +451,20 @@
  @param askPassword If true, password will be asked for if necessary
 */
 boost::shared_ptr<CPdf> getPdfInstance(QWidget *parent, const QString &filename, CPdf::OpenMode mode, bool askPassword) {
- boost::shared_ptr<CPdf> pdf=CPdf::getInstance(util::convertFromUnicode(filename,util::NAME).c_str(), mode);
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
+
  if (askPassword && pdf->needsCredentials()) {
   for(;;) {
    //Ask for password until we either get the right one or user gets bored with retrying
