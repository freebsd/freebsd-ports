# Yay! Many thanks to Franz Klammer <klammer@webonaut.com>,
# the theads is now work. That make a lot of desklets work now.

--- sensor/Sensor.py.orig	Mon Nov 17 16:46:57 2003
+++ sensor/Sensor.py	Mon Nov 17 16:48:43 2003
@@ -134,6 +134,8 @@
     #
     def _add_thread(self, threadfunction, *args):
 
+        gtk.threads_init()
+
         # the thread should not start before setup is complete, therefore
         # we are using the GTK idle handler
         def run_thread(threadfunction, args):
