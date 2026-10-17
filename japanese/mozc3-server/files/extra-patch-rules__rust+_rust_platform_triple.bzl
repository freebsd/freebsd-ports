--- rust/platform/triple.bzl.orig	2024-09-20 06:22:55.000000000 +0900
+++ rust/platform/triple.bzl	2025-02-19 10:18:50.874086000 +0900
@@ -115,6 +115,7 @@
 
     supported_architectures = {
         "linux": ["aarch64", "x86_64", "s390x"],
+        "freebsd": ["aarch64", "x86_64"],
         "macos": ["aarch64", "x86_64"],
         "windows": ["aarch64", "x86_64"],
     }
@@ -130,6 +131,10 @@
             abi or "gnu",
         ))
 
+    if "freebsd" in repository_ctx.os.name:
+        _validate_cpu_architecture(arch, supported_architectures["freebsd"])
+        return triple("{}-unknown-freebsd".format(arch))
+
     if "mac" in repository_ctx.os.name:
         _validate_cpu_architecture(arch, supported_architectures["macos"])
         return triple("{}-apple-darwin".format(arch))
