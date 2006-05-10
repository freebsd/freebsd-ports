--- ./install.py.orig	Sun Feb 12 16:47:01 2006
+++ ./install.py	Thu Mar 16 16:09:46 2006
@@ -98,8 +98,6 @@
 ]
 
 # copy games
-for game in games:
-  copyGame(gamesRoot, game, installRoot)
 
 # copy win32 dlls
 gtk2Root = os.path.normpath(os.path.join(thisDir, "../gtk2-2.4"))
