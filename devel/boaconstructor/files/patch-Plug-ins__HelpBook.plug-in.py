--- ./Plug-ins/HelpBook.plug-in.py.orig	2014-07-05 20:18:17.816680866 -0300
+++ ./Plug-ins/HelpBook.plug-in.py	2014-07-05 20:19:04.452676278 -0300
@@ -683,7 +683,7 @@
     delBmp = 'Images/Shared/DeleteItem.png'
     def __init__(self, parent, model):
         wx.SplitterWindow.__init__(self, parent, -1,
-              style=wx.CLIP_CHILDREN | wx.NO_3D | wx.SP_3DSASH)
+              style=wx.CLIP_CHILDREN | wx.SP_3DSASH)
 
         self.indexes = HelpBookIndexListView(self, model, self)
         self.files = HelpBookFilesView(self, model, False)
@@ -854,7 +854,7 @@
     delBmp = 'Images/Shared/DeleteItem.png'
     def __init__(self, parent, model):
         wx.SplitterWindow.__init__(self, parent, -1,
-              style=wx.CLIP_CHILDREN | wx.NO_3D | wx.SP_3DSASH)
+              style=wx.CLIP_CHILDREN | wx.SP_3DSASH)
 
         self.contents = HelpBookContentsTreeView(self, model, self)
         self.files = HelpBookFilesView(self, model, False)
