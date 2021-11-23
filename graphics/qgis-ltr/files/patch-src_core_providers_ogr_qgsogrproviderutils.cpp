--- src/core/providers/ogr/qgsogrproviderutils.cpp.orig	2021-11-19 12:08:37 UTC
+++ src/core/providers/ogr/qgsogrproviderutils.cpp
@@ -2311,7 +2311,7 @@ void QgsOgrProviderUtils::release( QgsOgrLayer *&layer
 }
 
 
-void QgsOgrProviderUtils::releaseDataset( QgsOgrDataset *&ds )
+void QgsOgrProviderUtils::releaseDataset( QgsOgrDataset *ds )
 {
   if ( !ds )
     return;
@@ -2319,7 +2319,6 @@ void QgsOgrProviderUtils::releaseDataset( QgsOgrDatase
   QMutexLocker locker( sGlobalMutex() );
   releaseInternal( ds->mIdent, ds->mDs, true );
   delete ds;
-  ds = nullptr;
 }
 
 bool QgsOgrProviderUtils::canDriverShareSameDatasetAmongLayers( const QString &driverName )
