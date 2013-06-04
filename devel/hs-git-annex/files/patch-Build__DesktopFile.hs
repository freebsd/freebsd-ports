--- ./Build/DesktopFile.hs.orig	2013-05-03 05:20:19.000000000 +0200
+++ ./Build/DesktopFile.hs	2013-05-09 22:23:06.000000000 +0200
@@ -42,11 +42,15 @@
 
 writeFDODesktop :: FilePath -> IO ()
 writeFDODesktop command = do
-	datadir <- ifM systemwideInstall ( return systemDataDir, userDataDir )
+	prefix <- catchMaybeIO (getEnv "PREFIX")
+	let (sddir,scdir) = case prefix of
+			      Just p  -> (p </> "share", p </> "etc/xdg")
+			      Nothing -> (systemDataDir, systemConfigDir)
+	datadir <- ifM systemwideInstall ( return sddir, userDataDir )
 	installMenu command
 		=<< inDestDir (desktopMenuFilePath "git-annex" datadir)
 
-	configdir <- ifM systemwideInstall ( return systemConfigDir, userConfigDir )
+	configdir <- ifM systemwideInstall ( return scdir, userConfigDir )
 	installAutoStart command 
 		=<< inDestDir (autoStartPath "git-annex" configdir)
 
