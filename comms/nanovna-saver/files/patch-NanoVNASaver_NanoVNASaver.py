--- NanoVNASaver/NanoVNASaver.py.orig	2019-12-04 11:05:36 UTC
+++ NanoVNASaver/NanoVNASaver.py
@@ -540,11 +540,7 @@ class NanoVNASaver(QtWidgets.QWidget):
         return_ports = []
         device_list = list_ports.comports()
         for d in device_list:
-            if (d.vid == VID and
-                    d.pid == PID):
-                port = d.device
-                logger.info("Found NanoVNA (%04x %04x) on port %s", d.vid, d.pid, d.device)
-                return_ports.append(port)
+            return_ports.append(d.device)
         return return_ports
 
     def exportFileS1P(self):
