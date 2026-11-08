--- indiweb/driver.py.orig	2020-02-02 00:00:00 UTC
+++ indiweb/driver.py
@@ -5,7 +5,7 @@ import xml.etree.ElementTree as ET  # noqa: N817
 import xml.etree.ElementTree as ET  # noqa: N817
 
 # Default INDI data directory
-INDI_DATA_DIR = os.environ.get('INDI_DATA_DIR', "/usr/share/indi/")
+INDI_DATA_DIR = os.environ.get('INDI_DATA_DIR', "%%LOCALBASE%%/share/indi/")
 
 
 class DeviceDriver:
