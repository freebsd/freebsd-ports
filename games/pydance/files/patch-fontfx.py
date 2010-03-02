--- fontfx.py.orig	2008-12-30 13:04:11.000000000 -0200
+++ fontfx.py	2010-02-05 23:37:31.000000000 -0200
@@ -141,7 +141,7 @@
     self.bgcolor = bgcolor
     self.offcolor = [c^40 for c in color]
     self.notcolor = [c^0xFF for c in color]
-    self.text = font.render(message, False, [255, 0, 0], self.notcolor)
+    self.text = font.render(message, True, [255, 0, 0], self.notcolor)
     self.text.set_colorkey(1, RLEACCEL)
     self.outline = self.textHollow(font, message, color)
     self.bar = pygame.Surface(self.text.get_size())
@@ -152,7 +152,7 @@
     self.ratio = width / 100.0
 
   def textHollow(self, font, message, fontcolor):
-    base = font.render(message, False, fontcolor, self.notcolor)
+    base = font.render(message, True, fontcolor, self.notcolor)
     size = base.get_width() + 2, base.get_height() + 2
     img = pygame.Surface(size, 16)
     img.fill(self.notcolor)
