--- ./Build/DesktopFile.hs.orig	2014-07-09 22:09:05.000000000 +0200
+++ ./Build/DesktopFile.hs	2014-07-13 01:40:51.000000000 +0200
@@ -25,6 +25,7 @@
 #ifndef mingw32_HOST_OS
 import System.Posix.User
 #endif
+import System.FilePath.Posix
 import Data.Maybe
 
 systemwideInstall :: IO Bool
@@ -48,12 +49,17 @@
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
+	configdir <- if systemwide then return scdir else userConfigDir
 	installAutoStart command 
 		=<< inDestDir (autoStartPath "git-annex" configdir)
 
