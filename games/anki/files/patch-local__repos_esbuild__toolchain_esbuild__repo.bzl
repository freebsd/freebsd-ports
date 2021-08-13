Define a local repository to use "devel/esbuild" from the Ports tree.

--- local_repos/esbuild_toolchain/esbuild_repo.bzl.orig	2021-08-03 12:18:17 UTC
+++ local_repos/esbuild_toolchain/esbuild_repo.bzl
@@ -51,4 +51,9 @@ def esbuild_dependencies():
         sha256 = "60af935fc3c29d6defd6e3822d9a00220dc631f4aba5cf5af3ce12d2d0d268e6",
     )
 
+    native.local_repository(
+        name = "esbuild_freebsd",
+	path = "%%_MY_LOCALREPO%%/local_esbuild",
+    )
+
     register_default_toolchains()
