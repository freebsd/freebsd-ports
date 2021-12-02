--- src/core/providers/ogr/qgsogrprovider.cpp.orig	2021-11-19 12:10:19 UTC
+++ src/core/providers/ogr/qgsogrprovider.cpp
@@ -5934,7 +5934,7 @@ void QgsOgrProviderUtils::release( QgsOgrLayer *&layer
 }
 
 
-void QgsOgrProviderUtils::releaseDataset( QgsOgrDataset *&ds )
+void QgsOgrProviderUtils::releaseDataset( QgsOgrDataset *ds )
 {
   if ( !ds )
     return;
@@ -5942,7 +5942,6 @@ void QgsOgrProviderUtils::releaseDataset( QgsOgrDatase
   QMutexLocker locker( sGlobalMutex() );
   releaseInternal( ds->mIdent, ds->mDs, true );
   delete ds;
-  ds = nullptr;
 }
 
 bool QgsOgrProviderUtils::canDriverShareSameDatasetAmongLayers( const QString &driverName )
