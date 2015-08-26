--- libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs.orig	2015-06-19 10:36:50 UTC
+++ libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs
@@ -261,10 +261,13 @@ alexProgram = (simpleProgram "alex") {
 gccProgram :: Program
 gccProgram = (simpleProgram "gcc") {
     programFindVersion = findProgramVersion "-dumpversion" id
+  , programFindLocation = \v p -> findProgramOnSearchPath v p "%%CC%%"
   }
 
 arProgram :: Program
-arProgram = simpleProgram "ar"
+arProgram = (simpleProgram "ar") {
+    programFindLocation = \_v _p -> return (Just "%%AR%%")
+  }
 
 stripProgram :: Program
 stripProgram = (simpleProgram "strip") {
@@ -336,7 +339,9 @@ greencardProgram :: Program
 greencardProgram = simpleProgram "greencard"
 
 ldProgram :: Program
-ldProgram = simpleProgram "ld"
+ldProgram = (simpleProgram "ld") {
+    programFindLocation = \_v _p -> return (Just "%%LD%%")
+  }
 
 tarProgram :: Program
 tarProgram = (simpleProgram "tar") {
