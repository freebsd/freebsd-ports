Avoid enabling Yarn again, which has already been prefetched and enabled by the
ports framework; otherwise, the build system will attempt to install Yarn in
${LOCALBASE}/bin.

--- build/ninja_gen/src/node.rs.orig	2026-08-05 14:40:46 UTC
+++ build/ninja_gen/src/node.rs
@@ -3,6 +3,7 @@ use std::collections::HashMap;
 
 use std::borrow::Cow;
 use std::collections::HashMap;
+use std::env;
 
 use anyhow::Result;
 use itertools::Itertools;
@@ -52,7 +53,11 @@ impl BuildAction for YarnSetup {
         if cfg!(windows) {
             "corepack.cmd enable yarn"
         } else {
-            "corepack enable yarn"
+            if env::var("PREINSTALLED_YARN").is_err() {
+                "corepack enable yarn"
+            } else {
+                "true"
+            }
         }
     }
 
