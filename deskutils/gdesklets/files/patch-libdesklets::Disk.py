# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> and
# Franz Klammer <klammer@webonaut.com> for help and create
# those patches.
#
# Note that, this is for now. It will be remove when the
# libgtop is update to 2.6 or maybe I can ask gnome@freebsd.org
# if they won't mind to add a patch in libgtop 2.4 to get this
# patch remove.
#
# Joe has fixed it in the libgtop 2.5.x and isn't in ports yet.

--- libdesklets/Disk.py.orig	Tue Dec 30 13:29:57 2003
+++ libdesklets/Disk.py	Tue Dec 30 13:31:01 2003
@@ -1,6 +1,6 @@
 import glibtop
 import polling
-
+import os
 
 class Disk:
 
@@ -14,18 +14,22 @@
 
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
         #end for
 
         return partitions
-            
+
 
 
     def __poll_size(self, partition):
