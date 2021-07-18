--- scripts/taiseilib/version.py.orig	2021-04-30 18:54:50 UTC
+++ scripts/taiseilib/version.py
@@ -57,6 +57,8 @@ def get(*, rootdir=None, fallback=None, args=common.de
     rootdir = rootdir if rootdir is not None else args.rootdir
     fallback = fallback if fallback is not None else args.fallback_version
 
+    return Version(fallback)
+
     if rootdir is None:
         import pathlib
         rootdir = pathlib.Path(__file__).parent
