--- setup.py.orig	2024-01-28 20:20:28 UTC
+++ setup.py
@@ -103,7 +103,7 @@ class BinaryDistribution(Distribution):
         return True
 
 # define dependencies
-dill_version = 'dill>=0.3.8'
+dill_version = 'dill>=0.3.7'
 pox_version = 'pox>=0.3.4'
 pathos_version = 'pathos>=0.3.2'
 mystic_version = 'mystic>=0.4.2'
