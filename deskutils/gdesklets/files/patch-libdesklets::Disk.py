--- libdesklets/Disk.py.orig	Mon Feb 23 10:52:50 2004
+++ libdesklets/Disk.py	Mon Feb 23 10:54:31 2004
@@ -1,6 +1,6 @@
 import glibtop
 import polling
-
+import os
 
 class Disk:
 
@@ -21,14 +21,19 @@
     #
     def __poll_partitions(self):
 
-        data = glibtop.get_mountlist(0)
+        fd = os.popen("mount -p")
+        data = fd.readlines()
+        fd.close()
+
         partitions = []
-        for size, device, mpoint, fstype in data:
-            if (fstype in ("ext2", "ext3", "msdos", "vfat", "ntfs", "hpfs"
-                           "jfs", "reiserfs", "xfs", "qnx4", "adfs", "ffs",
-                           "hfs", "befs", "bfs", "efs", "iso9660", "minix",
-                           "sysv", "coda", "nfs", "udf", "ufs", "xiafs")):
-                partitions.append((device, mpoint))
+        for lines in data:
+           fields = lines.strip().replace("\t", " ").split()
+           if (fields[2] in ("ext2", "ext3", "msdos", "vfat", "ntfs", "hpfs"
+                          "jfs", "reiserfs", "xfs", "qnx4", "adfs", "ffs",
+                          "hfs", "befs", "bfs", "efs", "iso9660", "minix",
+                          "sysv", "coda", "nfs", "udf", "ufs", "xiafs")):
+               partitions.append((fields[0], fields[1]))
+
 
         return partitions
             
