--- sdext/source/pdfimport/xpdfwrapper/wrapper_gpl.cxx.orig	2022-03-23 13:32:00 UTC
+++ sdext/source/pdfimport/xpdfwrapper/wrapper_gpl.cxx
@@ -138,6 +138,15 @@ int main(int argc, char **argv)
     _setmode( _fileno( g_binary_out ), _O_BINARY );
 #endif
 
+#if POPPLER_CHECK_VERSION(22, 3, 0)
+    PDFDoc aDoc( std::make_unique<GooString>(pFileName),
+                 GooString(pOwnerPasswordStr),
+                 GooString(pUserPasswordStr) );
+
+    PDFDoc aErrDoc( std::make_unique<GooString>(pErrFileName),
+                 GooString(pOwnerPasswordStr),
+                 GooString(pUserPasswordStr) );
+#else
     PDFDoc aDoc( pFileName,
                  pOwnerPasswordStr,
                  pUserPasswordStr );
@@ -145,6 +154,7 @@ int main(int argc, char **argv)
     PDFDoc aErrDoc( pErrFileName,
                  pOwnerPasswordStr,
                  pUserPasswordStr );
+#endif
 
     // Check various permissions for aDoc.
     PDFDoc &rDoc = aDoc.isOk()? aDoc: aErrDoc;
