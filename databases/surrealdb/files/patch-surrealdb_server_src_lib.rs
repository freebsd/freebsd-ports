-- workaround for:
-- * https://github.com/rust-lang/rust/issues/154476
-- * https://github.com/surrealdb/surrealdb/issues/7162

--- surrealdb/server/src/lib.rs.orig
+++ surrealdb/server/src/lib.rs
@@ -13,6 +13,7 @@
 // Temporarily allow deprecated items until version 3.0 for backward compatibility
 #![allow(deprecated)]
 #![deny(clippy::mem_forget)]
+#![recursion_limit = "256"]
 
 #[macro_use]
 extern crate tracing;
