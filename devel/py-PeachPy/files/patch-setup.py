--- setup.py.orig	2018-02-25 10:20:32 UTC
+++ setup.py
@@ -35,7 +35,7 @@ class GenerateInstructions(Command):
     def run(self):
         # package_dir may be None, in that case use the current directory.
         import os
-        if self.distribution.package_dir is None:
+        if not self.distribution.package_dir:
             src_dir = os.getcwd()
         else:
             src_dir = os.path.abspath(self.distribution.package_dir[""])
