--- setup.py.orig	2017-04-19 05:48:10 UTC
+++ setup.py
@@ -60,7 +60,7 @@ def run_configure(option):
 
 
 def run_make_print_config():
-    stdout = subprocess.check_output(["make", "-s", "print-config"])
+    stdout = subprocess.check_output(["gmake", "-s", "print-config"])
     if IS_PYTHON3:
         stdout = stdout.decode("ascii")
 
