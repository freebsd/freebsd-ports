--- ./Setup.lhs.orig	2010-05-09 15:23:32.000000000 +0200
+++ ./Setup.lhs	2010-05-15 13:37:00.000000000 +0200
@@ -17,7 +17,7 @@
          ( Version(versionBranch) )
 import Distribution.Simple.LocalBuildInfo
          ( LocalBuildInfo(..), absoluteInstallDirs )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, CopyDest (NoCopyDest))
 import Distribution.Simple.Setup
     (buildVerbosity, copyDest, copyVerbosity, fromFlag,
      haddockVerbosity, installVerbosity, sDistVerbosity)
@@ -168,7 +168,7 @@
                   -> Verbosity -> CopyDest -> IO ()
 installManpage pkg lbi verbosity copy =
     copyFiles verbosity
-              (mandir (absoluteInstallDirs pkg lbi copy) </> "man1")
+              (prefix (absoluteInstallDirs pkg lbi copy) </> "man/man1")
               [(buildDir lbi </> "darcs", "darcs.1")]
 
 determineVersion :: Verbosity -> PackageDescription -> IO (String, String)
