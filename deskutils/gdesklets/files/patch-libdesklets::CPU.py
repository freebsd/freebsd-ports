# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/CPU.py	Thu Nov  6 14:50:47 2003
+++ libdesklets/CPU.py	Sun Nov  9 01:34:27 2003
@@ -1,6 +1,8 @@
 import polling
 import glibtop
 
+import os
+import libdesklets as lib
 
 #
 # TODO: support SMP
@@ -35,20 +37,36 @@
 
     def __poll_cpu(self):
 
-        import libdesklets as lib
+        import re
 
-        fd = open("/proc/cpuinfo", "r")
+        platform = lib.sys.get_os()
+
+        if platform == "FreeBSD":
+            fd = os.popen("grep -3 CPU /var/run/dmesg.boot | head -7 | tail -4", "r")
+        elif platform == "Linux":
+            fd = open("/proc/cpuinfo", "r")
+        else:
+            print "Unknown OS, strange things may happen."
+            return
         lines = fd.readlines()
         fd.close()
 
         arch = lib.sys.get_arch()
         if (arch in ["i386", "i486", "i586", "i686"]):
-            fields = lines[4].split()
-            model_name = " ".join(fields[3:])
-            fields = lines[6].split()
-            cpu_mhz = fields[3]
-            fields = lines[7].split()
-            cpu_cache = " ".join(fields[3:5])
+            if ("FreeBSD" == platform):
+                m = re.search('^CPU: (.*) \(([0-9]+.*)-MHz [0-9]+-class CPU\)', lines[0])
+                model_name = m.group(1)           # or sysctl hw.model
+                cpu_mhz = m.group(2)              # or sysctl hw.clockrate
+                cpu_cache = " "                   # not available by default
+            elif ("Linux" == platform):
+                fields = lines[4].split()
+                model_name = " ".join(fields[3:])
+                fields = lines[6].split()
+                cpu_mhz = fields[3]
+                fields = lines[7].split()
+                cpu_cache = " ".join(fields[3:5])
+            else:
+                pass
 
         elif (arch == "ppc"):
             fields = lines[0].split()
