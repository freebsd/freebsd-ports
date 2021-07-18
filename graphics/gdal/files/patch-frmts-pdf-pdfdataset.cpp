--- frmts/pdf/pdfdataset.cpp.orig	2021-04-27 09:12:27 UTC
+++ frmts/pdf/pdfdataset.cpp
@@ -3584,7 +3584,7 @@ void PDFDataset::FindLayersPoppler()
 #if (POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 72)
                 const char* pszLayerName = (const char*)ocg->getName()->c_str();
 #else
-                const char* pszLayerName = (const char*)ocg->getName()->getCString();
+                const char* pszLayerName = (const char*)ocg->getName()->c_str();
 #endif
                 AddLayer(pszLayerName);
                 oLayerOCGListPoppler.push_back(std::make_pair(CPLString(pszLayerName), ocg));
@@ -4969,7 +4969,7 @@ PDFDataset *PDFDataset::Open( GDALOpenInfo * poOpenInf
 #if (POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 72)
         const char* pszContent = poMetadata->c_str();
 #else
-        const char* pszContent = poMetadata->getCString();
+        const char* pszContent = poMetadata->c_str();
 #endif
         if (pszContent != nullptr &&
             STARTS_WITH(pszContent, "<?xpacket begin="))
