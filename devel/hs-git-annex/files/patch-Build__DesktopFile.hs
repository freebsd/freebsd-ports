--- Build/DesktopFile.hs.orig	2018-12-11 20:34:28 UTC
+++ Build/DesktopFile.hs
@@ -21,6 +21,7 @@ import Utility.OSX
 import Assistant.Install.AutoStart
 import Assistant.Install.Menu
 
+import System.FilePath ((</>))
 import System.Environment
 import System.PosixCompat.User
 import Data.Maybe
@@ -28,7 +29,7 @@ import Control.Applicative
 import Prelude
 
 systemwideInstall :: IO Bool
-#ifndef mingw32_HOST_OS 
+#ifndef mingw32_HOST_OS
 systemwideInstall = isroot <||> destdirset
   where
 	isroot = do
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
