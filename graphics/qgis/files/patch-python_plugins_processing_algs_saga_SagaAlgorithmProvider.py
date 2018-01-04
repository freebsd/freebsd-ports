--- python/plugins/processing/algs/saga/SagaAlgorithmProvider.py.orig	2017-10-27 12:00:21 UTC
+++ python/plugins/processing/algs/saga/SagaAlgorithmProvider.py
@@ -73,7 +73,7 @@ class SagaAlgorithmProvider(AlgorithmProvider):
                                    self.tr('Problem with SAGA installation: SAGA was not found or is not correctly installed'))
             return
 
-        if not version.startswith('2.3.'):
+        if version < '2.3.':
             ProcessingLog.addToLog(ProcessingLog.LOG_ERROR,
                                    self.tr('Problem with SAGA installation: unsupported SAGA version found.'))
             return
