# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/Network.py.orig	Mon Sep 22 12:51:42 2003
+++ libdesklets/Network.py	Mon Sep 22 13:04:06 2003
@@ -1,7 +1,9 @@
 import polling
 
 import commands
+import os
 import time
+import libdesklets as lib
 
 class Network:
 
@@ -25,22 +27,42 @@
 
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
 
-            if (fields[0] == "lo"):
-                continue
-            else: # (fields[0].startswith("eth")):
-                device = fields[0]
-                devices.append(device)
-        #end for
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
+                else: # (fields[0].startswith("eth")):
+                    device = fields[0]
+                    devices.append(device)
+            #end for
+        else:
+            pass
 
         return devices
 
@@ -48,13 +70,15 @@
 
     def __poll_ipaddr(self, dev):
 
-        data = commands.getoutput("/sbin/ifconfig " + dev)
-        lines = data.splitlines()
-        for l in lines:
+        fd = os.popen("/sbin/ifconfig " + dev, "r")
+        data = fd.readlines()
+        fd.close()
+        for l in data:
             l = l.strip()
             fields = l.split()
 
-            if (fields[0] == "inet"): return fields[1].split(":")[1]
+            if (fields[0] == "inet"):
+                return fields[1]
         #end for
 
         #fd = open("/proc/net/rt_cache", "r")
@@ -78,6 +102,8 @@
 
     def __poll_in_out(self, dev):
 
+        platform = lib.sys.get_os()
+
         t = time.time()
         interval = t - self.__time
         self.__time = t
@@ -88,24 +114,40 @@
         speed_in = 0
         speed_out = 0
 
-        fd = open("/proc/net/dev", "r")
+        if ("FreeBSD" == platform):
+            fd = os.popen("netstat -b -I " + dev + " | grep Link", "r")
+        elif ("Linux" == platform):
+            fd = open("/proc/net/dev", "r")
+        else:
+            return (bytes_in, bytes_out, pack_in, pack_out, speed_in, speed_out)
         data = fd.read()
         fd.close()
         lines = data.splitlines()
 
         # look for the device
         found = 0
-        for l in lines:
-            l.strip()
-            l = l.replace(":", " ")
-            fields = l.split()
-            if (fields[0] == dev):
-                bytes_in, pack_in, bytes_out, pack_out = \
-                long(fields[1]), long(fields[2]), \
-                long(fields[9]), long(fields[10])
+        if ("FreeBSD" == platform):
+            for l in lines:
                 found = 1
+                fields = l.strip().split()
+                bytes_in, pack_in, bytes_out, pack_out = \
+                long(fields[6]), long(fields[4]), \
+                long(fields[9]), long(fields[7])
                 break
-        #end for
+        elif ("Linux" == platform):
+            for l in lines:
+                l.strip()
+                l = l.replace(":", " ")
+                fields = l.split()
+                if (fields[0] == dev):
+                    bytes_in, pack_in, bytes_out, pack_out = \
+                    long(fields[1]), long(fields[2]), \
+                    long(fields[9]), long(fields[10])
+                    found = 1
+                    break
+            #end for
+        else:
+            pass
 
         # warn if we didn't find the device
         if (not found): print ("WARNING:: Device %(dev)s not found!") % vars()
