--- NanoVNASaver/Hardware/Hardware.py.orig	2020-08-13 17:01:29 UTC
+++ NanoVNASaver/Hardware/Hardware.py
@@ -32,6 +32,7 @@ from NanoVNASaver.Hardware.NanoVNA_H import NanoVNA_H
 from NanoVNASaver.Hardware.NanoVNA_H4 import NanoVNA_H4
 from NanoVNASaver.Hardware.NanoVNA_V2 import NanoVNA_V2
 from NanoVNASaver.Hardware.Serial import drain_serial, Interface
+from NanoVNASaver.Hardware.Sysctl import usb_vid_pid
 
 logger = logging.getLogger(__name__)
 
@@ -61,8 +62,12 @@ def get_interfaces() -> List[Interface]:
     interfaces = []
     # serial like usb interfaces
     for d in list_ports.comports():
-        if platform.system() == 'Windows' and d.vid is None:
-            d = _fix_v2_hwinfo(d)
+        if platform.system() == 'FreeBSD':
+            logger.debug("Found FreeBSD USB port %s", d.device)
+            vid_pid = usb_vid_pid(d.device)
+            d.vid = vid_pid[0]
+            d.pid = vid_pid[1]
+                
         for t in USBDEVICETYPES:
             if d.vid != t.vid or d.pid != t.pid:
                 continue
@@ -72,7 +77,6 @@ def get_interfaces() -> List[Interface]:
             iface.port = d.device
             interfaces.append(iface)
     return interfaces
-
 
 def get_VNA(iface: Interface) -> 'VNA':
     # serial_port.timeout = TIMEOUT
