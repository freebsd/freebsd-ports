--- python/plugins/processing/algs/saga/SagaAlgorithmProvider.py.orig	2021-02-20 09:09:52 UTC
+++ python/plugins/processing/algs/saga/SagaAlgorithmProvider.py
@@ -86,13 +86,13 @@ class SagaAlgorithmProvider(QgsProcessingProvider):
             version is not None
             and (
                 version.startswith(REQUIRED_VERSION)
-                or version.startswith(BETA_SUPPORT_VERSION)
+                or version >= BETA_SUPPORT_VERSION
             )
         )
 
     def warningMessage(self):
         version = SagaUtils.getInstalledVersion(True)
-        if version is not None and version.startswith(BETA_SUPPORT_VERSION):
+        if version is not None and version >= BETA_SUPPORT_VERSION:
             return self.tr('SAGA version {} is not officially supported - algorithms may encounter issues').format(version)
         return ''
 
@@ -103,7 +103,7 @@ class SagaAlgorithmProvider(QgsProcessingProvider):
                                      self.tr('Processing'), Qgis.Critical)
             return
 
-        if not version.startswith(REQUIRED_VERSION) and not version.startswith(BETA_SUPPORT_VERSION):
+        if not version.startswith(REQUIRED_VERSION) and not version >= BETA_SUPPORT_VERSION:
             QgsMessageLog.logMessage(self.tr('Problem with SAGA installation: unsupported SAGA version (found: {}, required: {}).').format(version, REQUIRED_VERSION),
                                      self.tr('Processing'),
                                      Qgis.Critical)
