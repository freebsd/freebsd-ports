--- src/main/starlark/builtins_bzl/common/python/providers.bzl.orig	1980-01-01 00:00:00 UTC
+++ src/main/starlark/builtins_bzl/common/python/providers.bzl
@@ -18,7 +18,7 @@ _CcInfo = _builtins.toplevel.CcInfo
 _CcInfo = _builtins.toplevel.CcInfo
 
 # NOTE: This is copied to PyRuntimeInfo.java
-DEFAULT_STUB_SHEBANG = "#!/usr/bin/env python3"
+DEFAULT_STUB_SHEBANG = "#!%%PYTHON_CMD%%"
 
 # NOTE: This is copied to PyRuntimeInfo.java
 DEFAULT_BOOTSTRAP_TEMPLATE = "@" + TOOLS_REPO + "//tools/python:python_bootstrap_template.txt"
