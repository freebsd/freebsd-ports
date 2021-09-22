Skip the "cargo" command as the "maturin" binary is pre-built via the Port
itself.

--- setup.py.orig	2021-08-25 08:52:22 UTC
+++ setup.py
@@ -74,15 +74,15 @@ class PostInstallCommand(install):
                     ["--no-default-features", "--features=upload,log,human-panic"]
                 )
 
-            try:
-                metadata = json.loads(
-                    subprocess.check_output(cargo_args).splitlines()[-2]
-                )
-            except subprocess.CalledProcessError as exc:
-                raise RuntimeError("build maturin failed:\n" + exc.output.decode())
-            print(metadata)
-            assert metadata["target"]["name"] == "maturin"
-            source = metadata["filenames"][0]
+            #try:
+            #    metadata = json.loads(
+            #        subprocess.check_output(cargo_args).splitlines()[-2]
+            #    )
+            #except subprocess.CalledProcessError as exc:
+            #    raise RuntimeError("build maturin failed:\n" + exc.output.decode())
+            #print(metadata)
+            #assert metadata["target"]["name"] == "maturin"
+            #source = metadata["filenames"][0]
 
         # run this after trying to build with cargo (as otherwise this leaves
         # venv in a bad state: https://github.com/benfred/py-spy/issues/69)
@@ -90,7 +90,7 @@ class PostInstallCommand(install):
 
         target = os.path.join(self.install_scripts, executable_name)
         os.makedirs(self.install_scripts, exist_ok=True)
-        self.copy_file(source, target)
+        #self.copy_file(source, target)
         self.copy_tree(
             os.path.join(source_dir, "maturin"),
             os.path.join(self.install_lib, "maturin"),
