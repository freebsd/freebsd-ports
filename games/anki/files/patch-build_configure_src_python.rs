Use the "PythonEnvironmentStub" function to use a native Python environment
instead of Python venv.

--- build/configure/src/python.rs.orig	2023-05-01 01:47:30 UTC
+++ build/configure/src/python.rs
@@ -11,6 +11,7 @@ use ninja_gen::python::PythonEnvironment;
 use ninja_gen::inputs;
 use ninja_gen::python::python_format;
 use ninja_gen::python::PythonEnvironment;
+use ninja_gen::python::PythonEnvironmentStub;
 use ninja_gen::python::PythonLint;
 use ninja_gen::python::PythonTypecheck;
 use ninja_gen::rsync::RsyncFiles;
@@ -73,6 +74,25 @@ pub fn setup_venv(build: &mut Build) -> Result<()> {
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
+    build.add(
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
 
