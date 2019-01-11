--- frmts/pdf/pdfdataset.cpp.orig	2018-12-14 21:37:15 UTC
+++ frmts/pdf/pdfdataset.cpp
@@ -3459,7 +3459,7 @@ void PDFDataset::FindLayersPoppler()
 #endif
             if( ocg != nullptr && ocg->getName() != nullptr )
             {
-                const char* pszLayerName = (const char*)ocg->getName()->getCString();
+                const char* pszLayerName = (const char*)ocg->getName()->c_str();
                 AddLayer(pszLayerName);
                 oLayerOCGMapPoppler[pszLayerName] = ocg;
             }
@@ -4787,7 +4787,7 @@ GDALDataset *PDFDataset::Open( GDALOpenI
     GooString* poMetadata = poCatalogPoppler->readMetadata();
     if (poMetadata)
     {
-        const char* pszContent = poMetadata->getCString();
+        const char* pszContent = poMetadata->c_str();
         if (pszContent != nullptr &&
             STARTS_WITH(pszContent, "<?xpacket begin="))
         {
