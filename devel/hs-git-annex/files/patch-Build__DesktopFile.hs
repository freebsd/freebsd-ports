--- Build/DesktopFile.hs.orig	2017-06-12 17:56:05 UTC
+++ Build/DesktopFile.hs
@@ -25,6 +25,7 @@ import System.Environment
 #ifndef mingw32_HOST_OS
 import System.Posix.User
 #endif
+import System.FilePath.Posix
 import Data.Maybe
 import Control.Applicative
 import Prelude
@@ -50,12 +51,17 @@ writeFDODesktop :: FilePath -> IO ()
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
 
