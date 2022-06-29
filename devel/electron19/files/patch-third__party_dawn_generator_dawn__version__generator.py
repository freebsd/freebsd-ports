--- third_party/dawn/generator/dawn_version_generator.py.orig	2022-05-25 04:04:27 UTC
+++ third_party/dawn/generator/dawn_version_generator.py
@@ -23,11 +23,14 @@ def get_git():
 
 
 def get_gitHash(dawnDir):
-    result = subprocess.run([get_git(), 'rev-parse', 'HEAD'],
-                            stdout=subprocess.PIPE,
-                            cwd=dawnDir)
-    if result.returncode == 0:
-        return result.stdout.decode('utf-8').strip()
+    try:
+        result = subprocess.run([get_git(), "rev-parse", "HEAD"],
+                                stdout=subprocess.PIPE,
+                                cwd=dawnDir)
+        if result.returncode == 0:
+            return result.stdout.decode("utf-8").strip()
+    except Exception:
+        return ""
     # No hash was available (possibly) because the directory was not a git checkout. Dawn should
     # explicitly handle its absenece and disable features relying on the hash, i.e. caching.
     return ''
