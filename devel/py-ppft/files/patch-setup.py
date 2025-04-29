--- setup.py.orig	2025-04-16 00:56:58 UTC
+++ setup.py
@@ -86,7 +86,7 @@ class BinaryDistribution(Distribution):
         return True
 
 # define dependencies
-dill_version = 'dill>=0.4.0'
+dill_version = 'dill>=0.3.9'
 # add dependencies
 depend = []
 extras = {'dill': [dill_version]}
