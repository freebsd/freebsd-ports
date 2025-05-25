--- ogrgrass.h.orig	2025-02-06 13:45:38 UTC
+++ ogrgrass.h
@@ -56,9 +56,9 @@ class OGRGRASSLayer final : public OGRLayer
         return poFeatureDefn;
     }
     GIntBig GetFeatureCount(int) override;
-    OGRErr GetExtent(OGREnvelope *psExtent, int bForce) override;
+    OGRErr GetExtent(OGREnvelope *psExtent, int bForce);
     virtual OGRErr GetExtent(int iGeomField, OGREnvelope *psExtent,
-                             int bForce) override
+                             int bForce)
     {
         return OGRLayer::GetExtent(iGeomField, psExtent, bForce);
     }
@@ -73,8 +73,8 @@ class OGRGRASSLayer final : public OGRLayer
 
     // Filters
     virtual OGRErr SetAttributeFilter(const char *query) override;
-    virtual void SetSpatialFilter(OGRGeometry *poGeomIn) override;
-    virtual void SetSpatialFilter(int iGeomField, OGRGeometry *poGeom) override
+    virtual void SetSpatialFilter(OGRGeometry *poGeomIn);
+    virtual void SetSpatialFilter(int iGeomField, OGRGeometry *poGeom)
     {
         OGRLayer::SetSpatialFilter(iGeomField, poGeom);
     }
