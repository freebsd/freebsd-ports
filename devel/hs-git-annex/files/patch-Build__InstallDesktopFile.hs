--- ./Build/InstallDesktopFile.hs.orig	2012-10-17 03:24:57.000000000 +0200
+++ ./Build/InstallDesktopFile.hs	2012-11-06 11:26:23.567300019 +0100
@@ -59,11 +59,15 @@
 
 writeFDODesktop :: FilePath -> IO ()
 writeFDODesktop command = do
-	datadir <- ifM systemwideInstall ( return systemDataDir, userDataDir )
+	prefix <- catchMaybeIO (getEnv "PREFIX")
+	let (sddir,scdir) = case prefix of
+	                      Just p  -> (p </> "share", p </> "etc/xdg")
+	                      Nothing -> (systemDataDir, systemConfigDir)
+	datadir <- ifM systemwideInstall ( return sddir, userDataDir )
 	writeDesktopMenuFile (desktop command) 
 		=<< inDestDir (desktopMenuFilePath "git-annex" datadir)
 
-	configdir <- ifM systemwideInstall ( return systemConfigDir, userConfigDir )
+	configdir <- ifM systemwideInstall ( return scdir, userConfigDir )
 	installAutoStart command 
 		=<< inDestDir (autoStartPath "git-annex" configdir)
 
