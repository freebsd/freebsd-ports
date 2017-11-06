--- koch.nim.orig	2017-05-18 14:19:21.268379000 +0000
+++ koch.nim	2017-05-18 14:21:26.248851000 +0000
@@ -257,7 +257,6 @@
   let nimgrepExe = "bin/nimgrep".exe
   nimexec "c -o:" & nimgrepExe & " tools/nimgrep.nim"
   when defined(windows): buildVccTool()
-  buildNimble(latest)
 
 proc nsis(args: string) =
   bundleNimbleExe()
