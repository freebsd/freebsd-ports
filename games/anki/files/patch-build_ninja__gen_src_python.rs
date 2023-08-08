Add "PythonEnvironmentStub" stub function that is used if the NO_VENV
environment variable is set.

--- build/ninja_gen/src/python.rs.orig	2023-03-31 02:32:25 UTC
+++ build/ninja_gen/src/python.rs
@@ -87,6 +87,11 @@ pub struct PythonEnvironment {
     pub extra_binary_exports: &'static [&'static str],
 }
 
+pub struct PythonEnvironmentStub {
+    pub folder: &'static str,
+    pub extra_binary_exports: &'static [&'static str],
+}
+
 impl BuildAction for PythonEnvironment {
     fn command(&self) -> &str {
         "$runner pyenv $python_binary $builddir/$pyenv_folder $system_pkgs $base_requirements $requirements"
@@ -109,6 +114,35 @@ impl BuildAction for PythonEnvironment {
         build.add_variable("pyenv_folder", self.folder);
         build.add_outputs_ext("bin", bin_path("python"), true);
         build.add_outputs_ext("pip", bin_path("pip"), true);
+        for binary in self.extra_binary_exports {
+            build.add_outputs_ext(*binary, bin_path(binary), true);
+        }
+    }
+
+    fn check_output_timestamps(&self) -> bool {
+        true
+    }
+}
+
+impl BuildAction for PythonEnvironmentStub {
+    fn command(&self) -> &str {
+        "echo Running PythonEnvironmentStub..."
+    }
+
+    fn files(&mut self, build: &mut impl crate::build::FilesHandle) {
+        let bin_path = |binary: &str| -> Vec<String> {
+            let folder = self.folder;
+            let path = if cfg!(windows) {
+                format!("{folder}/scripts/{binary}.exe")
+            } else {
+                format!("{folder}/bin/{binary}")
+            };
+            vec![path]
+        };
+
+        build.add_inputs("python_binary", inputs!["$python_binary"]);
+        build.add_variable("pyenv_folder", self.folder);
+        build.add_outputs_ext("bin", bin_path("python"), true);
         for binary in self.extra_binary_exports {
             build.add_outputs_ext(*binary, bin_path(binary), true);
         }
