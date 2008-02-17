--- ogr/ogrsf_frmts/kml/ogr2kmlgeometry.cpp.orig	Mon Dec 17 13:49:31 2007
+++ ogr/ogrsf_frmts/kml/ogr2kmlgeometry.cpp	Wed Dec 26 11:43:43 2007
@@ -365,7 +365,7 @@
 
 CPLXMLNode* OGR_G_ExportEnvelopeToKMLTree( OGRGeometryH hGeometry )
 {
-    VALIDATE_POINTER1( hGeometry, "OGR_G_ExportEnvelopeToKMLTree", NULL );
+    //VALIDATE_POINTER1( hGeometry, "OGR_G_ExportEnvelopeToKMLTree", NULL );
 
     CPLXMLNode* psBox = NULL;
     CPLXMLNode* psCoord = NULL;
