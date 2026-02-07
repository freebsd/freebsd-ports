Only install docs for the host target

It otherwise wastes significant time (there are a lot of individual
files) and stages host docs, wasm docs, which unstages the host
docs first.

XXX: Shouldn't we instead just avoid adding docs-*-wasm* to _COMPONENTS in lang/rust/Makefile?

--- src/bootstrap/src/core/build_steps/install.rs.orig	2025-08-24 19:46:17 UTC
+++ src/bootstrap/src/core/build_steps/install.rs
@@ -206,7 +206,7 @@ install!((self, builder, _config),
 }
 
 install!((self, builder, _config),
-    Docs, path = "src/doc", _config.docs, IS_HOST: false, {
+    Docs, path = "src/doc", _config.docs, IS_HOST: true, {
         let tarball = builder.ensure(dist::Docs { host: self.target }).expect("missing docs");
         install_sh(builder, "docs", self.compiler.stage, Some(self.target), &tarball);
     };
