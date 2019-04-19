--- quisk.py.orig	2019-04-19 15:47:26 UTC
+++ quisk.py
@@ -21,6 +21,13 @@ os.chdir(os.path.normpath(os.path.dirnam
 if sys.path[0] != "'.'":		# Make sure the current working directory is on path
   sys.path.insert(0, '.')
 
+# Hack to ensure unicode is available.
+import locale
+locale.setlocale(locale.LC_ALL, '')
+cloc = locale.getdefaultlocale()
+if locale.nl_langinfo(locale.CODESET) != 'UTF-8':
+  locale.setlocale(locale.LC_ALL, (cloc[0], 'UTF-8'))
+
 import wx, wx.html, wx.lib.buttons, wx.lib.stattext, wx.lib.colourdb, wx.grid, wx.richtext
 import math, cmath, time, traceback, string, select, subprocess
 import threading, pickle, webbrowser
