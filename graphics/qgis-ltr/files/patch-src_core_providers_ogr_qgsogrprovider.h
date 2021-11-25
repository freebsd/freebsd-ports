--- src/core/providers/ogr/qgsogrprovider.h.orig	2021-11-19 12:10:19 UTC
+++ src/core/providers/ogr/qgsogrprovider.h
@@ -503,7 +503,7 @@ class CORE_EXPORT QgsOgrProviderUtils
     static void release( QgsOgrLayer *&layer );
 
     //! Release a QgsOgrDataset*
-    static void releaseDataset( QgsOgrDataset *&ds );
+    static void releaseDataset( QgsOgrDataset *ds );
 
     //! Make sure that the existing pool of opened datasets on dsName is not accessible for new getLayer() attempts
     static void invalidateCachedDatasets( const QString &dsName );
