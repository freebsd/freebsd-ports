--- Setup.hs.orig	2015-07-27 16:25:52 UTC
+++ Setup.hs
@@ -23,6 +23,7 @@ main = defaultMainWithHooks simpleUserHo
 		Configure.run Configure.tests
 		return (Nothing, [])	
 	, postInst = myPostInst
+	, postCopy = myPostCopy
 	}
 
 myPostInst :: Args -> InstallFlags -> PackageDescription -> LocalBuildInfo -> IO ()
@@ -34,6 +35,15 @@ myPostInst _ (InstallFlags { installVerb
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
@@ -50,14 +60,14 @@ installManpages :: CopyDest -> Verbosity
 installManpages copyDest verbosity pkg lbi =
 	installOrdinaryFiles verbosity dstManDir =<< srcManpages
   where
-	dstManDir   = mandir (absoluteInstallDirs pkg lbi copyDest) </> "man1"
+	dstManDir   = prefix (absoluteInstallDirs pkg lbi copyDest) </> "man" </> "man1"
 	srcManpages = zip (repeat srcManDir)
-		<$> filterM doesFileExist manpages
-	srcManDir   = ""
+		<$> filterM (doesFileExist . (srcManDir </>)) manpages
+	srcManDir   = "man"
 	manpages    = ["git-annex.1", "git-annex-shell.1"]
 
 installDesktopFile :: CopyDest -> Verbosity -> PackageDescription -> LocalBuildInfo -> IO ()
 installDesktopFile copyDest _verbosity pkg lbi =
 	DesktopFile.install $ dstBinDir </> "git-annex"
   where
-	dstBinDir = bindir $ absoluteInstallDirs pkg lbi copyDest
+	dstBinDir = bindir $ absoluteInstallDirs pkg lbi NoCopyDest
