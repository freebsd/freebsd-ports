--- mirage.py.orig	2013-04-10 19:04:47.000000000 +0200
+++ mirage.py	2013-04-10 19:05:50.000000000 +0200
@@ -1,3 +1,4 @@
+#!/usr/bin/python2
 # $HeadURL: http://svn.berlios.de/svnroot/repos/mirageiv/branches/mirage-0.9.x/mirage.py $
 # $Id: mirage.py 337 2011-02-13 22:40:05Z fredricj $
 
@@ -4575,10 +4576,10 @@
 				timer_screensaver = gobject.timeout_add(1000, self.disable_screensaver_in_slideshow_mode)
 
 	def main(self):
+		gtk.gdk.threads_enter()
 		gtk.main()
+		gtk.gdk.threads_leave()
 
 if __name__ == "__main__":
 	base = Base()
-	gtk.gdk.threads_enter()
 	base.main()
-	gtk.gdk.threads_leave()
