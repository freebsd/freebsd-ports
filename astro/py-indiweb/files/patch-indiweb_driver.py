--- indiweb/driver.py.orig	2021-02-24 15:36:36 UTC
+++ indiweb/driver.py
@@ -5,7 +5,7 @@ import xml.etree.ElementTree as ET
 import xml.etree.ElementTree as ET
 
 # Default INDI data directory
-INDI_DATA_DIR = os.environ.get('INDI_DATA_DIR', "/usr/share/indi/")
+INDI_DATA_DIR = os.environ.get('INDI_DATA_DIR', "%%LOCALBASE%%/share/indi/")
 
 
 class DeviceDriver:
