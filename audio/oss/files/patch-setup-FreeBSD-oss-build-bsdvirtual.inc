--- setup/FreeBSD/oss/build/bsdvirtual.inc.orig	2007-12-19 14:56:18.000000000 -0500
+++ setup/FreeBSD/oss/build/bsdvirtual.inc	2008-01-14 14:09:02.000000000 -0500
@@ -34,6 +34,8 @@
     {
       osdev = device_list[i];
 
+      if (osdev->dip != NULL && device_get_state(osdev->dip) == DS_BUSY)
+	device_unbusy(osdev->dip);
       if (!DRIVER_DETACH (osdev))
 	{
 	  printf (DRIVER_NICK ": Unloading busy device\n");
