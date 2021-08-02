Add FreeBSD to the list of supported operating systems.

At the moment only the "amd64" architecture is defined here but it should be
possible to add more architectures here.

--- local_repos/rules_nodejs/internal/common/os_name.bzl.orig	2021-07-27 08:47:19 UTC
+++ local_repos/rules_nodejs/internal/common/os_name.bzl
@@ -21,6 +21,7 @@ OS_ARCH_NAMES = [
     ("linux", "amd64"),
     ("linux", "arm64"),
     ("linux", "s390x"),
+    ("freebsd", "amd64"),
 ]
 
 OS_NAMES = ["_".join(os_arch_name) for os_arch_name in OS_ARCH_NAMES]
@@ -48,6 +49,13 @@ def os_name(rctx):
             return OS_NAMES[4]
         else:
             return OS_NAMES[2]
+    elif os_name.startswith("freebsd"):
+        # This is not ideal, but bazel doesn't directly expose arch.
+        arch = rctx.execute(["uname", "-m"]).stdout.strip()
+        if arch == "amd64":
+            return OS_NAMES[5]
+        else:
+            fail("Unsupported FreeBSD architecture: " + arch)
     else:
         fail("Unsupported operating system: " + os_name)
 
