--- indiweb/driver.py	2021-09-05 00:47:09.163136000 -0500
+++ indiweb/driver.py	2021-09-05 00:47:30.642233000 -0500
@@ -5,7 +5,7 @@
 import xml.etree.ElementTree as ET
 
 # Default INDI data directory
-INDI_DATA_DIR = "/usr/share/indi/"
+INDI_DATA_DIR = "%%LOCALBASE%%/share/indi/"
 
 
 class DeviceDriver:
