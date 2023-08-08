Check for NO_BUNDLE and NO_VENV environment variables.

--- build/configure/src/main.rs.orig	2023-03-31 02:32:25 UTC
+++ build/configure/src/main.rs
@@ -10,6 +10,8 @@ mod web;
 mod rust;
 mod web;
 
+use std::env;
+
 use aqt::build_and_check_aqt;
 use bundle::build_bundle;
 use ninja_gen::python::setup_python;
@@ -20,6 +22,7 @@ use python::setup_venv;
 use python::check_copyright;
 use python::check_python;
 use python::setup_venv;
+use python::setup_venv_stub;
 use rust::build_rust;
 use rust::check_rust;
 use web::build_and_check_web;
@@ -39,13 +42,24 @@ fn main() -> Result<()> {
     let build = &mut build;
 
     setup_python(build)?;
-    setup_venv(build)?;
 
+    if env::var("NO_VENV").is_ok() {
+        println!("NO_VENV is set, using Python system environment.");
+        setup_venv_stub(build)?;
+    } else {
+        setup_venv(build)?;
+    }
+
     build_rust(build)?;
     build_pylib(build)?;
     build_and_check_web(build)?;
     build_and_check_aqt(build)?;
-    build_bundle(build)?;
+    
+    if env::var("NO_BUNDLE").is_ok() {
+        println!("NO_BUNDLE is set, skipping build of bundles.");
+    } else {
+        build_bundle(build)?;
+    }
 
     check_rust(build)?;
     check_pylib(build)?;
