--- bundles/pyml/pyml-current/pyml_arch_freebsd.ml.orig	2020-01-03 01:59:43 UTC
+++ bundles/pyml/pyml-current/pyml_arch_freebsd.ml
@@ -0,0 +1,12 @@
+let library_patterns: (int -> int -> string, unit, string) format list =
+  ["libpython%d.%dm.so"; "libpython%d.%d.so"]
+
+let library_suffix = ".so"
+
+let ensure_executable_suffix executable = executable
+
+let which = "which"
+
+external fd_of_int: int -> Unix.file_descr = "%identity"
+
+let path_separator = ":"
