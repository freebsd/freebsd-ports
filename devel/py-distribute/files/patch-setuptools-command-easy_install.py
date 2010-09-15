--- setuptools/command/easy_install.py	2010-07-15 01:59:21.000000000 +0200
+++ setuptools/command/easy_install.py.port	2010-09-15 17:49:35.000000000 +0200
@@ -688,7 +688,7 @@
             return True
         if not dist.has_metadata('zip-safe'):
             return True
-        return True
+        return False
 
     def maybe_move(self, spec, dist_filename, setup_base):
         dst = os.path.join(self.build_directory, spec.key)
