Only install docs for the host target

It otherwise wastes significant time (there are a lot of individual
files) and stages host docs, wasm docs, which unstages the host
docs first.

--- src/bootstrap/install.rs.orig	2021-03-22 17:05:25 UTC
+++ src/bootstrap/install.rs
@@ -133,7 +133,7 @@ macro_rules! install {
 }
 
 install!((self, builder, _config),
-    Docs, "src/doc", _config.docs, only_hosts: false, {
+    Docs, "src/doc", _config.docs, only_hosts: true, {
         let tarball = builder.ensure(dist::Docs { host: self.target }).expect("missing docs");
         install_sh(builder, "docs", self.compiler.stage, Some(self.target), &tarball);
     };
