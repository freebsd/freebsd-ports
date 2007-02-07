--- gimmie/gimmie_gui.py.orig	Tue Feb  6 19:59:13 2007
+++ gimmie/gimmie_gui.py	Tue Feb  6 19:59:39 2007
@@ -234,6 +234,8 @@
         self.tooltip.add(content)
 
 	screen = self.widget.get_screen()
+	if self.widget.window is None:
+		return
 	x, y = self.widget.window.get_origin()
 
 	rect = self.widget.allocation
