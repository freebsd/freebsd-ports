--- koch.nim.orig	2020-11-03 05:15:11 UTC
+++ koch.nim
@@ -687,7 +687,7 @@ when isMainModule:
       of "tools":
         buildTools(op.cmdLineRest)
         bundleNimbleExe(latest, op.cmdLineRest)
-        bundleFusion(latest)
+      #  bundleFusion(latest)
       of "pushcsource", "pushcsources": pushCsources()
       of "valgrind": valgrind(op.cmdLineRest)
       of "c2nim": bundleC2nim(op.cmdLineRest)
