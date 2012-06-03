--- ./formats/c-sharp/CSharpTop.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./formats/c-sharp/CSharpTop.hs	2012-05-13 12:13:16.373594632 +0200
@@ -48,10 +48,10 @@
 import CFtoCSharpPrinter
 import CFtoLatex
 import CSharpUtils
-import System
 import GetCF
 import Char
-import System
+import System.Exit
+import System.Environment
 import System.Directory
 import System.IO
 import System.Process
