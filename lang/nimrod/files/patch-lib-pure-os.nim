--- lib/pure/os.nim.orig
+++ lib/pure/os.nim
@@ -1389,8 +1389,6 @@
     result = getApplAux("/proc/self/exe")
   elif defined(solaris):
     result = getApplAux("/proc/" & $getpid() & "/path/a.out")
-  elif defined(freebsd):
-    result = getApplAux("/proc/" & $getpid() & "/file")
   elif defined(macosx):
     var size: cuint32
     getExecPath1(nil, size)
@@ -1399,16 +1397,14 @@
       result = "" # error!
   else:
     # little heuristic that may work on other POSIX-like systems:
-    result = string(getEnv("_"))
-    if len(result) == 0:
-      result = string(ParamStr(0))
-      # POSIX guaranties that this contains the executable
-      # as it has been executed by the calling process
-      if len(result) > 0 and result[0] != DirSep: # not an absolute path?
-        # iterate over any path in the $PATH environment variable
-        for p in split(string(getEnv("PATH")), {PathSep}):
-          var x = joinPath(p, result)
-          if ExistsFile(x): return x
+    result = string(ParamStr(0))
+    # POSIX guaranties that this contains the executable
+    # as it has been executed by the calling process
+    if len(result) > 0 and result[0] != DirSep: # not an absolute path?
+      # iterate over any path in the $PATH environment variable
+      for p in split(string(getEnv("PATH")), {PathSep}):
+        var x = joinPath(p, result)
+        if ExistsFile(x): return x
 
 proc getApplicationFilename*(): string {.rtl, extern: "nos$1", deprecated.} =
   ## Returns the filename of the application's executable.
