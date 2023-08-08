--- pywal/util.py.orig	2023-03-29 11:39:40 UTC
+++ pywal/util.py
@@ -179,7 +179,7 @@ def disown(cmd):
 def get_pid(name):
     """Check if process is running by name."""
     try:
-        subprocess.check_output(["pidof", "-s", name])
+        subprocess.check_output(["pgrep", "-x", name])
     except subprocess.CalledProcessError:
         return False
 
