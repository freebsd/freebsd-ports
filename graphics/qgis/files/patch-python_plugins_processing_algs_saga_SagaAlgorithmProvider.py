--- python/plugins/processing/algs/saga/SagaAlgorithmProvider.py.orig	2019-03-02 02:07:46 UTC
+++ python/plugins/processing/algs/saga/SagaAlgorithmProvider.py
@@ -82,7 +82,7 @@ class SagaAlgorithmProvider(QgsProcessingProvider):
 
     def canBeActivated(self):
         version = SagaUtils.getInstalledVersion(True)
-        if version is not None and version.startswith(REQUIRED_VERSION):
+        if version is not None and version >= REQUIRED_VERSION:
             return True
         return False
 
@@ -93,7 +93,7 @@ class SagaAlgorithmProvider(QgsProcessingProvider):
                                      self.tr('Processing'), Qgis.Critical)
             return
 
-        if not version.startswith(REQUIRED_VERSION):
+        if version < REQUIRED_VERSION:
             QgsMessageLog.logMessage(self.tr('Problem with SAGA installation: unsupported SAGA version (found: {}, required: {}).').format(version, REQUIRED_VERSION),
                                      self.tr('Processing'),
                                      Qgis.Critical)
