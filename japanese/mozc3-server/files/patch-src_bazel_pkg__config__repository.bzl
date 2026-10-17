--- src/bazel/pkg_config_repository.bzl.orig	2026-07-15 15:24:24 UTC
+++ src/bazel/pkg_config_repository.bzl
@@ -74,6 +74,9 @@ cc_library(
     linkopts = [
         {linkopts}
     ],
+    srcs = [
+        {srcs}
+    ]
 )
 """
 
@@ -182,12 +185,24 @@ def _pkg_config_repository_impl(repo_ctx):
         includes = _exec_pkg_config(repo_ctx, ["--cflags-only-I", "--keep-system-cflags"])
     includes = [item[len("-I/"):] for item in includes]
     _symlinks(repo_ctx, includes)
+    includedirs = [item[len("/"):] for item in repo_ctx.attr.includedirs]
+    includes.extend(includedirs)
+    linkopts = _exec_pkg_config(repo_ctx, ["--libs-only-l"])
+    libdirs = _exec_pkg_config(repo_ctx, ["--libs-only-L"])
+    libdirs = [item[len("-L/"):] for item in libdirs]
+    libdir = "".join(libdirs)
+    srcs = [libdir + '/lib' + linkopt[len("-l"):] + '.so' for linkopt in linkopts]
+    _symlinks(repo_ctx, srcs)
+    symlinks = repo_ctx.attr.symlinks
+    symlinks = [item[len("/"):] for item in symlinks]
+    _symlinks(repo_ctx, symlinks)
     data = {
         "name": name,
         "hdrs": _make_strlist([item + "/**" for item in includes]),
         "copts": _make_strlist(_exec_pkg_config(repo_ctx, ["--cflags-only-other"])),
         "includes": _make_strlist(includes),
-        "linkopts": _make_strlist(_exec_pkg_config(repo_ctx, ["--libs-only-l"])),
+        "linkopts": _make_strlist(linkopts),
+        "srcs": _make_strlist(srcs),
     }
     build_file_data = BUILD_TEMPLATE.format(**data)
 
@@ -205,5 +220,7 @@ pkg_config_repository = repository_rule(
     attrs = {
         "exec_os": attr.string_list(default = ["linux"]),
         "packages": attr.string_list(),
+        "includedirs": attr.string_list(),
+        "symlinks": attr.string_list(),
     },
 )
