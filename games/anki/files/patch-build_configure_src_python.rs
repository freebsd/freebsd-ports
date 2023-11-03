Use the "PythonEnvironmentStub" function to use a native Python environment
instead of Python venv.

Avoid the use of Python's pip.

--- build/configure/src/python.rs.orig	2023-10-26 01:57:37 UTC
+++ build/configure/src/python.rs
@@ -13,6 +13,7 @@ use ninja_gen::python::PythonEnvironment;
 use ninja_gen::inputs;
 use ninja_gen::python::python_format;
 use ninja_gen::python::PythonEnvironment;
+use ninja_gen::python::PythonEnvironmentStub;
 use ninja_gen::python::PythonLint;
 use ninja_gen::python::PythonTypecheck;
 use ninja_gen::rsync::RsyncFiles;
@@ -81,6 +82,25 @@ pub fn setup_venv(build: &mut Build) -> Result<()> {
     Ok(())
 }
 
+pub fn setup_venv_stub(build: &mut Build) -> Result<()> {
+    build.add_action(
+        "pyenv",
+        PythonEnvironmentStub {
+            folder: "pyenv",
+            extra_binary_exports: &[
+                "mypy",
+                "black",    // Required in some parts of the code, but not for build
+                "isort",    // dito
+                "pylint",   // dito
+                "pytest",   // dito
+                "protoc-gen-mypy",
+            ],
+        },
+    )?;
+
+    Ok(())
+}
+
 pub struct GenPythonProto {
     pub proto_files: BuildInput,
 }
@@ -254,7 +274,6 @@ impl BuildAction for Sphinx {
 
     fn files(&mut self, build: &mut impl FilesHandle) {
         build.add_inputs("python", inputs![":pyenv:bin"]);
-        build.add_inputs("pip", inputs![":pyenv:pip"]);
         build.add_inputs("", &self.deps);
         build.add_output_stamp("python/sphinx/stamp");
     }
