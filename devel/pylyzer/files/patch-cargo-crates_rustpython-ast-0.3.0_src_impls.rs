https://github.com/RustPython/Parser/commit/29c4728dbedc7e69cc2560b9b34058bbba9b1303

--- cargo-crates/rustpython-ast-0.3.0/src/impls.rs.orig	2024-02-10 11:55:13
+++ cargo-crates/rustpython-ast-0.3.0/src/impls.rs
@@ -54,11 +54,12 @@ impl<R> Expr<R> {
     }
 }
 
-#[cfg(target_arch = "x86_64")]
-static_assertions::assert_eq_size!(crate::Expr, [u8; 72]);
-#[cfg(target_arch = "x86_64")]
-static_assertions::assert_eq_size!(crate::Stmt, [u8; 160]);
-#[cfg(target_arch = "x86_64")]
-static_assertions::assert_eq_size!(crate::Pattern, [u8; 96]);
-#[cfg(target_arch = "x86_64")]
+// TODO: make this a #[test] to avoid eq comparison
+// #[cfg(target_arch = "x86_64")]
+// static_assertions::assert_eq_size!(crate::Expr, [u8; 72]);
+// #[cfg(target_arch = "x86_64")]
+// static_assertions::assert_eq_size!(crate::Stmt, [u8; 160]);
+// #[cfg(target_arch = "x86_64")]
+// static_assertions::assert_eq_size!(crate::Pattern, [u8; 96]);
+// #[cfg(target_arch = "x86_64")]
 static_assertions::assert_eq_size!(crate::ExceptHandler, [u8; 64]);
