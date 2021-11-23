--- src/core/providers/ogr/qgsogrproviderutils.h.orig	2021-11-19 12:08:37 UTC
+++ src/core/providers/ogr/qgsogrproviderutils.h
@@ -216,7 +216,7 @@ class CORE_EXPORT QgsOgrProviderUtils
     static void release( QgsOgrLayer *&layer );
 
     //! Release a QgsOgrDataset*
-    static void releaseDataset( QgsOgrDataset *&ds );
+    static void releaseDataset( QgsOgrDataset *ds );
 
     //! Make sure that the existing pool of opened datasets on dsName is not accessible for new getLayer() attempts
     static void invalidateCachedDatasets( const QString &dsName );
