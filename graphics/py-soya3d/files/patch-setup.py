--- setup.py.orig	Sun May 13 10:54:49 2007
+++ setup.py	Fri Aug 17 16:32:16 2007
@@ -129,6 +129,7 @@
 		DEFINES.append(('SOYA_MACOSX',1))
 	else:
 		LIBS.append("openal")
+		LIBS.append("alut")
 
 
 if "darwin" in sys.platform:
