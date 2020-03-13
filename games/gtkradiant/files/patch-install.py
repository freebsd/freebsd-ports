--- ./install.py.orig	Sun Feb 12 16:47:01 2006
+++ ./install.py	Thu Mar 16 16:09:46 2006
@@ -38,7 +38,7 @@
   targetFile = target
   if os.path.isdir(targetFile):
     targetFile = os.path.join(target, os.path.basename(source))
-  print source, "->", targetFile
+  print(source, "->", targetFile)
   shutil.copyfile(source, targetFile)
   
 def copyFileIfExists(source, target):
@@ -98,8 +98,6 @@
 ]
 
 # copy games
-for game in games:
-  copyGame(gamesRoot, game, installRoot)
 
 # copy win32 dlls
 gtk2Root = os.path.normpath(os.path.join(thisDir, "../gtk2-2.4"))
