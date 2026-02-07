--- Tools/jit/_targets.py.orig	2025-04-08 13:54:08 UTC
+++ Tools/jit/_targets.py
@@ -538,6 +538,9 @@ def get_target(host: str) -> _COFF | _ELF | _MachO:
     elif re.fullmatch(r"x86_64-.*-linux-gnu", host):
         args = ["-fpic"]
         target = _ELF(host, args=args, ghccc=True)
+    elif re.fullmatch(r"amd64-.*-freebsd.*", host):
+        args = ["-fpic"]
+        target = _ELF(host, args=args, ghccc=True)
     else:
         raise ValueError(host)
     return target
