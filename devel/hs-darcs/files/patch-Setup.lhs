--- ./Setup.lhs.orig	2013-02-06 07:07:21.000000000 +0100
+++ ./Setup.lhs	2014-07-13 22:44:31.000000000 +0200
@@ -26,7 +26,7 @@
 import Data.Version( showVersion )
 import Distribution.Simple.LocalBuildInfo
          ( LocalBuildInfo(..), absoluteInstallDirs, externalPackageDeps )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, CopyDest (NoCopyDest))
 import Distribution.Simple.PackageIndex ( topologicalOrder )
 import Distribution.Simple.Program ( gccProgram, rawSystemProgramStdoutConf )
 import Distribution.Simple.Setup
@@ -200,7 +200,7 @@
                   -> Verbosity -> CopyDest -> IO ()
 installManpage pkg lbi verbosity copy =
     copyFiles verbosity
-              (mandir (absoluteInstallDirs pkg lbi copy) </> "man1")
+              (prefix (absoluteInstallDirs pkg lbi copy) </> "man" </> "man1")
               [(buildDir lbi </> "darcs", "darcs.1")]
 
 determineVersion :: Verbosity -> PackageDescription -> IO (String, String)
