--- koch.nim.orig	2018-03-14 15:15:05.712810000 +0000
+++ koch.nim	2018-03-14 15:15:42.575087000 +0000
@@ -265,7 +265,8 @@
 
   #nimexec "c -o:" & ("bin/nimresolve".exe) & " tools/nimresolve.nim"
 
-  buildNimble(latest)
+  # Don't build Nimble here. Use the port instead.
+  #buildNimble(latest)
 
 proc nsis(args: string) =
   bundleNimbleExe()
