# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> and
# Franz Klammer <klammer@webonaut.com> for help and create
# those patches.
#
# Note that, this is for now. One of us still need to fix the
# libgtop to correct read the partition so this patch can be
# remove.

--- libdesklets/Disk.py.orig	Mon Nov 17 13:59:20 2003
+++ libdesklets/Disk.py	Mon Nov 17 14:05:34 2003
@@ -1,6 +1,6 @@
 import glibtop
 import polling
-
+import os
 
 class Disk:
 
@@ -13,18 +13,22 @@
 
     def __poll_partitions(self):
 
-        data = glibtop.get_mountlist(0)
-        partitions = []
-        for size, device, mpoint, fstype in data:
-            if (fstype in ("ext2", "ext3", "msdos", "vfat", "ntfs", "hpfs"
-                           "jfs", "reiserfs", "xfs", "qnx4", "adfs", "ffs",
-                           "hfs", "befs", "bfs", "efs", "iso9660", "minix",
-                           "sysv", "coda", "nfs", "udf", "ufs", "xiafs")):
-                partitions.append((device, mpoint))
+        fd = os.popen("mount -p")
+        data = fd.readlines()
+        fd.close()
+
+        partitions = []
+        for lines in data:
+           fields = lines.strip().replace("\t", " ").split()
+           if (fields[2] in ("ext2", "ext3", "msdos", "vfat", "ntfs", "hpfs"
+                          "jfs", "reiserfs", "xfs", "qnx4", "adfs", "ffs",
+                          "hfs", "befs", "bfs", "efs", "iso9660", "minix",
+                          "sysv", "coda", "nfs", "udf", "ufs", "xiafs")):
+               partitions.append((fields[0], fields[1]))
         #end for
 
         return partitions
-            
+
 
 
     def __poll_size(self, partition):
