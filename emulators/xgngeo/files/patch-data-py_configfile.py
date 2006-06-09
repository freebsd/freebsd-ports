--- data/py/configfile.py	Thu Jul 14 13:48:58 2005
+++ data/py/configfile.py	Fri Apr 14 01:25:46 2006
@@ -33,7 +33,7 @@
 as the `gngeorc'."""
 
 	def __init__(self):
-		self.xgngeoconfPath = "data/xgngeo.conf" #Path to XGngeo config file.
+		self.xgngeoconfPath =  os.path.join(os.getenv("HOME"),".gngeo/xgngeo.conf") #Path to XGngeo config file.
 		self.gngeoDir = os.path.expanduser("~/.gngeo") #Gngeo local configuration directory.
 		self.gngeorcPath = os.path.join(self.gngeoDir,"gngeorc") #Path to Gngeo config file.
 
@@ -42,9 +42,9 @@
 		and XGngeo configuration files."""
 		return { #Gngeo default.
 			#Path
-			"libglpath":"/usr/lib/libGL.so",
+			"libglpath":"%%X11BASE%%/lib/libGL.so",
 			"rompath": os.path.join(os.getenv("HOME"),"..."),
-			"romrc":"/usr/local/share/gngeo/romrc",
+			"romrc":"%%X11BASE%%/share/gngeo/romrc",
 			#Graphic
 			"blitter":"soft",
 			"effect":"none",
@@ -74,7 +74,7 @@
 			"previewimages":"false",
 			"previewimagedir":"data/previewimages/",
 			"rominfos":"true",
-			"rominfoxml":"data/rominfos.xml",
+			"rominfoxml":"%%DATADIR%%/rominfos.xml",
 			"showavailableromsonly":"true"
 			}
 
