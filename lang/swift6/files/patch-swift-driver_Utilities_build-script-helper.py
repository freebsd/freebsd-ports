--- swift-driver/Utilities/build-script-helper.py.orig	2026-06-15 22:02:57 UTC
+++ swift-driver/Utilities/build-script-helper.py
@@ -199,7 +199,7 @@ def install_binary(file, source_dir, install_dir, verb
 
 def install_binary(file, source_dir, install_dir, verbose):
     print("Installing %s into: %s" % (file, install_dir))
-    cmd = ["rsync", "-a", os.path.join(source_dir, file), install_dir]
+    cmd = ["install", "-p", os.path.join(source_dir, file), install_dir]
     if verbose:
         print(" ".join(cmd))
     subprocess.check_call(cmd)
