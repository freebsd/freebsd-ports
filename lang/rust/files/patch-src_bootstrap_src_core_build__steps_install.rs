Only install docs for the host target

It otherwise wastes significant time (there are a lot of individual
files) and stages host docs, wasm docs, which unstages the host
docs first.

--- src/bootstrap/src/core/build_steps/install.rs.orig	2022-05-01 20:28:31 UTC
+++ src/bootstrap/src/core/build_steps/install.rs
@@ -204,7 +204,7 @@ install!((self, builder, _config),
 }
 
 install!((self, builder, _config),
-    Docs, path = "src/doc", _config.docs, IS_HOST: false, {
+    Docs, path = "src/doc", _config.docs, IS_HOST: true, {
         let tarball = builder.ensure(dist::Docs { host: self.target }).expect("missing docs");
         install_sh(builder, "docs", self.build_compiler, Some(self.target), &tarball);
     };
