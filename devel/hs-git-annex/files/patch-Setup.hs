--- Setup.hs.orig	2013-08-27 21:23:35.000000000 +0100
+++ Setup.hs	2013-12-08 17:28:34.656382191 +0000
@@ -19,6 +19,7 @@
 main = defaultMainWithHooks simpleUserHooks
 	{ preConf = configure
 	, postInst = myPostInst
+	, postCopy = myPostCopy
 	}
 
 configure _ _ = do
@@ -34,6 +35,15 @@
 	dest      = NoCopyDest
 	verbosity = fromFlag installVerbosity
 
+myPostCopy :: Args -> CopyFlags -> PackageDescription -> LocalBuildInfo -> IO ()
+myPostCopy _ (CopyFlags { copyVerbosity, copyDest }) pkg lbi = do
+	installGitAnnexShell dest verbosity pkg lbi
+	installManpages      dest verbosity pkg lbi
+	installDesktopFile   dest verbosity pkg lbi
+  where
+	dest      = fromFlag copyDest
+	verbosity = fromFlag copyVerbosity
+
 installGitAnnexShell :: CopyDest -> Verbosity -> PackageDescription -> LocalBuildInfo -> IO ()
 installGitAnnexShell copyDest verbosity pkg lbi =
 	rawSystemExit verbosity "ln"
@@ -50,7 +60,7 @@
 installManpages copyDest verbosity pkg lbi =
 	installOrdinaryFiles verbosity dstManDir =<< srcManpages
   where
-	dstManDir   = mandir (absoluteInstallDirs pkg lbi copyDest) </> "man1"
+	dstManDir   = prefix (absoluteInstallDirs pkg lbi copyDest) </> "man" </> "man1"
 	srcManpages = zip (repeat srcManDir)
 		<$> filterM doesFileExist manpages
 	srcManDir   = ""
