--- ./formats/java/JavaTop.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./formats/java/JavaTop.hs	2012-05-13 12:22:38.512466534 +0200
@@ -38,7 +38,7 @@
 -- Dependencies.
 -------------------------------------------------------------------
 import Directory	( createDirectory )
-import IO		( try, isAlreadyExistsError )
+import System.IO.Error		( try, isAlreadyExistsError )
 
 import Utils
 import CF
@@ -49,7 +49,7 @@
 import CFtoJavaSkeleton
 import CFtoVisitSkel
 import CFtoLatex
-import System
+import System.Exit
 import GetCF		( tryReadCF, writeFileRep )
 import Char
 import List(intersperse)
