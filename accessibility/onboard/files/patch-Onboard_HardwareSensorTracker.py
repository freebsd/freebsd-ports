--- Onboard/HardwareSensorTracker.py.orig	2025-07-03 16:13:44 UTC
+++ Onboard/HardwareSensorTracker.py
@@ -259,7 +259,7 @@ class AcpidListener:
             elif self._exit_r in rl:
                 break
 
-            for event in data.decode("UTF-8").splitlines():
+            for event in data.decode("UTF-8", errors='replace').splitlines():
 
                 _logger.info("AcpidListener: ACPI event: '{}'"
                              .format(event))
