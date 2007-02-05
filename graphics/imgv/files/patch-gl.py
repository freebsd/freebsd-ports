--- gl.py.orig	Sat Oct 28 20:58:44 2006
+++ gl.py	Sat Feb  3 11:39:15 2007
@@ -9,6 +9,7 @@
 from res import my_toggle_fullscreen
 from pygame import version
 
+os.environ['IMGV_HOME'] = '%%DATADIR%%'
 
 BASE_DIR = os.getcwd()
 try:
