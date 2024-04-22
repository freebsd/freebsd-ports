--- setup.py.orig	2024-02-24 14:39:02 UTC
+++ setup.py
@@ -70,7 +70,7 @@ def main():
 
     if not clang:
         try:
-            gcc_version_check = subprocess.check_output( ["gcc", "--version"], universal_newlines=True)
+            gcc_version_check = subprocess.check_output( ["cc", "--version"], universal_newlines=True)
             if gcc_version_check.find("clang") != -1:
                 clang = True
             else:
