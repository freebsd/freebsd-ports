# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/Sys.py.orig	Mon Sep 22 13:06:41 2003
+++ libdesklets/Sys.py	Mon Sep 22 13:13:11 2003
@@ -2,7 +2,8 @@
 
 import commands
 import time
-
+import os
+import libdesklets as lib
 
 class Sys:
 
@@ -31,17 +32,25 @@
 
     def __poll_os(self):
 
-        os = commands.getoutput("uname -o")
-        return os
+        platform = commands.getoutput("uname -s")
+        return platform
 
 
     def __poll_uptime(self, mode):
 
-        fd = open("/proc/uptime", "r")
-        data = fd.readlines()
-        fd.close()
-        
-        uptime, idletime = data[0].split()
+        platform = lib.sys.get_os()
+
+        if ("FreeBSD" == platform):
+            bt = commands.getoutput("sysctl kern.boottime")
+            boottime = int(bt.strip().split()[4].strip(","))
+            uptime = int(time.time() - float(boottime))
+            idletime = 0
+        elif ("Linux" == platform):
+            fd = open("/proc/uptime", "r")
+            data = fd.readlines()
+            fd.close()
+            uptime, idletime = data[0].split()
+            boottime = int(time.time() - float(uptime))
 
         # uptime
         if (mode == 0):
@@ -51,16 +60,32 @@
             return int(float(idletime))
         # sys start
         elif (mode == 2):
-            now = time.time()
-            return int(now - float(uptime))
+            return boottime
 
 
     def __poll_load_avg(self, mode):
 
-        fd = open("/proc/loadavg", "r")
+        import re
+        platform = lib.sys.get_os()
+
+        if ("FreeBSD" == platform):
+            fd = os.popen("uptime")
+        elif ("Linux" == platform):
+            fd = open("/proc/loadavg", "r")
+        else:
+            return float(0.0)
         data = fd.readlines()
         fd.close()
-        load1, load5, load15, t, d = data[0].split()
+
+        if ("FreeBSD" == platform):
+            m = re.search('load averages: ([0-9]\.[0-9]+), ([0-9]\.[0-9]+), ([0-9]\.[0-9]+)', data[0])
+            load1  = m.group(1)
+            load5  = m.group(2)
+            load15 = m.group(3)
+        elif ("Linux" == platform):
+            load1, load5, load15, t, d = data[0].split()
+        else:
+            pass
 
         # avg over 1 minute
         if (mode == 0):
@@ -76,11 +101,25 @@
 
     def __poll_tasks(self):
 
-        fd = open("/proc/loadavg", "r")
+        platform = lib.sys.get_os()
+
+        if ("FreeBSD" == platform):
+            fd = os.popen("vmstat -n 0")
+        elif ("Linux" == platform):
+            fd = open("/proc/loadavg", "r")
+        else:
+            return (int(0), int(0))
         data = fd.readlines()
         fd.close()
 
-        parts = data[0].split()
-        running, tasks = parts[3].split("/")
+        if ("FreeBSD" == platform):
+            parts = data[2].split()
+            running = parts[0]
+            tasks = parts[0] + parts[1] + parts[2]
+        elif ("Linux" == platform):
+            parts = data[0].split()
+            running, tasks = parts[3].split("/")
+        else:
+            pass
 
         return (int(tasks), int(running))
