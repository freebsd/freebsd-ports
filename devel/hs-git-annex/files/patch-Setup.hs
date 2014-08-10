--- ./Setup.hs.orig	2014-01-22 21:23:18.000000000 +0100
+++ ./Setup.hs	2014-07-10 21:52:00.000000000 +0200
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
@@ -60,4 +70,4 @@
 installDesktopFile copyDest verbosity pkg lbi =
 	DesktopFile.install $ dstBinDir </> "git-annex"
   where
-	dstBinDir = bindir $ absoluteInstallDirs pkg lbi copyDest
+	dstBinDir = bindir $ absoluteInstallDirs pkg lbi NoCopyDest
