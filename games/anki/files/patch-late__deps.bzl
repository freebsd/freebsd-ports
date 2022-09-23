Avoid loading of Rust and Python PIP rules as both tries to load their
dependencies (cargo crates, Python packages) during the build process.

--- late_deps.bzl.orig	2022-06-24 05:10:06 UTC
+++ late_deps.bzl
@@ -1,10 +1,6 @@
 """Repo setup that can't happen until after defs.bzl:setup_deps() is run."""
 
-load("@py_deps//:requirements.bzl", "install_deps")
-load("@rules_rust//tools/rust_analyzer/raze:crates.bzl", "rules_rust_tools_rust_analyzer_fetch_remote_crates")
 load("@build_bazel_rules_nodejs//toolchains/esbuild:esbuild_repositories.bzl", "esbuild_repositories")
 
 def setup_late_deps():
-    install_deps()
-    rules_rust_tools_rust_analyzer_fetch_remote_crates()
     esbuild_repositories()
