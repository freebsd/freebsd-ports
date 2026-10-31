--- lib/parser/parser.nim.orig	2026-10-29 10:03:59 UTC
+++ lib/parser/parser.nim
@@ -521,7 +521,7 @@ proc resolveStdlibOnly(raw: string): string =
   if stdlibEnv.len > 0 and fileExists(stdlibEnv / key): return stdlibEnv / key
   try:
     let appDir = getAppDir()
-    for rel in ["../stdlib", "stdlib"]:
+    for rel in ["../share/puffin/stdlib", "../stdlib", "stdlib"]:
       if fileExists(appDir / rel / key): return appDir / rel / key
   except CatchableError: discard
   ""
@@ -3881,7 +3881,7 @@ proc resolveUsePath*(sourceDir, raw: string): string =
         if fileExists(cand): return cand
     try:
       let appDir = getAppDir()
-      for rel in ["../stdlib", "stdlib"]:
+      for rel in ["../share/puffin/stdlib", "../stdlib", "stdlib"]:
         for c in candidates:
           let cand = appDir / rel / c
           if fileExists(cand): return cand
@@ -4946,7 +4946,7 @@ proc resolveIncludePathExact(sourceDir, raw: string): 
     if fileExists(cand): return cand
   try:
     let appDir = getAppDir()
-    for rel in ["../stdlib", "stdlib"]:
+    for rel in ["../share/puffin/stdlib", "../stdlib", "stdlib"]:
       let cand = appDir / rel / raw
       if fileExists(cand): return cand
   except CatchableError: discard
