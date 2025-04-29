--- setup.py.orig	2025-04-17 03:46:26 UTC
+++ setup.py
@@ -95,7 +95,7 @@ class BinaryDistribution(Distribution):
         return True
 
 # define dependencies
-dill_version = 'dill>=0.4.0'
+dill_version = 'dill>=0.3.9'
 klepto_version = 'klepto>=0.2.7'
 pathos_version = 'pathos>=0.3.4'
 pyina_version = 'pyina>=0.3.0'
