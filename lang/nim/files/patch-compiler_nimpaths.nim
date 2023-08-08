--- compiler/nimpaths.nim.orig	2022-11-21 01:04:21 UTC
+++ compiler/nimpaths.nim
@@ -20,8 +20,8 @@ Unstable API
 import os, strutils
 
 const
-  docCss* = "$nimr/doc/nimdoc.css"
-  docHackNim* = "$nimr/tools/dochack/dochack.nim"
+  docCss* = "$nimr/share/doc/nim/nimdoc.css"
+  docHackNim* = "$nimr/share/nim/dochack/dochack.nim"
   docHackJs* = docHackNim.changeFileExt("js")
   docHackJsFname* = docHackJs.lastPathPart
   theindexFname* = "theindex.html"
