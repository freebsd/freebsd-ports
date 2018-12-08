--- libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs.orig   2017-11-28 16:40:34 UTC
+++ libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs
@@ -59,6 +59,8 @@ import Distribution.Compat.Exception
 import Distribution.Verbosity
 import Distribution.Version
 
+import System.FilePath (takeDirectory)
+
 import qualified Data.Map as Map
 
 -- ------------------------------------------------------------
@@ -265,11 +267,13 @@ alexProgram = (simpleProgram "alex") {
 
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
@@ -337,7 +341,9 @@ greencardProgram :: Program
 greencardProgram = simpleProgram "greencard"
 
 ldProgram :: Program
-ldProgram = simpleProgram "ld"
+ldProgram = (simpleProgram "ld") {
+    programFindLocation = \v p -> findProgramOnSearchPath v p "%%LD%%"
+  }
 
 tarProgram :: Program
 tarProgram = (simpleProgram "tar") {
