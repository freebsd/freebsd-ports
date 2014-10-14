--- chirp/platform.py.orig	2013-04-09 03:01:35.000000000 -0400
+++ chirp/platform.py	2014-10-14 17:06:48.000000000 -0400
@@ -284,6 +284,7 @@
 
     def list_serial_ports(self):
         ports = ["/dev/ttyS*",
+                 "/dev/tty*",
                  "/dev/ttyUSB*",
                  "/dev/ttyAMA*",
                  "/dev/cu.*",
