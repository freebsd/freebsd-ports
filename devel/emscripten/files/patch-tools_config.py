-- default cache location to ~/.cache/emscripten
-- see also https://github.com/emscripten-core/emscripten/issues/23284

--- tools/config.py.orig	2025-01-02 23:51:05 UTC
+++ tools/config.py
@@ -33,7 +33,7 @@ FROZEN_CACHE = None
 WASMTIME = None
 WASM_ENGINES: List[List[str]] = []
 FROZEN_CACHE = None
-CACHE = None
+CACHE = f"{os.environ['HOME']}/.cache/emscripten"
 PORTS = None
 COMPILER_WRAPPER = None
 
