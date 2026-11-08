--- bazel/toolchains/cc/mongo_compiler_flags.bzl.orig	2026-09-29 00:00:00 UTC
+++ bazel/toolchains/cc/mongo_compiler_flags.bzl
@@ -39,9 +39,18 @@ STREAMS_THIRD_PARTY_DIR = "src/mongo/db/modules/enterp
 
 MONGO_GLOBAL_COPTS = MONGO_LINUX_CC_COPTS
 
+def freebsd_cxx_standard_copt(package_name):
+    if package_name.startswith("src/mongo"):
+        return select({
+            "@platforms//os:freebsd": ["-std=c++20"],
+            "//conditions:default": [],
+        })
+    return []
+
 def get_copts(name, package_name, copts = []):
     copts = MONGO_GLOBAL_COPTS + \
+            freebsd_cxx_standard_copt(package_name) + \
             copts + \
             force_includes_copt(package_name, name)
     return copts
