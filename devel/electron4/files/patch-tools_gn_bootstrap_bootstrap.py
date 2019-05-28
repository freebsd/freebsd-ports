--- tools/gn/bootstrap/bootstrap.py.orig	2019-03-15 06:38:26 UTC
+++ tools/gn/bootstrap/bootstrap.py
@@ -71,8 +71,6 @@ def main(argv):
       '--no-last-commit-position',
       '--out-path=' + gn_build_dir,
   ]
-  if not options.with_sysroot:
-    cmd.append('--no-sysroot')
   if options.debug:
     cmd.append('--debug')
   subprocess.check_call(cmd)
@@ -81,6 +79,8 @@ def main(argv):
       os.path.join(BOOTSTRAP_DIR, 'last_commit_position.h'), gn_build_dir)
   subprocess.check_call(
       ['ninja', '-C', gn_build_dir, 'gn', '-w', 'dupbuild=err'])
+  subprocess.check_call(
+    ['ninja', '-C', gn_build_dir, 'gn_unittests', '-w', 'dupbuild=err'])
   shutil.copy2(os.path.join(gn_build_dir, 'gn'), gn_path)
 
   gn_gen_args = options.gn_gen_args or ''
