--- gyp_uv.py.orig	2015-02-09 21:06:37.000000000 +0100
+++ gyp_uv.py	2015-02-10 21:08:12.000000000 +0100
@@ -88,8 +88,9 @@
 
   # Some platforms (OpenBSD for example) don't have multiprocessing.synchronize
   # so gyp must be run with --no-parallel
-  if not gyp_parallel_support:
-    args.append('--no-parallel')
+  # FreeBSD: our gyp is too old and does not support '--no-parallel'
+  #if not gyp_parallel_support:
+  #  args.append('--no-parallel')
 
   gyp_args = list(args)
   print gyp_args
