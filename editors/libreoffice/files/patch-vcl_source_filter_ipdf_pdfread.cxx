--- vcl/source/filter/ipdf/pdfread.cxx.orig	2020-10-21 20:09:11 UTC
+++ vcl/source/filter/ipdf/pdfread.cxx
@@ -218,7 +218,7 @@ size_t RenderPDFBitmaps(const void* pBuffer, int nSize
     (void)rBitmaps;
     (void)nFirstPage;
     (void)nPages;
-    (void)fResolutionDPI;
+    (void)pSizeHint;
     return 0;
 #endif // HAVE_FEATURE_PDFIUM
 }
