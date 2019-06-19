--- quisk_widgets.py.orig	2019-06-19 06:35:39 UTC
+++ quisk_widgets.py
@@ -248,7 +248,16 @@ class SliderBoxH:
     else:
       self.text_ctrl = wx.StaticText(parent, -1, t, pos=pos)
       w2, h2 = self.text_ctrl.GetSize()
-      self.slider = wx.Slider(parent, -1, init, themin, themax, (pos[0] + w2, pos[1]), (width - w2, h2))
+      self.slider = wx.Slider(parent, -1, init, themin, themax)
+      w3, h3 = self.slider.GetSize()
+      p2 = pos[1]
+      if h3 > h2:
+        p2 -= (h3 - h2) / 2
+        h2 = h3
+      else:
+        p2 += (h2 - h3) / 2
+      self.slider.SetSize((width - w2, h2))
+      self.slider.SetPosition((pos[0] + w2, p2))
     self.slider.Bind(wx.EVT_SCROLL, self.OnScroll)
     self.text_ctrl.SetForegroundColour(parent.GetForegroundColour())
     self.OnScroll()
