--- setup/FreeBSD/oss/build/bsdpci.inc.orig	2007-12-19 14:56:18.000000000 -0500
+++ setup/FreeBSD/oss/build/bsdpci.inc	2008-01-14 14:38:15.000000000 -0500
@@ -92,6 +92,8 @@
       osdev = device_list[i];
       if (osdev->dip == dev)
 	{
+	  if (device_get_state(dev) == DS_BUSY)
+	    device_unbusy(dev);
 	  if (!DRIVER_DETACH (osdev))
 	    {
 	      printf (DRIVER_NICK ": Unloading busy device\n");
