--- ./src/libuv/gyp_uv.py.orig	2014-06-28 04:53:11.000000000 +0900
+++ ./src/libuv/gyp_uv.py	2014-07-17 12:32:13.000000000 +0900
@@ -96,6 +96,9 @@
 
   if sys.platform == 'darwin' and '-DOS=android' in sys.argv[1:]:
     sys.platform='linux'    
+
+  if sys.platform.startswith('freebsd'):
+    args.append('--no-parallel')
     
   gyp_args = list(args)
   print gyp_args
