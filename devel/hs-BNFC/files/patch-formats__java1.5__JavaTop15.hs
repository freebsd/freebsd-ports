--- ./formats/java1.5/JavaTop15.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./formats/java1.5/JavaTop15.hs	2012-05-13 12:20:30.194507156 +0200
@@ -39,7 +39,7 @@
 -- Dependencies.
 -------------------------------------------------------------------
 import Directory	( createDirectory )
-import IO		( try, isAlreadyExistsError )
+import System.IO.Error		( try, isAlreadyExistsError )
 
 import Utils
 import CF
@@ -54,7 +54,7 @@
 import CFtoFoldVisitor
 import CFtoAllVisitor
 import CFtoLatex
-import System
+import System.Exit
 import GetCF		( tryReadCF, writeFileRep )
 import Char
 import List(intersperse)
