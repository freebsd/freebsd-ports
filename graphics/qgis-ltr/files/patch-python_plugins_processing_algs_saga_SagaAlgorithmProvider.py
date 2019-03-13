--- python/plugins/processing/algs/saga/SagaAlgorithmProvider.py.orig	2018-11-23 12:08:36 UTC
+++ python/plugins/processing/algs/saga/SagaAlgorithmProvider.py
@@ -93,7 +93,7 @@ class SagaAlgorithmProvider(QgsProcessingProvider):
                                      self.tr('Processing'), Qgis.Critical)
             return
 
-        if not version.startswith(REQUIRED_VERSION):
+        if version < '2.3':
             QgsMessageLog.logMessage(self.tr('Problem with SAGA installation: unsupported SAGA version (found: {}, required: {}).').format(version, REQUIRED_VERSION),
                                      self.tr('Processing'),
                                      Qgis.Critical)
