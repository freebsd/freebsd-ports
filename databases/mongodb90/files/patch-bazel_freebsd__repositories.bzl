--- /dev/null
+++ bazel/freebsd_repositories.bzl
@@ -0,0 +1,15 @@
+def _freebsd_system_yq_repo_impl(rctx):
+    localbase = rctx.os.environ.get("LOCALBASE", "/usr/local")
+    rctx.symlink("{}/bin/yq".format(localbase), "yq")
+    rctx.file(
+        "BUILD.bazel",
+        """
+package(default_visibility = ["//visibility:public"])
+exports_files(["yq"])
+""",
+    )
+
+freebsd_system_yq_repo = repository_rule(
+    implementation = _freebsd_system_yq_repo_impl,
+    environ = ["LOCALBASE"],
+)
