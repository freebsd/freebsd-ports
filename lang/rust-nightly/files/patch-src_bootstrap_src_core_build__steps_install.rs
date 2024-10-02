Only install docs for the host target

It otherwise wastes significant time (there are a lot of individual
files) and stages host docs, wasm docs, which unstages the host
docs first.

--- src/bootstrap/src/core/build_steps/install.rs.orig	2024-09-30 19:13:29 UTC
+++ src/bootstrap/src/core/build_steps/install.rs
@@ -197,7 +197,7 @@ install!((self, builder, _config),
 }
 
 install!((self, builder, _config),
-    Docs, path = "src/doc", _config.docs, only_hosts: false, {
+    Docs, path = "src/doc", _config.docs, only_hosts: true, {
         let tarball = builder.ensure(dist::Docs { host: self.target }).expect("missing docs");
         install_sh(builder, "docs", self.compiler.stage, Some(self.target), &tarball);
     };
