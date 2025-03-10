-- default cache location to ~/.cache/emscripten
-- see also https://github.com/emscripten-core/emscripten/issues/23284

--- emcc.py.orig	2025-01-02 23:47:04 UTC
+++ emcc.py
@@ -1143,6 +1143,9 @@ def parse_args(newargs):  # noqa: C901, PLR0912, PLR09
   should_exit = False
   skip = False
 
+  if not config.CACHE:
+    config.CACHE = f"{os.environ['HOME']}/.cache/emscripten"
+
   for i in range(len(newargs)):
     if skip:
       skip = False
