# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/Disk.py.orig	Mon Sep 22 12:25:18 2003
+++ libdesklets/Disk.py	Mon Sep 22 12:28:28 2003
@@ -3,7 +3,7 @@
 import time
 import os
 import statvfs
-
+import libdesklets as lib
 
 class Disk:
 
@@ -19,21 +19,33 @@
 
     def __poll_partitions(self):
 
+        platform = lib.sys.get_os()
+
         # we don't have to reread the file if it hasn't changed
-        if (self.__partitions_last_read >= os.path.getmtime("/etc/mtab")):
+        if (platform == "Linux" and self.__partitions_last_read >= os.path.getmtime("/etc/mtab")):
             return self.__partitions
         else:
             self.__partitions_last_read = time.time()
 
         # /etc/mtab is more portable than /proc/mount, so we use it
-        fd = open("/etc/mtab", "r")
+        if (platform == "Linux"):
+            fd = open("/etc/mtab", "r")
+        else:
+            fd = os.popen("mount", "r")
         lines = fd.readlines()
         fd.close()
 
         partitions = []
         for l in lines:
             parts = l.split()
-            device, mpoint, fstype = parts[:3]
+            if (platform == "Linux"):
+                device, mpoint, fstype = parts[:3]
+            elif (platform == "FreeBSD"):
+                device = parts[0]
+                mpoint = parts[2]
+                import re
+                m = re.search('\(([a-zA-Z]+)[,)]', parts[3])
+                fstype = m.group(0)
             # FIXME: is this OK? it might be better to check if the device
             #        actually is a file in /dev
             if (fstype in ("ext2", "ext3", "msdos", "vfat", "ntfs", "hpfs"
