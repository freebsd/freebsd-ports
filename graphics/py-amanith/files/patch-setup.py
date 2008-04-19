--- setup.py	Thu Apr  6 16:23:35 2006
+++ setup.py	Sat Sep  2 17:34:01 2006
@@ -6,15 +6,19 @@
 import os
 from os.path import join
 
+LOCALBASE = os.environ['LOCALBASE']
+LOCALBASE = os.environ['LOCALBASE']
+
 try:
   amanith_base = os.environ["AMANITHDIR"]
 except:
-  amanith_base = "amanith"
+  amanith_base = os.environ['LOCALBASE']
+  LOCALBASE = os.environ['LOCALBASE']
 
 debug = False
 libs = ["amanith"]
-inc = [join("changes", "include"), join(amanith_base, "include"), "include"]
-lib = [join(amanith_base, "lib")]
+inc = [join("changes", "include"), join(amanith_base, "include"), join(LOCALBASE,"include") ,"include"]
+lib = [join(amanith_base, "lib"), join(LOCALBASE, "lib")]
 cc_args = []
 swig_args = ["-Ibuild/amanith"]
 
@@ -41,10 +45,10 @@
   def run(self):
     # Ultimately this should use patch(1) or something, but for now
     # we just copy the stuff over.
-    if not os.path.isdir(join("build", "amanith")):
-      os.makedirs(join("build", "amanith"))
-      shutil.copytree(join(amanith_base, "include"), join("build", "amanith", "include"))
-    self.copy("changes", join("build", "amanith"))
+    if not os.path.isdir(join("build", "amanith","include")):
+      os.makedirs(join("build", "amanith","include"))
+      shutil.copytree(join(amanith_base, "include","amanith"), join("build", "amanith", "include","amanith"))
+    self.copy(join("changes","include"), join("build", "amanith","include"))
     _build_ext.run(self)
 
 ext_amanith = Extension('_amanith', ['amanith.i'],
