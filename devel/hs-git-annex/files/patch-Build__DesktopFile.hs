--- Build/DesktopFile.hs.orig	2019-06-26 16:31:40 UTC
+++ Build/DesktopFile.hs
@@ -20,6 +20,7 @@ import Config.Files
 import Utility.OSX
 import Assistant.Install.AutoStart
 import Assistant.Install.Menu
+import System.FilePath ((</>))
 
 import System.Environment
 import System.PosixCompat.User
@@ -48,13 +49,18 @@ writeFDODesktop :: FilePath -> IO ()
 writeFDODesktop command = do
 	systemwide <- systemwideInstall
 
-	datadir <- if systemwide then return systemDataDir else userDataDir
+	prefix <- catchMaybeIO (getEnv "PREFIX")
+	let (sddir,scdir) = case prefix of
+				Just p  -> (p </> "share", p </> "etc/xdg")
+				Nothing -> (systemDataDir, systemConfigDir)
+
+	datadir <- if systemwide then return sddir else userDataDir
 	menufile <- inDestDir (desktopMenuFilePath "git-annex" datadir)
 	icondir <- inDestDir (iconDir datadir)
 	installMenu command menufile "doc" icondir
 
-	configdir <- if systemwide then return systemConfigDir else userConfigDir
-	installAutoStart command 
+	configdir <- if systemwide then return scdir else userConfigDir
+	installAutoStart command
 		=<< inDestDir (autoStartPath "git-annex" configdir)
 
 writeOSXDesktop :: FilePath -> IO ()
