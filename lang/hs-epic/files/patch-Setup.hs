--- Setup.hs.orig	2012-02-27 23:44:30.000000000 +0000
+++ Setup.hs	2013-12-08 15:39:13.067013368 +0000
@@ -1,10 +1,12 @@
 import Distribution.Simple
 import Distribution.Simple.InstallDirs
 import Distribution.Simple.LocalBuildInfo
-import Distribution.PackageDescription
+import Distribution.Simple.Setup
+import Distribution.PackageDescription hiding (Flag)
 
 import System.Exit
 import System.Process
+import System.FilePath.Posix
 
 -- After Epic is built, we need a run time system.
 
@@ -33,7 +35,14 @@
     = do let pfx = prefix (installDirTemplates local)
          system' $ "make -C evm install PREFIX=" ++ show pfx
 
+postCopyLib args flags desc local = do
+  let pfix = prefix (installDirTemplates local)
+  let (Flag (CopyTo destDir)) = copyDest flags
+  putStrLn $ "PREFIX=" ++ (show destDir </> show pfix)
+  system' $ "make -C evm install PREFIX=" ++ (destDir </> show pfix)
+
 main = defaultMainWithHooks (simpleUserHooks { postBuild = buildLib,
                                                postConf = postConfLib,
-                                               postInst = postInstLib })
+                                               postInst = postInstLib,
+                                               postCopy = postCopyLib })
 
