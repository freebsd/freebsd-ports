Obtained from:	https://github.com/OSGeo/gdal/commit/ab72c4893e6d14d488dfed25745d79f11bee45b9

--- frmts/jpeg2000/jpeg2000dataset.cpp.orig	2020-05-04 09:21:31 UTC
+++ frmts/jpeg2000/jpeg2000dataset.cpp
@@ -484,7 +484,7 @@ int JPEG2000Dataset::DecodeImage()
     /* the JP2 boxes match the ones of the code stream */
     if (nBands != 0)
     {
-        if (nBands != jas_image_numcmpts( psImage ))
+        if (nBands != static_cast<int>(jas_image_numcmpts( psImage )))
         {
             CPLError(CE_Failure, CPLE_AppDefined,
                      "The number of components indicated in the IHDR box (%d) mismatch "
@@ -595,7 +595,7 @@ GDALDataset *JPEG2000Dataset::Open( GDALOpenInfo * poO
 
 {
     int         iFormat;
-    char        *pszFormatName = nullptr;
+    const char *pszFormatName = nullptr;
 
     if (!Identify(poOpenInfo))
         return nullptr;
