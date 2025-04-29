--- setup.py.orig	2025-04-17 04:15:45 UTC
+++ setup.py
@@ -104,7 +104,7 @@ class BinaryDistribution(Distribution):
         return True
 
 # define dependencies
-dill_version = 'dill>=0.4.0'
+dill_version = 'dill>=0.3.9'
 pox_version = 'pox>=0.3.6'
 pathos_version = 'pathos>=0.3.4'
 mystic_version = 'mystic>=0.4.4'
