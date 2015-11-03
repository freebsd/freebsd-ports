--- python/plugins/processing/algs/saga/SagaAlgorithmProvider.py.orig	2015-10-23 12:10:38 UTC
+++ python/plugins/processing/algs/saga/SagaAlgorithmProvider.py
@@ -46,7 +46,10 @@ class SagaAlgorithmProvider(AlgorithmPro
     supportedVersions = {"2.1.2": ("2.1.2", SagaAlgorithm212),
                          "2.1.3": ("2.1.3", SagaAlgorithm213),
                          "2.1.4": ("2.1.4", SagaAlgorithm214),
-                         "2.2.0": ("2.2.0", SagaAlgorithm214)}
+                         "2.2.0": ("2.2.0", SagaAlgorithm214),
+                         "2.2.1": ("2.2.0", SagaAlgorithm214), 
+                         "2.2.2": ("2.2.2", SagaAlgorithm214), 
+                         "2.2.3": ("2.2.2", SagaAlgorithm214)}
 
     def __init__(self):
         AlgorithmProvider.__init__(self)
