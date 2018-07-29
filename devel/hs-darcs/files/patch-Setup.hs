--- Setup.hs.orig       2018-07-17 19:45:58 UTC
+++ Setup.hs
@@ -17,7 +17,7 @@ import Distribution.Package
 import Distribution.Version( Version )
 import Distribution.Simple.LocalBuildInfo
          ( LocalBuildInfo(..), absoluteInstallDirs )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, CopyDest (NoCopyDest))
 import Distribution.Simple.Setup
     (buildVerbosity, copyDest, copyVerbosity, fromFlag,
      haddockVerbosity, installVerbosity, sDistVerbosity, replVerbosity )
@@ -145,7 +145,7 @@ installManpage :: PackageDescription -> LocalBuildInfo
                   -> Verbosity -> CopyDest -> IO ()
 installManpage pkg lbi verbosity copy =
     copyFiles verbosity
-              (mandir (absoluteInstallDirs pkg lbi copy) </> "man1")
+              (prefix (absoluteInstallDirs pkg lbi copy) </> "man" </> "man1")
               [(buildDir lbi </> "darcs", "darcs.1")]

 -- ---------------------------------------------------------------------
