--- setup/FreeBSD/oss/build/bsdvirtual.inc.orig	2021-12-18 15:12:47.018175000 +0000
+++ setup/FreeBSD/oss/build/bsdvirtual.inc	2021-12-18 15:11:06.335823000 +0000
@@ -34,8 +34,6 @@
     {
       osdev = device_list[i];
 
-      if (osdev->dip != NULL && device_get_state(osdev->dip) == DS_BUSY)
-	device_unbusy(osdev->dip);
       if (!DRIVER_DETACH (osdev))
 	{
 	  printf (DRIVER_NICK ": Unloading busy device\n");
