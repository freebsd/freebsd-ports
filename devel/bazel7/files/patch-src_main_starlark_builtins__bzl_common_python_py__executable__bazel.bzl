--- src/main/starlark/builtins_bzl/common/python/py_executable_bazel.bzl.orig	1980-01-01 00:00:00 UTC
+++ src/main/starlark/builtins_bzl/common/python/py_executable_bazel.bzl
@@ -431,7 +431,7 @@ def _create_executable_zip_file(ctx, *, output, zip_fi
 def _create_executable_zip_file(ctx, *, output, zip_file):
     ctx.actions.run_shell(
         command = "echo '{shebang}' | cat - {zip} > {output}".format(
-            shebang = "#!/usr/bin/env python3",
+            shebang = "#!%%PYTHON_CMD%%",
             zip = zip_file.path,
             output = output.path,
         ),
