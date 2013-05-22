--- mirage.py.orig	2011-02-13 23:40:05.000000000 +0100
+++ mirage.py	2013-05-22 17:56:33.000000000 +0200
@@ -71,7 +71,7 @@
 
 	def __init__(self):
 		
-		gtk.gdk.threads_init()
+		#gtk.gdk.threads_init()
 		
 		# FIX THIS! Does not work on windows and what happens if mo-files exists
 		# in both dirs?
@@ -841,9 +841,7 @@
 			self.thumbpane_bottom_coord_loaded = bottom_coord
 		# update images:
 		if not self.thumbpane_updating:
-			thread = threading.Thread(target=self.thumbpane_update_pending_images, args=(force_upto_imgnum, None))
-			thread.setDaemon(True)
-			thread.start()
+			self.thumbpane_update_pending_images(force_upto_imgnum, None)
 
 	def thumbpane_create_dir(self):
 		if not os.path.exists(os.path.expanduser('~/.thumbnails/')):
@@ -4579,6 +4577,6 @@
 
 if __name__ == "__main__":
 	base = Base()
-	gtk.gdk.threads_enter()
+	#gtk.gdk.threads_enter()
 	base.main()
-	gtk.gdk.threads_leave()
+	#gtk.gdk.threads_leave()
