--- ogrgrasslayer.cpp.orig	2015-02-06 15:30:50 UTC
+++ ogrgrasslayer.cpp
@@ -1013,7 +1013,7 @@ OGRErr OGRGRASSLayer::CreateFeature( OGR
 /*      Eventually we should consider implementing a more efficient     */
 /*      way of counting features matching a spatial query.              */
 /************************************************************************/
-int OGRGRASSLayer::GetFeatureCount( int bForce )
+GIntBig OGRGRASSLayer::GetFeatureCount( int bForce )
 {
     if( m_poFilterGeom != NULL || m_poAttrQuery != NULL )
         return OGRLayer::GetFeatureCount( bForce );
