--- drFileDialog.py.orig	2015-07-19 21:30:17 UTC
+++ drFileDialog.py
@@ -1026,8 +1026,8 @@ class drWxFileDialog(wx.FileDialog):
 def FileDialog(parent, title, wildcard, point=(0, 0), size=wx.DefaultSize, IsASaveDialog=0, MultipleSelection=0, ShowRecentFiles=0):
         if parent.prefs.usewxfiledialog:
             if IsASaveDialog:
-                return drWxFileDialog(parent, title, "", "", wildcard, wx.SAVE|wx.HIDE_READONLY|wx.OVERWRITE_PROMPT)
+                return drWxFileDialog(parent, title, "", "", wildcard, wx.FD_SAVE|wx.FD_OVERWRITE_PROMPT)
             else:
-                return drWxFileDialog(parent, title, "", "", wildcard, wx.OPEN|wx.HIDE_READONLY|wx.MULTIPLE)
+                return drWxFileDialog(parent, title, "", "", wildcard, wx.FD_OPEN|wx.FD_MULTIPLE)
         else:
             return drFileDialog(parent, title, wildcard, point, size, IsASaveDialog, MultipleSelection, ShowRecentFiles)
