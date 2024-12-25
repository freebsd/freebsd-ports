--- setup.py.orig	2024-12-06 18:35:30 UTC
+++ setup.py
@@ -359,7 +359,7 @@ def awscrt_ext():
             # So it's simpler to link them in statically and have less runtime dependencies.
             #
             # Don't apply this trick to dependencies that are always on the OS (e.g. librt)
-            libraries = [':lib{}.a'.format(x) for x in libraries]
+            libraries = [':lib{}.so'.format(x) for x in libraries]
 
         # OpenBSD doesn't have librt; functions are found in libc instead.
         if not sys.platform.startswith('openbsd'):
