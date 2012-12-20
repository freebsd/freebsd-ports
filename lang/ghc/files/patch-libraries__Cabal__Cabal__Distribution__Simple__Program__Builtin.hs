--- ./libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs.orig	2012-11-23 17:07:58.000000000 +0100
+++ ./libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs	2012-11-23 19:17:52.000000000 +0100
@@ -46,7 +46,7 @@
   ) where
 
 import Distribution.Simple.Program.Types
-         ( Program(..), simpleProgram )
+         ( Program(..), simpleProgram, simpleProgramFromEnvironment )
 import Distribution.Simple.Utils
          ( findProgramLocation, findProgramVersion )
 
@@ -194,15 +194,15 @@
   }
 
 gccProgram :: Program
-gccProgram = (simpleProgram "gcc") {
+gccProgram = (simpleProgramFromEnvironment "gcc" "CC") {
     programFindVersion = findProgramVersion "-dumpversion" id
   }
 
 ranlibProgram :: Program
-ranlibProgram = simpleProgram "ranlib"
+ranlibProgram = simpleProgramFromEnvironment "ranlib" "RANLIB"
 
 arProgram :: Program
-arProgram = simpleProgram "ar"
+arProgram = simpleProgramFromEnvironment "ar" "AR"
 
 stripProgram :: Program
 stripProgram = simpleProgram "strip"
@@ -255,13 +255,13 @@
 greencardProgram = simpleProgram "greencard"
 
 ldProgram :: Program
-ldProgram = simpleProgram "ld"
+ldProgram = simpleProgramFromEnvironment "ld" "LD"
 
 tarProgram :: Program
 tarProgram = simpleProgram "tar"
 
 cppProgram :: Program
-cppProgram = simpleProgram "cpp"
+cppProgram = simpleProgramFromEnvironment "cpp" "CPP"
 
 pkgConfigProgram :: Program
 pkgConfigProgram = (simpleProgram "pkg-config") {
