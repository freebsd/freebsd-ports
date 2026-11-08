--- src/bazel/pkg_config_repository.bzl.orig	2026-10-16 12:33:33 UTC
+++ src/bazel/pkg_config_repository.bzl
@@ -181,13 +181,32 @@ def _pkg_config_repository_impl(repo_ctx):
     if not includes or includes[0] == "":
         includes = _exec_pkg_config(repo_ctx, ["--cflags-only-I", "--keep-system-cflags"])
     includes = [item[len("-I/"):] for item in includes]
+
+    local_include = "%%LOCALBASE%%/include".lstrip("/")
+
+    if "ibus-1.0" in repo_ctx.attr.packages:
+        includes = [path for path in includes if path != local_include]
+
+    if "gl" in repo_ctx.attr.packages:
+        filtered_includes = []
+        for path in includes:
+            if path == local_include:
+                for subdir in ["GL", "KHR"]:
+                    source = repo_ctx.path("/" + path + "/" + subdir)
+                    if not source.exists:
+                        fail("Required OpenGL include directory not found: %s" % source)
+                    repo_ctx.symlink(source, "opengl_include/" + subdir)
+                filtered_includes.append("opengl_include")
+            else:
+                filtered_includes.append(path)
+        includes = filtered_includes
     _symlinks(repo_ctx, includes)
     data = {
         "name": name,
         "hdrs": _make_strlist([item + "/**" for item in includes]),
         "copts": _make_strlist(_exec_pkg_config(repo_ctx, ["--cflags-only-other"])),
         "includes": _make_strlist(includes),
-        "linkopts": _make_strlist(_exec_pkg_config(repo_ctx, ["--libs-only-l"])),
+        "linkopts": _make_strlist(_exec_pkg_config(repo_ctx, ["--libs"])),
     }
     build_file_data = BUILD_TEMPLATE.format(**data)
 
