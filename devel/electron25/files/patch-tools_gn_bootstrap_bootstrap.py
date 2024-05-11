--- tools/gn/bootstrap/bootstrap.py.orig	2023-06-27 00:56:05 UTC
+++ tools/gn/bootstrap/bootstrap.py
@@ -123,7 +123,7 @@ def main(argv):
 
   shutil.copy2(
       os.path.join(BOOTSTRAP_DIR, 'last_commit_position.h'), gn_build_dir)
-  cmd = [ninja_binary, '-C', gn_build_dir, '-w', 'dupbuild=err', 'gn']
+  cmd = [ninja_binary, '-C', gn_build_dir, 'gn']
   if options.jobs:
     cmd += ['-j', str(options.jobs)]
   subprocess.check_call(cmd)
