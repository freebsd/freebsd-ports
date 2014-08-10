--- ./libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs.orig	2014-07-10 06:34:21.000000000 +0200
+++ ./libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs	2014-07-26 23:57:20.869626927 +0200
@@ -198,13 +198,18 @@
 gccProgram :: Program
 gccProgram = (simpleProgram "gcc") {
     programFindVersion = findProgramVersion "-dumpversion" id
+  , programFindLocation = \v p -> findProgramOnSearchPath v p "%%CC%%"
   }
 
 ranlibProgram :: Program
-ranlibProgram = simpleProgram "ranlib"
+ranlibProgram = (simpleProgram "ranlib") {
+    programFindLocation = \_v _p -> return (Just "%%RANLIB%%")
+  }
 
 arProgram :: Program
-arProgram = simpleProgram "ar"
+arProgram = (simpleProgram "ar") {
+    programFindLocation = \_v _p -> return (Just "%%AR%%")
+  }
 
 stripProgram :: Program
 stripProgram = simpleProgram "strip"
@@ -257,7 +262,9 @@
 greencardProgram = simpleProgram "greencard"
 
 ldProgram :: Program
-ldProgram = simpleProgram "ld"
+ldProgram = (simpleProgram "ld") {
+    programFindLocation = \_v _p -> return (Just "%%LD%%")
+  }
 
 tarProgram :: Program
 tarProgram = simpleProgram "tar"
