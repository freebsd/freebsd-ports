--- bazel/platforms/local_config_platform.bzl.orig	2026-08-11 19:14:56 UTC
+++ bazel/platforms/local_config_platform.bzl
@@ -18,8 +18,10 @@ def _setup_local_config_platform(ctx):
         os = "windows"
     elif "mac" in ctx.os.name:
         os = "macos"
-    else:
+    elif "linux" in ctx.os.name:
         os = "linux"
+    elif "freebsd" in ctx.os.name:
+        os = "freebsd"
 
     arch = ctx.os.arch
 
@@ -31,7 +33,9 @@ def _setup_local_config_platform(ctx):
     # So Starlark doesn't throw an indentation error when this gets injected.
     constraints_str = ",\n        ".join(['"%s"' % c for c in constraints])
 
-    distro = get_host_distro_major_version(ctx)
+    distro = None
+    if os == "linux":
+        distro = get_host_distro_major_version(ctx)
     if arch == "x86_64":
         arch = "amd64"
     elif arch == "aarch64":
