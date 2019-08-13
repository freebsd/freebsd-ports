error: the item `exit` is imported redundantly
  --> src/main.rs:86:25
   |
16 | use std::process::exit;
   |     ------------------ the item `exit` is already imported here
...
86 |                     use std::process::exit;
   |                         ^^^^^^^^^^^^^^^^^^
   |

--- src/main.rs.orig	2019-04-12 08:16:01 UTC
+++ src/main.rs
@@ -1,4 +1,3 @@
-#![deny(warnings)]
 #[macro_use]
 extern crate clap;
 
@@ -83,7 +82,6 @@ fn main() {
                 }
                 Err(e) => {
                     use std::io::Write;
-                    use std::process::exit;
 
                     writeln!(
                         &mut std::io::stderr(),
@@ -124,7 +122,6 @@ fn main() {
     if let Some(file) = args.value_of("output") {
         if let Err(e) = svg::save(file, &svg) {
             use std::io::Write;
-            use std::process::exit;
 
             writeln!(
                 &mut std::io::stderr(),
@@ -148,7 +145,6 @@ where
             Ok(a) => Some(a),
             Err(e) => {
                 use std::io::Write;
-                use std::process::exit;
 
                 writeln!(
                     &mut std::io::stderr(),
