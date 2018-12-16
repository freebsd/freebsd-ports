--- filters/karbon/pdf/PdfImport.cpp.orig	2018-12-08 16:48:32 UTC
+++ filters/karbon/pdf/PdfImport.cpp
@@ -88,9 +88,9 @@ KoFilter::ConversionStatus PdfImport::convert(const QB
     SvgOutputDev * dev = new SvgOutputDev(m_chain->outputFile());
     if (dev->isOk()) {
         int rotate = 0;
-        GBool useMediaBox = gTrue;
-        GBool crop = gFalse;
-        GBool printing = gFalse;
+        bool useMediaBox = true;
+        bool crop = false;
+        bool printing = false;
         pdfDoc->displayPages(dev, firstPage, lastPage, hDPI, vDPI, rotate, useMediaBox, crop, printing);
         dev->dumpContent();
     }
