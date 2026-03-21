--- setup.py.orig	2026-03-13 12:44:44 UTC
+++ setup.py
@@ -64,7 +64,7 @@ def build_library_files(dry_run):
     plt = sys.platform
     if 'linux' in plt or 'bsd' in plt or 'darwin' in plt or 'gnu' in plt:
         os.environ['CXXFLAGS'] = os.environ.get('CXXFLAGS', '') + ' -fPIC'
-    spawn(cmd, dry_run=dry_run)
+    spawn(cmd)
 
 
 class LlvmliteBuild(build):
