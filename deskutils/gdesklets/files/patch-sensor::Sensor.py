# Yay! Many thanks to Franz Klammer <klammer@webonaut.com>,
# the theads is now work. That make a lot of desklets work now.

--- sensor/Sensor.py.orig	Tue Nov 18 13:32:10 2003
+++ sensor/Sensor.py	Tue Nov 18 13:33:39 2003
@@ -346,3 +346,7 @@
     def __on_quit(self, src):
 
         gtk.main_quit()
+
+
+# FreeBSD needs this; Linux doesn't but it's cleaner to use it
+gtk.threads_init()
