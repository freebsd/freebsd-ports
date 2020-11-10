Skip the "cargo" command as the "maturin" binary is pre-built via the Port
itself.  Also change the destination directory to honor ${PREFIX}.

--- setup.py.orig	2020-08-17 14:45:47 UTC
+++ setup.py
@@ -55,10 +55,10 @@ class PostInstallCommand(install):
                     "cargo not found in PATH. Please install rust "
                     "(https://www.rust-lang.org/tools/install) and try again"
                 )
-            subprocess.check_call(
-                ["cargo", "rustc", "--bin", "maturin", "--", "-C", "link-arg=-s"]
-            )
-            source = os.path.join(source_dir, "target", "debug", executable_name)
+            source = os.path.join(source_dir, "target", "release", executable_name)
+            #subprocess.check_call(
+            #    ["cargo", "rustc", "--bin", "maturin", "--", "-C", "link-arg=-s"]
+            #)
         # run this after trying to build with cargo (as otherwise this leaves
         # venv in a bad state: https://github.com/benfred/py-spy/issues/69)
         install.run(self)
@@ -68,7 +68,7 @@ class PostInstallCommand(install):
         self.copy_file(source, target)
         self.copy_tree(
             os.path.join(source_dir, "maturin"),
-            os.path.join(self.root or self.install_lib, "maturin"),
+            os.path.join(self.install_lib, "maturin"),
         )
 
 
