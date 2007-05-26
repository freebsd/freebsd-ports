--- ./src/App/FreeCADInit.py.orig	Sat Feb 24 11:35:04 2007
+++ ./src/App/FreeCADInit.py	Sun Apr 29 10:04:04 2007
@@ -52,6 +52,8 @@
 	#print FreeCAD.ConfigGet("HomePath")
 	if os.path.isdir(FreeCAD.ConfigGet("HomePath")+'Mod'):
 		ModDir = FreeCAD.ConfigGet("HomePath")+'Mod'
+	elif sys.platform[:7] == 'freebsd':
+		ModDir = '/usr/local/share/FreeCAD/Mod'
 	else:
 		if os.path.isdir(FreeCAD.ConfigGet("HomePath")+'src\\Mod'):
 			ModDir = FreeCAD.ConfigGet("HomePath")+'src\\Mod'
