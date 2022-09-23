Add FreeBSD to the list of supported architectures for NodeJS.

--- local_repos/rules_nodejs/nodejs/private/os_name.bzl.orig	2022-07-03 10:33:49 UTC
+++ local_repos/rules_nodejs/nodejs/private/os_name.bzl
@@ -25,6 +25,7 @@ OS_ARCH_NAMES = [
     ("linux", "arm64"),
     ("linux", "s390x"),
     ("linux", "ppc64le"),
+    ("freebsd", "all"),
 ]
 
 OS_NAMES = ["_".join(os_arch_name) for os_arch_name in OS_ARCH_NAMES]
@@ -58,6 +59,8 @@ def os_name(rctx):
             return OS_NAMES[5]
         elif arch == "ppc64le":
             return OS_NAMES[6]
+    elif os_name.startswith("freebsd"):
+            return OS_NAMES[7]
 
     fail("Unsupported operating system {} architecture {}".format(os_name, arch))
 
@@ -73,7 +76,10 @@ def node_exists_for_os(node_version, os_name):
     return name == OS_NAMES[3] or name == OS_NAMES[4] or name == OS_NAMES[5] or name == OS_NAMES[6]
 
 def node_exists_for_os(node_version, os_name):
-    return "-".join([node_version, os_name]) in NODE_VERSIONS.keys()
+    if os_name.startswith("freebsd"):
+        return True
+    else:
+        return "-".join([node_version, os_name]) in NODE_VERSIONS.keys()
 
 def assert_node_exists_for_host(rctx):
     node_version = rctx.attr.node_version
