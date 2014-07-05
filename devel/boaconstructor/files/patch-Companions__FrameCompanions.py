--- ./Companions/FrameCompanions.py.orig	2014-07-05 20:19:37.550674426 -0300
+++ ./Companions/FrameCompanions.py	2014-07-05 20:19:46.427673184 -0300
@@ -188,7 +188,7 @@
         BaseFrameDTC.__init__(self, name, designer, frameCtrl)
         self.windowStyles = ['wx.DIALOG_MODAL', 'wx.DIALOG_MODELESS',
               'wx.CAPTION', 'wx.DEFAULT_DIALOG_STYLE', 'wx.RESIZE_BORDER',
-              'wx.THICK_FRAME', 'wx.STAY_ON_TOP', 'wx.NO_3D', 'wx.DIALOG_NO_PARENT',
+              'wx.THICK_FRAME', 'wx.STAY_ON_TOP', 'wx.DIALOG_NO_PARENT',
               'wx.SYSTEM_MENU', 'wx.CLOSE_BOX']\
               + self.windowStyles
 
