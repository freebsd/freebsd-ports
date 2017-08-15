--- libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs.orig	2017-01-03 15:59:20 UTC
+++ libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs
@@ -54,6 +54,8 @@ import Distribution.Compat.Exception
 import Distribution.Verbosity
 import Distribution.Version
 
+import System.FilePath (takeDirectory)
+
 import Data.Char
          ( isDigit )
 import qualified Data.Map as Map
@@ -251,11 +253,13 @@ alexProgram = (simpleProgram "alex") {
 
 gccProgram :: Program
 gccProgram = (simpleProgram "gcc") {
-    programFindVersion = findProgramVersion "-dumpversion" id
-  }
+     programFindLocation = \v p -> findProgramOnSearchPath v p "%%CC%%"
+}
 
 arProgram :: Program
-arProgram = simpleProgram "ar"
+arProgram = (simpleProgram "ar") {
+     programFindLocation = \v p -> findProgramOnSearchPath v p "%%AR%%"
+}
 
 stripProgram :: Program
 stripProgram = (simpleProgram "strip") {
@@ -311,7 +315,9 @@ greencardProgram :: Program
 greencardProgram = simpleProgram "greencard"
 
 ldProgram :: Program
-ldProgram = simpleProgram "ld"
+ldProgram = (simpleProgram "ld") {
+    programFindLocation = \v p -> findProgramOnSearchPath v p "%%LD%%"
+  }
 
 tarProgram :: Program
 tarProgram = (simpleProgram "tar") {
