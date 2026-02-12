--- platform_methods.py.orig	2025-03-25 23:11:16 UTC
+++ platform_methods.py
@@ -28,6 +28,9 @@ architecture_aliases = {
     "rv": "rv64",
     "riscv": "rv64",
     "riscv64": "rv64",
+    "powerpc64le": "ppc64",
+    "powerpc64": "ppc64",
+    "powerpc": "ppc32",
     "ppcle": "ppc32",
     "ppc": "ppc32",
     "ppc64le": "ppc64",
@@ -36,7 +39,7 @@ def detect_arch():
 
 
 def detect_arch():
-    host_machine = platform.machine().lower()
+    host_machine = platform.processor().lower()
     if host_machine in architectures:
         return host_machine
     elif host_machine in architecture_aliases.keys():
