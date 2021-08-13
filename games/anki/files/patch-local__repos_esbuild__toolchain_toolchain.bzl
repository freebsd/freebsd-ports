Set a custom repository for FreeBSD to use "devel/esbuild" from the Ports tree.

--- local_repos/esbuild_toolchain/toolchain.bzl.orig	2021-08-03 10:59:28 UTC
+++ local_repos/esbuild_toolchain/toolchain.bzl
@@ -14,6 +14,7 @@ TOOLCHAIN = "@esbuild_toolchain//:toolchain_type"
 
 _default_toolchains = [
     ["@esbuild_darwin//:bin/esbuild", "macos"],
+    ["@esbuild_freebsd//:bin/esbuild", "freebsd"],
     ["@esbuild_linux//:bin/esbuild", "linux"],
     ["@esbuild_linux_arm64//:bin/esbuild", "linux_arm64"],
     ["@esbuild_windows//:esbuild.exe", "windows"],
