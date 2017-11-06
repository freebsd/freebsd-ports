--- chirp/platform.py.orig	2017-02-07 08:01:12 UTC
+++ chirp/platform.py
@@ -317,6 +317,7 @@ class UnixPlatform(Platform):
 
     def list_serial_ports(self):
         ports = ["/dev/ttyS*",
+                 "/dev/tty*",
                  "/dev/ttyUSB*",
                  "/dev/ttyAMA*",
                  "/dev/ttyACM*",
