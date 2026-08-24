--- karukan-cli/src/bin/server.rs.orig	2026-08-09 15:30:55 UTC
+++ karukan-cli/src/bin/server.rs
@@ -15,6 +15,7 @@ use std::sync::{Arc, RwLock};
 use serde::{Deserialize, Serialize};
 use std::collections::HashMap;
 use std::sync::{Arc, RwLock};
+use std::{env, path::Path};
 use tower_http::{
     cors::{Any, CorsLayer},
     services::ServeDir,
@@ -283,8 +284,23 @@ async fn main() {
         app = app.route("/api/tokenize", post(tokenize_handler));
     }
 
+    // Prefer packaged static files, but keep local dev fallback.
+    let static_dir = env::var("KARUKAN_STATIC_DIR")
+        .ok()
+        .filter(|v| !v.is_empty())
+        .or_else(|| {
+            if Path::new("/usr/share/karukan/static").is_dir() {
+                Some("/usr/share/karukan/static".to_string())
+            } else if Path::new("static").is_dir() {
+                Some("static".to_string())
+            } else {
+                None
+            }
+        })
+        .unwrap_or_else(|| "/usr/share/karukan/static".to_string());
+
     let app = app
-        .fallback_service(ServeDir::new("static"))
+        .fallback_service(ServeDir::new(static_dir))
         .layer(DefaultBodyLimit::max(256 * 1024)) // 256 KB
         .layer(cors)
         .with_state(state);
