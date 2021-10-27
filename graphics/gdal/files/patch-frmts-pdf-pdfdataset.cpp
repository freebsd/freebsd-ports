--- frmts/pdf/pdfdataset.cpp.orig	2021-09-01 09:50:03 UTC
+++ frmts/pdf/pdfdataset.cpp
@@ -3593,7 +3593,7 @@ void PDFDataset::FindLayersPoppler()
 #if (POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 72)
                 const char* pszLayerName = (const char*)ocg->getName()->c_str();
 #else
-                const char* pszLayerName = (const char*)ocg->getName()->getCString();
+                const char* pszLayerName = (const char*)ocg->getName()->c_str();
 #endif
                 AddLayer(pszLayerName);
                 oLayerOCGListPoppler.push_back(std::make_pair(CPLString(pszLayerName), ocg));
@@ -4982,13 +4982,13 @@ PDFDataset *PDFDataset::Open( GDALOpenInfo * poOpenInf
 #ifdef HAVE_POPPLER
   if (bUseLib.test(PDFLIB_POPPLER))
   {
-    GooString* poMetadata = poCatalogPoppler->readMetadata();
+    auto poMetadata = poCatalogPoppler->readMetadata();
     if (poMetadata)
     {
 #if (POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 72)
         const char* pszContent = poMetadata->c_str();
 #else
-        const char* pszContent = poMetadata->getCString();
+        const char* pszContent = poMetadata->c_str();
 #endif
         if (pszContent != nullptr &&
             STARTS_WITH(pszContent, "<?xpacket begin="))
@@ -4996,7 +4996,9 @@ PDFDataset *PDFDataset::Open( GDALOpenInfo * poOpenInf
             const char * const apszMDList[2] = { pszContent, nullptr };
             poDS->SetMetadata(const_cast<char**>(apszMDList), "xml:XMP");
         }
+#if (POPPLER_MAJOR_VERSION < 21 || (POPPLER_MAJOR_VERSION == 21 && POPPLER_MINOR_VERSION <= 9))
         delete poMetadata;
+#endif
     }
 
     /* Read Info object */
