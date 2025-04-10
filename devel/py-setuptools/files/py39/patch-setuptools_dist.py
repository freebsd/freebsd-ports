--- setuptools/dist.py.orig	2022-07-04 02:25:25 UTC
+++ setuptools/dist.py
@@ -777,8 +777,9 @@ class Distribution(_Distribution):
 
     def _setuptools_commands(self):
         try:
-            return metadata.distribution('setuptools').entry_points.names
-        except metadata.PackageNotFoundError:
+            dist = pkg_resources.get_distribution('setuptools')
+            return list(dist.get_entry_map('distutils.commands'))
+        except pkg_resources.DistributionNotFound:
             # during bootstrapping, distribution doesn't exist
             return []
 
