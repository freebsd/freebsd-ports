--- tools/gn/bootstrap/bootstrap.py.orig	2024-01-16 20:56:06 UTC
+++ tools/gn/bootstrap/bootstrap.py
@@ -122,7 +122,7 @@ def main(argv):
 
   shutil.copy2(
       os.path.join(BOOTSTRAP_DIR, 'last_commit_position.h'), gn_build_dir)
-  cmd = [ninja_binary, '-C', gn_build_dir, '-w', 'dupbuild=err', 'gn']
+  cmd = [ninja_binary, '-C', gn_build_dir, 'gn']
   if options.jobs:
     cmd += ['-j', str(options.jobs)]
   subprocess.check_call(cmd)
