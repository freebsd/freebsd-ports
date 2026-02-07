--- NanoVNASaver/Hardware/Hardware.py.orig	2022-04-01 14:51:11 UTC
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
@@ -87,14 +93,17 @@ def get_interfaces() -> List[Interface]:
                          t.name, d.vid, d.pid, d.device)
             iface = Interface('serial', t.name)
             iface.port = d.device
-            iface.open()
+            try:
+                iface.open()
+            except serial.SerialException:
+                logger.warning("Could not open serial port %s", d.device)
+                continue
             iface.comment = get_comment(iface)
             iface.close()
             interfaces.append(iface)
 
     logger.debug("Interfaces: %s", interfaces)
     return interfaces
-
 
 def get_VNA(iface: Interface) -> 'VNA':
     # serial_port.timeout = TIMEOUT
