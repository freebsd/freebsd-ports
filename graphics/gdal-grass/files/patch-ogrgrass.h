--- ogrgrass.h.orig	2015-02-06 15:30:50 UTC
+++ ogrgrass.h
@@ -55,7 +55,7 @@ class OGRGRASSLayer : public OGRLayer
 
     // Layer info
     OGRFeatureDefn *    GetLayerDefn() { return poFeatureDefn; }
-    int                 GetFeatureCount( int );
+    GIntBig             GetFeatureCount( int );
     OGRErr              GetExtent(OGREnvelope *psExtent, int bForce);
     virtual OGRSpatialReference *GetSpatialRef();
     int                 TestCapability( const char * );
