Use the "PythonEnvironmentStub" function to use a native Python environment
instead of Python venv.

--- build/configure/src/python.rs.orig	2023-08-19 22:41:35 UTC
+++ build/configure/src/python.rs
@@ -12,6 +12,7 @@ use ninja_gen::python::PythonEnvironment;
 use ninja_gen::inputs;
 use ninja_gen::python::python_format;
 use ninja_gen::python::PythonEnvironment;
+use ninja_gen::python::PythonEnvironmentStub;
 use ninja_gen::python::PythonLint;
 use ninja_gen::python::PythonTypecheck;
 use ninja_gen::rsync::RsyncFiles;
@@ -74,6 +75,25 @@ pub fn setup_venv(build: &mut Build) -> Result<()> {
             base_requirements_txt: inputs!["python/requirements.base.txt"],
             requirements_txt: inputs![reqs_qt5, "python/requirements.qt5_14.txt"],
             extra_binary_exports: &[],
+        },
+    )?;
+
+    Ok(())
+}
+
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
         },
     )?;
 
