--- sonata/main.py.orig	2009-09-21 23:02:16.000000000 +0200
+++ sonata/main.py	2013-12-21 09:55:28.000000000 +0100
@@ -989,13 +989,14 @@
 						self.repeatmenu.set_active(self.status['repeat'] == '1')
 					if not self.last_random or self.last_random != self.status['random']:
 						self.randommenu.set_active(self.status['random'] == '1')
-					if self.status['xfade'] == '0':
-						self.config.xfade_enabled = False
-					else:
-						self.config.xfade_enabled = True
-						self.config.xfade = int(self.status['xfade'])
-						if self.config.xfade > 30:
-							self.config.xfade = 30
+					self.config.xfade_enabled = False
+					if 'xfade' in self.status:
+						xfade = int(self.status['xfade'])
+						if xfade != 0:
+							self.config.xfade_enabled = True
+							self.config.xfade = xfade
+							if self.config.xfade > 30:
+								self.config.xfade = 30
 					self.last_repeat = self.status['repeat']
 					self.last_random = self.status['random']
 					return
@@ -3400,4 +3401,7 @@
 		self.on_currsong_notify(force_popup=True)
 	
 	def main(self):
+		gtk.gdk.threads_init()
+		gtk.gdk.threads_enter()
 		gtk.main()
+		gtk.gdk.threads_leave()
