--- libdesklets/Disk.py.orig	Fri Feb 20 14:29:07 2004
+++ libdesklets/Disk.py	Fri Apr 30 15:50:42 2004
@@ -1,6 +1,7 @@
 import glibtop
 import polling
-
+import os
+import statvfs
 
 class Disk:
 
@@ -21,14 +22,19 @@
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
             
@@ -43,15 +49,19 @@
     #:/function
     #
     def __poll_size(self, partition):
-
-        blocks, bfree, bavail, files, ffree = glibtop.get_fsusage(partition)
-        free = float(bfree * 512)
-        total = float(blocks * 512)
-        used = total - free
-
-        return (total, used)#, free)
-
-
+                                                                                                                                
+          try:
+              statvfs_data = os.statvfs(partition)
+              free = float(statvfs_data[statvfs.F_BFREE] * statvfs_data[statvfs.F_FRSIZE])
+              total = float(statvfs_data[statvfs.F_BLOCKS] * statvfs_data[statvfs.F_FRSIZE])
+          except:
+              blocks, bfree, bavail, files, ffree = glibtop.get_fsusage(partition)
+              free = float(bfree * 512)
+              total = float(blocks * 512)
+                                                                                                                                
+          used = total - free
+                                                                                                                                
+          return (total, used)#, free)
 
     #
     #:function get_fs | partition | Returns the filesystem for the given
