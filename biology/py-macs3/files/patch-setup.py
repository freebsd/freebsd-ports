--- setup.py.orig	2023-11-15 16:09:23 UTC
+++ setup.py
@@ -40,7 +40,7 @@ classifiers =[\
 install_requires = [ "numpy>=1.19",
                      "hmmlearn>=0.3",
                      "cykhash>=2.0,<3.0",
-                     "Cython~=3.0" ]
+                     "Cython>=0" ]
 
 tests_requires = [ 'pytest' ]
 
@@ -70,7 +70,7 @@ def main():
 
     if not clang:
         try:
-            gcc_version_check = subprocess.check_output( ["gcc", "--version"], universal_newlines=True)
+            gcc_version_check = subprocess.check_output( ["cc", "--version"], universal_newlines=True)
             if gcc_version_check.find("clang") != -1:
                 clang = True
             else:
