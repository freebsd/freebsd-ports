--- vnc2flv/rfb.py.orig	2010-01-18 06:19:13.000000000 -0800
+++ vnc2flv/rfb.py	2011-10-18 15:12:54.000000000 -0700
@@ -152,6 +152,8 @@
         if server_security == 0:
             return self.autherr()
         elif server_security == 1:
+            # send: always shared.
+            self.send('\x01');
             return self.start()
         else:
             return self.crauth()
