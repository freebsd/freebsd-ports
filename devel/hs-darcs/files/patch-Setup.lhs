--- Setup.lhs.orig	2017-01-11 20:07:29 UTC
+++ Setup.lhs
@@ -26,7 +26,7 @@ import Distribution.Version
 import Data.Version( showVersion )
 import Distribution.Simple.LocalBuildInfo
          ( LocalBuildInfo(..), absoluteInstallDirs, externalPackageDeps )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, CopyDest (NoCopyDest))
 import Distribution.Simple.PackageIndex ( topologicalOrder )
 import Distribution.Simple.Program ( gccProgram, rawSystemProgramStdoutConf )
 import Distribution.Simple.Setup
@@ -217,7 +217,7 @@ installManpage :: PackageDescription -> LocalBuildInfo
                   -> Verbosity -> CopyDest -> IO ()
 installManpage pkg lbi verbosity copy =
     copyFiles verbosity
-              (mandir (absoluteInstallDirs pkg lbi copy) </> "man1")
+              (prefix (absoluteInstallDirs pkg lbi copy) </> "man" </> "man1")
               [(buildDir lbi </> "darcs", "darcs.1")]
 
 -- ---------------------------------------------------------------------
