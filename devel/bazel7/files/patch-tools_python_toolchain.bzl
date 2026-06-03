--- tools/python/toolchain.bzl.orig	1980-01-01 00:00:00 UTC
+++ tools/python/toolchain.bzl
@@ -191,7 +191,7 @@ def define_autodetecting_toolchain(
         name = "_autodetecting_py3_runtime",
         interpreter = ":py3wrapper.sh",
         python_version = "PY3",
-        stub_shebang = "#!/usr/bin/env python3",
+        stub_shebang = "#!%%PYTHON_CMD%%",
         visibility = ["//visibility:private"],
     )
 
@@ -199,7 +199,7 @@ def define_autodetecting_toolchain(
         name = "_autodetecting_py3_runtime_nonstrict",
         interpreter = ":py3wrapper_nonstrict.sh",
         python_version = "PY3",
-        stub_shebang = "#!/usr/bin/env python3",
+        stub_shebang = "#!%%PYTHON_CMD%%",
         visibility = ["//visibility:private"],
     )
 
