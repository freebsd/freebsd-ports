Only install docs for the host target

It otherwise wastes significant time (there are a lot of individual
files) and stages host docs, wasm docs, which unstages the host
docs first.

--- src/bootstrap/src/core/build_steps/install.rs.orig	2022-05-01 20:28:31 UTC
+++ src/bootstrap/src/core/build_steps/install.rs
@@ -138,7 +138,7 @@ macro_rules! install {
 }
 
 install!((self, builder, _config),
-    Docs, path = "src/doc", _config.docs, only_hosts: false, {
+    Docs, path = "src/doc", _config.docs, only_hosts: true, {
         let tarball = builder.ensure(dist::Docs { host: self.target }).expect("missing docs");
         install_sh(builder, "docs", self.compiler.stage, Some(self.target), &tarball);
     };
