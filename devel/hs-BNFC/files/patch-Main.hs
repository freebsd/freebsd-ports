--- Main.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ Main.hs	2012-05-13 12:32:42.198463500 +0200
@@ -41,8 +41,9 @@
 
 import MultiView (preprocessMCF, mkTestMulti, mkMakefileMulti)
 
-import System
 import System.Exit
+import System.Environment
+import System.Process
 import Char
 import Data.List (elemIndex)
 
