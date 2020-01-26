--- src/extension/internal/pdfinput/pdf-input.cpp.orig	2020-01-25 21:47:43 UTC
+++ src/extension/internal/pdfinput/pdf-input.cpp
@@ -689,12 +689,12 @@ PdfInput::open(::Inkscape::Extension::Input * /*mod*/,
         //
         gchar const *poppler_datadir = g_getenv("POPPLER_DATADIR");
         if (poppler_datadir != NULL) {
-            globalParams = new GlobalParams(poppler_datadir);
+            globalParams = std::unique_ptr<GlobalParams>(new GlobalParams(poppler_datadir));
         } else {
-            globalParams = new GlobalParams();
+            globalParams = std::unique_ptr<GlobalParams>(new GlobalParams());
         }
 #else
-        globalParams = new GlobalParams();
+        globalParams = std::unique_ptr<GlobalParams>(new GlobalParams());
 #endif // ENABLE_OSX_APP_LOCATIONS
     }
 
