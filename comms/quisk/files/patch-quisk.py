--- quisk.py.orig	2018-11-23 17:50:38 UTC
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
@@ -3609,9 +3616,9 @@ class App(wx.App):
     self.file_play_timer = 0
     self.file_play_source = 0	# 10 == play audio file, 11 == play I/Q sample file, 12 == play CQ message
     # get the screen size - thanks to Lucian Langa
-    x1, y1, x2, y2 = wx.Display().GetGeometry()
-    self.screen_width = x2 - x1
-    self.screen_height = y2 - y1
+    dispGeo = wx.Display().GetGeometry()
+    self.screen_width = dispGeo.width
+    self.screen_height = dispGeo.height
     self.Bind(wx.EVT_IDLE, self.OnIdle)
     self.Bind(wx.EVT_QUERY_END_SESSION, self.OnEndSession)
     # Restore persistent program state
