--- lib/pure/os.nim.orig	2016-10-08 02:25:13 UTC
+++ lib/pure/os.nim
@@ -1450,9 +1450,6 @@ proc getAppFilename*(): string {.rtl, ex
     elif defined(solaris):
       result = getApplAux("/proc/" & $getpid() & "/path/a.out")
     elif defined(freebsd):
-      result = getApplAux("/proc/" & $getpid() & "/file")
-    # little heuristic that may work on other POSIX-like systems:
-    if result.len == 0:
       result = getApplHeuristic()
 
 proc getApplicationFilename*(): string {.rtl, extern: "nos$1", deprecated.} =
