--- bazel/toolchains/python/python_toolchain.bzl.orig
+++ bazel/toolchains/python/python_toolchain.bzl
@@ -55,82 +55,89 @@
         os = "windows"
     elif "mac" in ctx.os.name:
         os = "macos"
-    else:
+    elif "linux" in ctx.os.name:
         os = "linux"
+    elif "freebsd" in ctx.os.name:
+        os = "freebsd"
 
     if ctx.attr.arch:
         arch = ctx.attr.arch
     else:
         arch = ctx.os.arch
 
-    if ctx.attr.urls:
-        urls = ctx.attr.urls
-        sha = ctx.attr.sha256
+    if ctx.os.environ.get("MONGO_USE_SYSTEM_PYTHON"):
+        ctx.file("dist/bin/.keep", "")
+        ctx.symlink(ctx.os.environ.get("PYTHON_CMD", "python3"), "dist/bin/python3")
         interpreter_path = ctx.attr.interpreter_path
     else:
-        platform_info = URLS_MAP["{os}_{arch}".format(os = os, arch = arch)]
-        urls = platform_info["url"]
-        sha = platform_info["sha"]
-        interpreter_path = platform_info["interpreter_path"]
+        if ctx.attr.urls:
+            urls = ctx.attr.urls
+            sha = ctx.attr.sha256
+            interpreter_path = ctx.attr.interpreter_path
+        else:
+            platform_info = URLS_MAP["{os}_{arch}".format(os = os, arch = arch)]
+            urls = platform_info["url"]
+            sha = platform_info["sha"]
+            interpreter_path = platform_info["interpreter_path"]
 
-    ctx.report_progress("downloading python")
-    retry_download_and_extract(
-        ctx = ctx,
-        output = "dist",
-        tries = 5,
-        url = urls,
-        sha256 = sha,
-        stripPrefix = "python",
-    )
+        ctx.report_progress("downloading python")
+        retry_download_and_extract(
+            ctx = ctx,
+            output = "dist",
+            tries = 5,
+            url = urls,
+            sha256 = sha,
+            stripPrefix = "python",
+        )
 
-    windows_python = False
-    for name in ctx.path("dist").readdir():
-        if name.basename == "python.exe":
-            windows_python = True
-            break
+        windows_python = False
+        for name in ctx.path("dist").readdir():
+            if name.basename == "python.exe":
+                windows_python = True
+                break
 
-    if windows_python:
-        # windows does not have python version specific dir
-        usercustomize_file = "dist/Lib/site-packages/usercustomize.py"
-    else:
-        # detect python version without execution
-        # this looks for the `python#.#` binary on macos and linux
-        # and extracts the version information at the end of the binary,
-        # starlark doesn't have regex support so had to roll our own
-        # parsing.
-        python_base_dir = ctx.path("dist/bin")
-        bin_files = python_base_dir.readdir()
-        python_major_version = -1
-        python_minor_version = -1
-        for bin_file in bin_files:
-            basename = bin_file.basename
-            if basename.startswith("python"):
-                numeric = basename.replace("python", "")
-                versions = numeric.split(".")
-                if len(versions) == 2:
-                    numbers_only = True
-                    for version in versions:
-                        if not version.isdigit():
-                            numbers_only = False
-                    if numbers_only:
-                        python_major_version = versions[0]
-                        python_minor_version = versions[1]
-                        break
+        if windows_python:
+            # windows does not have python version specific dir
+            usercustomize_file = "dist/Lib/site-packages/usercustomize.py"
+        else:
+            # detect python version without execution
+            # this looks for the `python#.#` binary on macos and linux
+            # and extracts the version information at the end of the binary,
+            # starlark doesn't have regex support so had to roll our own
+            # parsing.
+            python_base_dir = ctx.path("dist/bin")
+            bin_files = python_base_dir.readdir()
+            python_major_version = -1
+            python_minor_version = -1
+            for bin_file in bin_files:
+                basename = bin_file.basename
+                if basename.startswith("python"):
+                    numeric = basename.replace("python", "")
+                    versions = numeric.split(".")
+                    if len(versions) == 2:
+                        numbers_only = True
+                        for version in versions:
+                            if not version.isdigit():
+                                numbers_only = False
+                        if numbers_only:
+                            python_major_version = versions[0]
+                            python_minor_version = versions[1]
+                            break
 
-        if python_major_version == -1 or python_minor_version == -1:
-            ctx.fail("Could not detect python versions")
+            if python_major_version == -1 or python_minor_version == -1:
+                ctx.fail("Could not detect python versions")
 
-        usercustomize_file = "dist/lib/python" + python_major_version + "." + python_minor_version + "/site-packages/usercustomize.py"
+            usercustomize_file = "dist/lib/python" + python_major_version + "." + python_minor_version + "/site-packages/usercustomize.py"
 
-    ctx.file(
-        usercustomize_file,
-        """
+        ctx.file(
+            usercustomize_file,
+            """
 import sys
 import os
 import tempfile
 sys.pycache_prefix = os.path.join(tempfile.gettempdir(), "bazel_pycache")
 """,
-    )
+        )
 
     ctx.report_progress("generating build file")
     os_constraint = OS_TO_PLATFORM_MAP[os]
@@ -152,7 +159,7 @@
         #ctx.execute(['icacls', 'dist', '/inheritance:r', '/grant:r', 'Everyone:R', '/T'])
         #ctx.execute(['icacls', 'dist', '/inheritance:r', '/grant:r', 'Administrators:R', '/T'])
         pass
-    else:
+    elif not ctx.os.environ.get("MONGO_USE_SYSTEM_PYTHON"):
         ctx.execute(["chmod", "-R", "544", "dist"])
 
     ctx.template(
@@ -173,7 +180,7 @@
             doc = "Expected SHA-256 sum of the archive.",
         ),
         "os": attr.string(
-            values = ["macos", "linux", "windows"],
+            values = ["macos", "linux", "windows", "freebsd"],
             doc = "Host operating system.",
         ),
         "arch": attr.string(
@@ -189,6 +196,7 @@
             doc = "Label denoting the BUILD file template that get's installed in the repo.",
         ),
     },
+    environ = ["MONGO_USE_SYSTEM_PYTHON", "PYTHON_CMD"],
 )
 
 def setup_mongo_python_toolchains():
@@ -231,6 +239,24 @@ def setup_mongo_python_toolchains():
         urls = [URLS_MAP["linux_s390x"]["url"]],
     )
 
+    py_download(
+        name = "py_freebsd_arm64",
+        arch = "aarch64",
+        os = "freebsd",
+    )
+
+    py_download(
+        name = "py_freebsd_x86_64",
+        arch = "amd64",
+        os = "freebsd",
+    )
+
+    py_download(
+        name = "py_freebsd_ppc64le",
+        arch = "ppc64le",
+        os = "freebsd",
+    )
+
     py_download(
         name = "py_windows_x86_64",
         arch = "amd64",
@@ -260,5 +286,8 @@ def setup_mongo_python_toolchains():
 
     return (
+        "@py_freebsd_arm64//:python_toolchain",
+        "@py_freebsd_x86_64//:python_toolchain",
+        "@py_freebsd_ppc64le//:python_toolchain",
         "@py_linux_arm64//:python_toolchain",
         "@py_linux_x86_64//:python_toolchain",
         "@py_linux_ppc64le//:python_toolchain",
