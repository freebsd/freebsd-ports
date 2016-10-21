--- compiler/nimconf.nim.orig	2016-10-08 02:17:21 UTC
+++ compiler/nimconf.nim
@@ -221,9 +221,8 @@ proc getSystemConfigPath(filename: strin
   # the UNIX way)
   let p = getPrefixDir()
   result = joinPath([p, "config", filename])
-  when defined(unix):
-    if not existsFile(result): result = joinPath([p, "etc", filename])
-    if not existsFile(result): result = "/etc/" & filename
+  if not existsFile(result): result = joinPath([p, "etc", filename])
+  if not existsFile(result): result = "/etc/" & filename
 
 proc loadConfigs*(cfg: string) =
   setDefaultLibpath()
