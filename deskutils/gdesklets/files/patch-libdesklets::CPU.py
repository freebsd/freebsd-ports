# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/CPU.py.orig	Fri Oct 17 22:47:02 2003
+++ libdesklets/CPU.py	Fri Oct 17 22:53:05 2003
@@ -1,5 +1,7 @@
 import polling
 
+import os
+import libdesklets as lib
 
 #
 # TODO: support SMP
@@ -21,8 +23,16 @@
 
         self.get_load = polling.wrap(self.__poll_load, 0.2)
 
+        platform = lib.sys.get_os()
+
         try:
-            fd = open("/proc/cpuinfo", "r")
+            if platform == "FreeBSD":
+                fd = os.popen("grep -3 CPU /var/run/dmesg.boot | head -7 | tail -4", "r")
+            elif platform == "Linux":
+                fd = open("/proc/cpuinfo", "r")
+            else:
+                print "Unknown OS, strange things may happen."
+                return
         except IOError, e:
             import traceback; traceback.print_exc()
             print e
@@ -40,15 +50,24 @@
 
     def __poll_cpu(self):
 
-        import libdesklets as lib
+        import re
         arch = lib.sys.get_arch()
+        platform = lib.sys.get_os()
         if (arch in ["i386", "i486", "i586", "i686"]):
-            fields = self.__lines[4].split()
-            model_name = " ".join(fields[3:])
-            fields = self.__lines[6].split()
-            cpu_mhz = fields[3]
-            fields = self.__lines[7].split()
-            cpu_cache = " ".join(fields[3:5])
+            if ("FreeBSD" == platform):
+                m = re.search('^CPU: (.*) \(([0-9]+.*)-MHz [0-9]+-class CPU\)', self.__lines[0])
+                model_name = m.group(1)           # or sysctl hw.model
+                cpu_mhz = m.group(2)              # or sysctl hw.clockrate
+                cpu_cache = " "                   # not available by default
+            elif ("Linux" == platform):
+                fields = self.__lines[4].split()
+                model_name = " ".join(fields[3:])
+                fields = self.__lines[6].split()
+                cpu_mhz = fields[3]
+                fields = self.__lines[7].split()
+                cpu_cache = " ".join(fields[3:5])
+            else:
+                pass
 
         elif (arch == "ppc"):
             fields = self.__lines[0].split()
@@ -68,17 +87,34 @@
 
     def __poll_load(self):
 
-        fd = open("/proc/stat", "r")
+        platform = lib.sys.get_os()
+
+        if ("FreeBSD" == platform):
+            fd = os.popen("iostat -n 0", "r")
+            line = 2
+        elif ("Linux" == platform):
+            fd = open("/proc/stat", "r")
+            line = 0
+        else:
+            return
         data = fd.read()
         fd.close()
 
         data = data.splitlines()
-        fields = data[0].split()
+        fields = data[line].split()
 
-        u = float(fields[1])
-        s = float(fields[2])
-        n = float(fields[3])
-        i = float(fields[4])
+        if ("FreeBSD" == platform):
+            u = float(fields[2]) + float(fields[3])
+            s = float(fields[4])
+            n = float(fields[5])
+            i = float(fields[6])
+        elif ("Linux" == platform):
+            u = float(fields[1])
+            s = float(fields[2])
+            n = float(fields[3])
+            i = float(fields[4])
+        else:
+            pass
 
         total = ((u - self.__uT) + (s - self.__sT) + (n - self.__nT) +
                 (i - self.__iT))
