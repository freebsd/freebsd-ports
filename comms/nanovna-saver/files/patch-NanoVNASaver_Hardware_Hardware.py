--- NanoVNASaver/Hardware/Hardware.py.orig	2022-01-04 07:44:03 UTC
+++ NanoVNASaver/Hardware/Hardware.py
@@ -34,6 +34,7 @@ from NanoVNASaver.Hardware.NanoVNA_H4 import NanoVNA_H
 from NanoVNASaver.Hardware.NanoVNA_V2 import NanoVNA_V2
 from NanoVNASaver.Hardware.TinySA import TinySA
 from NanoVNASaver.Hardware.Serial import drain_serial, Interface
+from NanoVNASaver.Hardware.Sysctl import usb_vid_pid
 
 
 logger = logging.getLogger(__name__)
@@ -80,6 +81,11 @@ def get_interfaces() -> List[Interface]:
     for d in list_ports.comports():
         if platform.system() == 'Windows' and d.vid is None:
             d = _fix_v2_hwinfo(d)
+        if platform.system() == 'FreeBSD':
+            logger.debug("Found FreeBSD USB port %s", d.device)
+            vid_pid = usb_vid_pid(d.device)
+            d.vid = vid_pid[0]
+            d.pid = vid_pid[1]
         for t in USBDEVICETYPES:
             if d.vid != t.vid or d.pid != t.pid:
                 continue
@@ -94,7 +100,6 @@ def get_interfaces() -> List[Interface]:
 
     logger.debug("Interfaces: %s", interfaces)
     return interfaces
-
 
 def get_VNA(iface: Interface) -> 'VNA':
     # serial_port.timeout = TIMEOUT
