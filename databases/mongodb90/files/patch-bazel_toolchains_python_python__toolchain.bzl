--- bazel/toolchains/python/python_toolchain.bzl.orig
+++ bazel/toolchains/python/python_toolchain.bzl
@@ -55,8 +55,10 @@
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
@@ -68,17 +70,20 @@
     host_os_name = ctx.os.name.lower()
     is_host_windows = "win" in host_os_name
     is_host_macos = "mac" in host_os_name or "darwin" in host_os_name
-    is_host_linux = not is_host_windows and not is_host_macos
+    is_host_freebsd = "freebsd" in host_os_name
+    is_host_linux = not is_host_windows and not is_host_macos and not is_host_freebsd
 
     is_toolchain_windows = os == "windows"
     is_toolchain_macos = os == "macos"
     is_toolchain_linux = os == "linux"
+    is_toolchain_freebsd = os == "freebsd"
 
     # Check if OS matches
     os_matches = (
         (is_host_windows and is_toolchain_windows) or
         (is_host_macos and is_toolchain_macos) or
-        (is_host_linux and is_toolchain_linux)
+        (is_host_linux and is_toolchain_linux) or
+        (is_host_freebsd and is_toolchain_freebsd)
     )
 
     # If OS doesn't match, create a minimal stub BUILD file and skip download
@@ -110,66 +115,71 @@
 """.format(constraints = constraints_str))
         return None
 
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
 
-    write_python_pyc_cache_prefix_customization(ctx, usercustomize_file)
+        write_python_pyc_cache_prefix_customization(ctx, usercustomize_file)
 
     ctx.report_progress("generating build file")
     os_constraint = OS_TO_PLATFORM_MAP[os]
@@ -191,7 +201,7 @@
         #ctx.execute(['icacls', 'dist', '/inheritance:r', '/grant:r', 'Everyone:R', '/T'])
         #ctx.execute(['icacls', 'dist', '/inheritance:r', '/grant:r', 'Administrators:R', '/T'])
         pass
-    else:
+    elif not ctx.os.environ.get("MONGO_USE_SYSTEM_PYTHON"):
         ctx.execute(["chmod", "-R", "544", "dist"])
 
     ctx.template(
@@ -212,7 +222,7 @@
             doc = "Expected SHA-256 sum of the archive.",
         ),
         "os": attr.string(
-            values = ["macos", "linux", "windows"],
+            values = ["macos", "linux", "windows", "freebsd"],
             doc = "Host operating system.",
         ),
         "arch": attr.string(
@@ -228,6 +238,7 @@
             doc = "Label denoting the BUILD file template that get's installed in the repo.",
         ),
     },
+    environ = ["MONGO_USE_SYSTEM_PYTHON", "PYTHON_CMD"],
 )
 
 def setup_mongo_python_toolchains(ctx):
@@ -281,6 +292,24 @@
     )
 
     py_download(
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
+    py_download(
         name = "py_windows_x86_64",
         arch = "amd64",
         os = "windows",
@@ -307,6 +336,9 @@
 
     # Return value is not used since toolchains are registered in MODULE.bazel
     return (
+        "@py_freebsd_arm64//:python_toolchain",
+        "@py_freebsd_x86_64//:python_toolchain",
+        "@py_freebsd_ppc64le//:python_toolchain",
         "@py_linux_arm64//:python_toolchain",
         "@py_linux_x86_64//:python_toolchain",
         "@py_linux_ppc64le//:python_toolchain",
