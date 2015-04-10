--- compiler/nimconf.nim.orig	2015-04-02 16:30:19.768619132 +0200
+++ compiler/nimconf.nim	2015-04-02 16:44:18.476742363 +0200
@@ -215,20 +215,16 @@
   # the UNIX way)
   let p = getPrefixDir()
   result = joinPath([p, "config", filename])
-  when defined(unix):
-    if not existsFile(result): result = joinPath([p, "etc", filename])
-    if not existsFile(result): result = "/etc/" & filename
+  if not existsFile(result): result = joinPath([p, "etc", filename])
+  if not existsFile(result): result = "/etc/" & filename
 
 proc loadConfigs*(cfg: string) =
   # set default value (can be overwritten):
   if libpath == "": 
     # choose default libpath:
     var prefix = getPrefixDir()
-    when defined(posix):
-      if prefix == "/usr": libpath = "/usr/lib/nim"
-      elif prefix == "/usr/local": libpath = "/usr/local/lib/nim"
-      else: libpath = joinPath(prefix, "lib")
-    else: libpath = joinPath(prefix, "lib")
+    libpath = joinPath(prefix, "lib/nim")
+    if not existsDir(libpath): libpath = joinPath(prefix, "lib")
 
   if optSkipConfigFile notin gGlobalOptions:
     readConfigFile(getSystemConfigPath(cfg))
