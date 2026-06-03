--- platform_methods.py.orig	2026-01-25 23:11:41 UTC
+++ platform_methods.py
@@ -29,13 +29,16 @@ architecture_aliases = {
     "rv": "rv64",
     "riscv": "rv64",
     "riscv64": "rv64",
+    "powerpc64le": "ppc64",
+    "powerpc64": "ppc64",
+    "powerpc": "ppc32",
     "ppc64le": "ppc64",
     "loong64": "loongarch64",
 }
 
 
 def detect_arch():
-    host_machine = platform.machine().lower()
+    host_machine = platform.processor().lower()
     if host_machine in architectures:
         return host_machine
     elif host_machine in architecture_aliases.keys():
