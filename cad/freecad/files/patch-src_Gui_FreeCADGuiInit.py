--- ./src/Gui/FreeCADGuiInit.py.orig	Sat Feb 24 11:41:26 2007
+++ ./src/Gui/FreeCADGuiInit.py	Sun Apr 29 10:08:42 2007
@@ -31,7 +31,7 @@
 
 
 # imports the one and only
-import FreeCAD, FreeCADGui
+import FreeCAD, FreeCADGui, sys
 
 # shortcuts
 Gui = FreeCADGui
@@ -83,6 +83,8 @@
 	#print FreeCAD.ConfigGet("HomePath")
 	if os.path.isdir(FreeCAD.ConfigGet("HomePath")+'Mod'):
 		ModDir = FreeCAD.ConfigGet("HomePath")+'Mod'
+	elif sys.platform[:7] == 'freebsd':
+		ModDir = '/usr/local/share/FreeCAD/Mod'
 	else:
 		if os.path.isdir(FreeCAD.ConfigGet("HomePath")+'src\\Mod'):
 			ModDir = FreeCAD.ConfigGet("HomePath")+'src\\Mod'
