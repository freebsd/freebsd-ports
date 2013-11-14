--- compiler/nimconf.nim.orig
+++ compiler/nimconf.nim
@@ -213,7 +213,9 @@
 proc getSystemConfigPath(filename: string): string =
   # try standard configuration file (installation did not distribute files
   # the UNIX way)
-  result = joinPath([getPrefixDir(), "config", filename])
+  var prefix = getPrefixDir()
+  result = joinPath([prefix, "etc", filename])
+  if not ExistsFile(result): result = joinPath([prefix, "config", filename])
   if not ExistsFile(result): result = "/etc/" & filename
 
 proc LoadConfigs*(cfg: string) =
@@ -221,9 +223,8 @@
   if libpath == "": 
     # choose default libpath:
     var prefix = getPrefixDir()
-    if prefix == "/usr": libpath = "/usr/lib/nimrod"
-    elif prefix == "/usr/local": libpath = "/usr/local/lib/nimrod"
-    else: libpath = joinPath(prefix, "lib")
+    libpath = joinPath(prefix, "lib/nimrod")
+    if not ExistsDir(libpath): libpath = joinPath(prefix, "lib")
 
   if optSkipConfigFile notin gGlobalOptions:
     readConfigFile(getSystemConfigPath(cfg))
