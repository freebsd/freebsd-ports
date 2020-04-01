--- python/plugins/processing/algs/saga/SagaAlgorithmProvider.py.orig	2020-03-27 05:50:09 UTC
+++ python/plugins/processing/algs/saga/SagaAlgorithmProvider.py
@@ -79,7 +79,7 @@ class SagaAlgorithmProvider(QgsProcessingProvider):
 
     def canBeActivated(self):
         version = SagaUtils.getInstalledVersion(True)
-        if version is not None and (version.startswith(REQUIRED_VERSION) or version.startswith(BETA_SUPPORT_VERSION)):
+        if version is not None and version >= REQUIRED_VERSION:
             return True
         return False
 
@@ -96,7 +96,7 @@ class SagaAlgorithmProvider(QgsProcessingProvider):
                                      self.tr('Processing'), Qgis.Critical)
             return
 
-        if not version.startswith(REQUIRED_VERSION) and not version.startswith(BETA_SUPPORT_VERSION):
+        if version < REQUIRED_VERSION:
             QgsMessageLog.logMessage(self.tr('Problem with SAGA installation: unsupported SAGA version (found: {}, required: {}).').format(version, REQUIRED_VERSION),
                                      self.tr('Processing'),
                                      Qgis.Critical)
