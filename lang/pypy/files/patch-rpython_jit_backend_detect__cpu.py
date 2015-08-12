--- rpython/jit/backend/detect_cpu.py.orig	2015-08-11 18:20:39 UTC
+++ rpython/jit/backend/detect_cpu.py
@@ -63,6 +63,7 @@ def detect_model_from_host_platform():
             'AMD64': MODEL_X86,    # win64
             'armv7l': MODEL_ARM,
             'armv6l': MODEL_ARM,
+            'arm': MODEL_ARM,      # freebsd
             }.get(mach)
 
     if result is None:
