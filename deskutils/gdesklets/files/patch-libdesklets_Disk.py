--- libdesklets/Disk.py.orig	Mon Aug 16 12:43:05 2004
+++ libdesklets/Disk.py	Mon Aug 16 12:43:10 2004
@@ -43,13 +43,14 @@
     #:/function
     #
     def __poll_size(self, partition):
-
-        blocks, bfree, bavail, files, ffree = glibtop.get_fsusage(partition)[:5]
-        free = float(bfree * 512)
-        total = float(blocks * 512)
+	# code stolen from libgtop.py::fsusage()
+        buf = glibtop.get_fsusage(partition)
+        bsize = buf[glibtop.FSUSAGE_BLOCK_SIZE]
+        free = float(buf[glibtop.FSUSAGE_BFREE] * bsize)
+        total = float(buf[glibtop.FSUSAGE_BLOCKS] * bsize)
         used = total - free
 
-        return (total, used)#, free)
+        return (total, used)
 
 
 
