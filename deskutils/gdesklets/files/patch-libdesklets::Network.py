# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> and
# Franz Klammer <klammer@webonaut.com> for help and create
# those patches.

--- libdesklets/Network.py.orig	Sun Nov 16 15:15:30 2003
+++ libdesklets/Network.py	Sun Nov 16 15:18:22 2003
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
+                fields = lines.strip().split(":")
+
+                if (fields[0][:2] == "lo"):
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
 
