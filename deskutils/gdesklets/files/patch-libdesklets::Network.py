# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/Network.py.orig	Sun Nov  9 00:52:39 2003
+++ libdesklets/Network.py	Sun Nov  9 00:53:05 2003
@@ -1,8 +1,8 @@
 import polling
 import glibtop
-
+import os
 import time
-
+import libdesklets as lib
 
 class Network:
 
@@ -27,21 +27,40 @@
 
     def __poll_devices(self):
 
-        fd = open("/proc/net/dev", "r")
+        platform = lib.sys.get_os()
+
+        if ("FreeBSD" == platform):
+            fd = os.popen("ifconfig -a | grep mtu", "r")
+        elif ("Linux" == platform):
+            fd = open("/proc/net/dev", "r")
+        else:
+            return []
         data = fd.readlines()
         fd.close()
 
         devices = []
-        for lines in data[2:]:
-            l = lines.strip()
-            l = l.replace(":", " ")
-            fields = l.split()
-
-            if (fields[0] == "lo"):
-                continue
-            else:
-                device = fields[0]
-                devices.append(device)
+        if ("FreeBSD" == platform):
+            for lines in data:
+                fields = lines.strip().strip(":")
+
+                if (fields[0] == "lo"):
+                    continue
+                else:
+                    device = fields[0]
+                    devices.append(device)
+        elif ("Linux" == platform):
+            for lines in data[2:]:
+                l = lines.strip()
+                l = l.replace(":", " ")
+                fields = l.split()
+
+                if (fields[0] == "lo"):
+                    continue
+                else:
+                    device = fields[0]
+                    devices.append(device)
+        else:
+            pass
 
         return devices
 
