-- default cache location to ~/.cache/emscripten
-- see also https://github.com/emscripten-core/emscripten/issues/23284

--- emcc.py.orig	2026-04-22 03:51:10 UTC
+++ emcc.py
@@ -343,6 +343,10 @@ def separate_linker_flags(newargs):
     linker_args.append(LinkFlag(flag, is_file))
 
   skip = False
+
+  if not config.CACHE:
+    config.CACHE = f"{os.environ['HOME']}/.cache/emscripten"
+
   for i in range(len(newargs)):
     if skip:
       skip = False
