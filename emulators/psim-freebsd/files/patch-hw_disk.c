--- sim/ppc/hw_disk.c.orig	Thu Apr 15 18:35:09 1999
+++ sim/ppc/hw_disk.c	Mon Mar 25 15:58:01 2002
@@ -232,6 +232,9 @@
 			space, address, 0/*size*/, access_read_write_exec,
 			me);
 
+  /* Tell the world we are a disk.  */
+  device_add_string_property(me, "device_type", "disk");
+
   /* get the name of the file specifying the disk image */
   disk->name_index = 0;
   disk->nr_names = device_find_string_array_property(me, "file",
