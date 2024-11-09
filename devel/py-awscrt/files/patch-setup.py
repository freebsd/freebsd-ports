--- setup.py.orig	2024-10-23 17:56:10 UTC
+++ setup.py
@@ -353,7 +353,7 @@ def awscrt_ext():
         # In Brazil, both shared and static libs are available.
         # But Lambda requires all shared libs to be explicitly packaged up.
         # So it's simpler to link them in statically and have less runtime dependencies.
-        libraries = [':lib{}.a'.format(x) for x in libraries]
+        libraries = [':lib{}.so'.format(x) for x in libraries]
 
         # OpenBSD doesn't have librt; functions are found in libc instead.
         if not sys.platform.startswith('openbsd'):
