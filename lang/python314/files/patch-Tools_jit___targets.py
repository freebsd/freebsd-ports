--- Tools/jit/_targets.py.orig	2025-10-07 09:34:52 UTC
+++ Tools/jit/_targets.py
@@ -54,7 +54,7 @@ class _Target(typing.Generic[_S, _R]):
     def _get_nop(self) -> bytes:
         if re.fullmatch(r"aarch64-.*", self.triple):
             nop = b"\x1f\x20\x03\xd5"
-        elif re.fullmatch(r"x86_64-.*|i686.*", self.triple):
+        elif re.fullmatch(r"amd64-.*|x86_64-.*|i686.*", self.triple):
             nop = b"\x90"
         else:
             raise ValueError(f"NOP not defined for {self.triple}")
@@ -559,6 +559,10 @@ def get_target(host: str) -> _COFF | _ELF | _MachO:
     elif re.fullmatch(r"x86_64-.*-linux-gnu", host):
         args = ["-fno-pic", "-mcmodel=medium", "-mlarge-data-threshold=0"]
         condition = "defined(__x86_64__) && defined(__linux__)"
+        target = _ELF(host, condition, args=args)
+    elif re.fullmatch(r"amd64-.*-freebsd.*", host):
+        args = ["-fno-pic", "-mcmodel=medium", "-mlarge-data-threshold=0"]
+        condition = "defined(__amd64__) && defined(__FreeBSD__)"
         target = _ELF(host, condition, args=args)
     else:
         raise ValueError(host)
