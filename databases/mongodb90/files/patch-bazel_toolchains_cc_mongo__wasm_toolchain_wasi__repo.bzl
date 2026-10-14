--- bazel/toolchains/cc/mongo_wasm/toolchain/wasi_repo.bzl.orig	2026-10-06 00:00:00 UTC
+++ bazel/toolchains/cc/mongo_wasm/toolchain/wasi_repo.bzl
@@ -51,20 +51,28 @@
     return arch
 
 def _setup_wasi_deps(rctx):
-    os = _normalize_os(rctx.os.name)
+    host_os = rctx.os.name
+    os = _normalize_os(host_os)
     arch = _normalize_arch(rctx.os.arch)
     key = (os, arch)
 
-    if key not in _WASI_SDK_DIST:
-        fail("Unsupported platform for wasi-sdk: os={}, arch={}".format(os, arch))
+    if host_os.startswith("freebsd"):
+        # FreeBSD uses the native clang (see below), so only the wasm32-wasip2
+        # sysroot and clang resource files of the wasi-sdk are needed. The
+        # port prepares them in a directory with the same layout.
+        for child in rctx.path(rctx.os.environ["WASI_SDK_DIR"]).readdir():
+            rctx.symlink(child, child.basename)
+    else:
+        if key not in _WASI_SDK_DIST:
+            fail("Unsupported platform for wasi-sdk: os={}, arch={}".format(os, arch))
 
-    dist = _WASI_SDK_DIST[key]
-    rctx.download_and_extract(
-        dist["url"],
-        output = "",
-        sha256 = dist["sha256"],
-        stripPrefix = dist["stripPrefix"],
-    )
+        dist = _WASI_SDK_DIST[key]
+        rctx.download_and_extract(
+            dist["url"],
+            output = "",
+            sha256 = dist["sha256"],
+            stripPrefix = dist["stripPrefix"],
+        )
 
     # This results from bazel not being able to copy empty directories.
     rctx.file(
@@ -75,6 +83,21 @@
     # the toolchain config can use the same label on all platforms.
     exe = ".exe" if os == "windows" else ""
 
+    if host_os.startswith("freebsd"):
+        localbase = rctx.os.environ.get("LOCALBASE")
+        if not localbase:
+            localbase = "/usr/local"
+        llvm_bindir = localbase + "/bin"
+        native_tools = {
+            "wasm32-wasip2-clang": "clang22",
+            "wasm32-wasip2-clang++": "clang++22",
+            "llvm-ar": "llvm-ar22",
+        }
+        for tool, native_tool in native_tools.items():
+            target_arg = "" if tool == "llvm-ar" else " --target=wasm32-wasip2"
+            rctx.delete("bin/" + tool + exe)
+            rctx.file("bin/" + tool + exe, content = "#!/bin/sh\nexec \"{}/{}\"{} \"$@\"\n".format(llvm_bindir, native_tool, target_arg), executable = True)
+
     rctx.file(
         "BUILD.bazel",
         content = """
@@ -95,4 +118,5 @@
 
 setup_wasi_deps = repository_rule(
     implementation = _setup_wasi_deps,
+    environ = ["LOCALBASE", "WASI_SDK_DIR"],
 )
