--- chirp/platform.py.orig	2012-09-07 19:08:30.000000000 -0500
+++ chirp/platform.py	2012-09-17 09:48:00.000000000 -0500
@@ -246,6 +246,9 @@
 
     def list_serial_ports(self):
         return sorted(glob.glob("/dev/ttyS*") +
+		      glob.glob("/dev/tty*") +
+		      glob.glob("/dev/cu*") +
+		      glob.glob("/dev/ttyU*") +
                       glob.glob("/dev/ttyUSB*") +
                       glob.glob("/dev/cu.*") +
                       glob.glob("/dev/term/*") +
