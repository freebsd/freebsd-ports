# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/Memory.py.orig	Fri Oct 17 22:57:33 2003
+++ libdesklets/Memory.py	Fri Oct 17 23:01:14 2003
@@ -1,7 +1,7 @@
 import polling
 
 import os, stat
-
+import libdesklets as lib
 
 class Memory:
 
@@ -16,41 +16,85 @@
 
     def __poll_total_ram(self):
 
-        memtotal = os.stat("/proc/kcore")[stat.ST_SIZE]
+        platform = lib.sys.get_os()
+        
+        if ("FreeBSD" == platform):
+            fd = os.popen("sysctl hw.physmem")
+            physmem = fd.readline()
+            fd.close()
+            lines = physmem.splitlines()
+            memtotal = int(lines[0].split()[1])
+        elif ("Linux" == platform):
+            memtotal = os.stat("/proc/kcore")[stat.ST_SIZE]
+        else:
+            memtotal = 0
+
         return memtotal
 
 
 
     def __poll_mem(self, mode):
 
-        fd = open("/proc/meminfo", "r")
-        mem = fd.read()
-        fd.close()
-        lines = mem.splitlines()
+        platform = lib.sys.get_os()
 
         # RAM
         if (mode == 0):
-            total = int(self.__get_total_ram()/1024)
-            for l in lines:
-                if (l.startswith("MemFree:")):
-                    value = l.split()
-                    free = int(value[1])
-                elif (l.startswith("Cached:")):
-                    value = l.split()
-                    free = free + int(value[1])
-                    break
-            used = total - free
+            if ("FreeBSD" == platform):
+                fd = os.popen("vmstat -n 0", "r")
+            elif ("Linux" == platform):
+                fd = open("/proc/meminfo", "r")
+            else:
+                return (0, 0)
+            mem = fd.read()
+            fd.close()
+            lines = mem.splitlines()
+
+            if ("FreeBSD" == platform):
+                # this may be larger than total, as this is the active virtual
+                # memory, not the active physical memory
+                used = int(lines[2].split()[3])/1024
+                total = int(self.__get_total_ram()/1024)
+            elif ("Linux" == platform):
+                total = int(self.__get_total_ram()/1024)
+                for l in lines:
+                    if (l.startswith("MemFree:")):
+                        value = l.split()
+                        free = int(value[1])
+                    elif (l.startswith("Cached:")):
+                        value = l.split()
+                        free = free + int(value[1])
+                        break
+                used = total - free
+            else:
+                pass
 
         # Swap
         elif (mode == 1):
-            for l in lines:
-                if (l.startswith("SwapTotal:")):
-                    value = l.split()
-                    total = int(value[1])
-                elif (l.startswith("SwapFree:")):
-                    value = l.split()
-                    free = int(value[1])
-                    break
-            used = total - free
+            if ("FreeBSD" == platform):
+                fd = os.popen("pstat -T", "r")
+            elif ("Linux" == platform):
+                fd = open("/proc/meminfo", "r")
+            else:
+                return (0, 0)
+            mem = fd.read()
+            fd.close()
+            lines = mem.splitlines()
+
+            if ("FreeBSD" == platform):
+                used, total = lines[1].split()[0].split("/")
+                used = int(used[0:-2]) * 1024 * 1024
+                total = int(total[0:-2]) * 1024 * 1024
+            elif ("Linux" == platform):
+                for l in lines:
+                    if (l.startswith("SwapTotal:")):
+                        value = l.split()
+                        total = int(value[1])
+                    elif (l.startswith("SwapFree:")):
+                        value = l.split()
+                        free = int(value[1])
+                        break
+                used = total - free
+            else:
+                pass
 
         return (total, used)
