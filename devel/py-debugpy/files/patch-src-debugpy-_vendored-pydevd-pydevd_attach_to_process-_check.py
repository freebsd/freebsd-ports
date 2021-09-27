--- src/debugpy/_vendored/pydevd/pydevd_attach_to_process/_check.py.orig	2021-09-09 10:13:20 UTC
+++ src/debugpy/_vendored/pydevd/pydevd_attach_to_process/_check.py
@@ -1,2 +1,2 @@
 import add_code_to_python_process
-print add_code_to_python_process.run_python_code(3736, "print(20)", connect_debugger_tracing=False)
\ No newline at end of file
+print(add_code_to_python_process.run_python_code(3736, "print(20)", connect_debugger_tracing=False))
