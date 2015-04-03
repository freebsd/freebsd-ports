--- lib/pure/os.nim.orig
+++ lib/pure/os.nim
@@ -1785,8 +1785,7 @@
     result = getApplAux("/proc/" & $getpid() & "/path/a.out")
     if result.len == 0: result = getApplHeuristic()
   elif defined(freebsd):
-    result = getApplAux("/proc/" & $getpid() & "/file")
-    if result.len == 0: result = getApplHeuristic()
+     result = getApplHeuristic()
   elif defined(macosx):
     var size: cuint32
     getExecPath1(nil, size)
