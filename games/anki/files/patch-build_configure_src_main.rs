Check for NO_BUNDLE and NO_VENV environment variables.

Disable setup for offline documentation.

--- build/configure/src/main.rs.orig	2023-10-31 21:56:55 UTC
+++ build/configure/src/main.rs
@@ -9,6 +9,8 @@ mod web;
 mod rust;
 mod web;
 
+use std::env;
+
 use anyhow::Result;
 use aqt::build_and_check_aqt;
 use bundle::build_bundle;
@@ -22,6 +24,7 @@ use python::setup_venv;
 use pylib::check_pylib;
 use python::check_python;
 use python::setup_venv;
+use python::setup_venv_stub;
 use rust::build_rust;
 use rust::check_minilints;
 use rust::check_rust;
@@ -45,15 +48,24 @@ fn main() -> Result<()> {
     check_proto(build, inputs![glob!["proto/**/*.proto"]])?;
 
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
-
-    setup_sphix(build)?;
+    
+    if env::var("NO_BUNDLE").is_ok() {
+        println!("NO_BUNDLE is set, skipping build of bundles.");
+    } else {
+        build_bundle(build)?;
+    }
 
     check_rust(build)?;
     check_pylib(build)?;
