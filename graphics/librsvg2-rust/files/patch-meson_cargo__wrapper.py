--- meson/cargo_wrapper.py.orig	2025-02-22 18:19:31 UTC
+++ meson/cargo_wrapper.py
@@ -164,6 +164,9 @@ else:
 else:
     buildtype = 'debug'
 
+cargo_cmd.extend(['--verbose'])
+cargo_cmd.extend(['--verbose'])
+
 if args.target:
     cargo_cmd.extend(['--target', args.target])
 
