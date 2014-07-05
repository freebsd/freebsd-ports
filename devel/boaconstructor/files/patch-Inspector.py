--- ./Inspector.py.orig	2014-07-05 20:17:27.633683705 -0300
+++ ./Inspector.py	2014-07-05 20:17:36.358682355 -0300
@@ -871,7 +871,7 @@
           style = Preferences.splitterStyle)
 
         self.categories = wx.SplitterWindow(self, -1,
-              style=wx.NO_3D | wx.SP_3D | wx.SP_LIVE_UPDATE)
+              style=wx.SP_3D | wx.SP_LIVE_UPDATE)
         self.definitions = InspectorEventScrollWin(self, -1,
               style=wx.SUNKEN_BORDER | wx.TAB_TRAVERSAL)
 
