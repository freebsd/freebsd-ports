--- sonata/main.py.orig	2013-08-03 13:13:21.000000000 +0200
+++ sonata/main.py	2013-08-03 13:14:12.000000000 +0200
@@ -3400,4 +3400,7 @@ class Base(object):
 		self.on_currsong_notify(force_popup=True)
 	
 	def main(self):
+		gtk.gdk.threads_init()
+		gtk.gdk.threads_enter()
 		gtk.main()
+		gtk.gdk.threads_leave()
