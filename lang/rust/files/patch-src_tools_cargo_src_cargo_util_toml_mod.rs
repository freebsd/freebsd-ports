Revert https://github.com/rust-lang/cargo/commit/6f214ac7520d71c480dbe93e3874f14cfdaf594b
since it break CARGO_USE_GITHUB ports.

--- src/tools/cargo/src/cargo/util/toml/mod.rs.orig	2021-09-06 18:42:51 UTC
+++ src/tools/cargo/src/cargo/util/toml/mod.rs
@@ -1780,11 +1780,12 @@ impl<P: ResolveToPath> DetailedTomlDependency<P> {
 
             for &(key, key_name) in &git_only_keys {
                 if key.is_some() {
-                    bail!(
-                        "key `{}` is ignored for dependency ({}).",
-                        key_name,
-                        name_in_toml
+                    let msg = format!(
+                        "key `{}` is ignored for dependency ({}). \
+                         This will be considered an error in future versions",
+                        key_name, name_in_toml
                     );
+                    cx.warnings.push(msg)
                 }
             }
         }
