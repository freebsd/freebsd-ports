--- rpython/jit/backend/detect_cpu.py.orig	2016-06-14 07:46:04 UTC
+++ rpython/jit/backend/detect_cpu.py
@@ -61,6 +61,7 @@ def detect_model_from_host_platform():
             'i86pc': MODEL_X86,    # Solaris/Intel
             'x86': MODEL_X86,      # Apple
             'Power Macintosh': MODEL_PPC_64,
+            'powerpc': MODEL_PPC_64, # freebsd
             'ppc64': MODEL_PPC_64,
             'ppc64le': MODEL_PPC_64,
             'x86_64': MODEL_X86,
