--- quisk.py.orig	2019-06-18 23:38:53 UTC
+++ quisk.py
@@ -23,6 +23,13 @@ os.chdir(os.path.normpath(os.path.dirnam
 if sys.path[0] != "'.'":		# Make sure the current working directory is on path
   sys.path.insert(0, '.')
 
+# Hack to ensure unicode is available.
+import locale
+locale.setlocale(locale.LC_ALL, '')
+cloc = locale.getdefaultlocale()
+if locale.nl_langinfo(locale.CODESET) != 'UTF-8':
+  locale.setlocale(locale.LC_ALL, (cloc[0], 'UTF-8'))
+
 import wx, wx.html, wx.lib.stattext, wx.lib.colourdb, wx.grid, wx.richtext
 import math, cmath, time, traceback, string, select, subprocess
 import threading, pickle, webbrowser
