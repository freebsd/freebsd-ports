--- src/calibre/ebooks/pdf/reflow.h.orig	2011-10-26 12:04:54.000000000 +0000
+++ src/calibre/ebooks/pdf/reflow.h	2011-10-26 12:09:04.000000000 +0000
@@ -244,11 +244,7 @@ class XMLOutputDev : public OutputDev {
     XMLImages *images;
     PDFDoc *doc;
 
-#if (POPPLER_MAJOR_VERSION == 0) && (POPPLER_MINOR_VERSION < 17)
-    void process_link(Link* link);
-#else
     void process_link(AnnotLink* link);
-#endif
 
 };
 }
