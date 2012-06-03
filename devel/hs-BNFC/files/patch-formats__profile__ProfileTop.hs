--- ./formats/profile/ProfileTop.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./formats/profile/ProfileTop.hs	2012-05-13 12:25:17.510460618 +0200
@@ -37,7 +37,7 @@
 import Utils
 
 import Char
-import System
+import System.Exit
 import Monad(when)
 
 -- naming conventions
@@ -184,8 +184,8 @@
 	         "",
                  "import Trees",
                  "import Profile",
-	         "import IO ( stdin, hGetContents )",
-	         "import System ( getArgs, getProgName )",
+	         "import System.IO ( stdin, hGetContents )",
+	         "import System.Environment ( getArgs, getProgName )",
 		 "",
 		 "import " ++ alexFileM     inDir name,
 		 "import " ++ happyFileM    inDir name,
