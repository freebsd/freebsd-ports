--- setup/FreeBSD/oss/build/bsdpci.inc.orig	2014-02-14 22:59:55.000000000 +0000
+++ setup/FreeBSD/oss/build/bsdpci.inc	2021-12-18 15:09:33.546812000 +0000
@@ -92,8 +92,6 @@
       osdev = device_list[i];
       if (osdev->dip == dev)
 	{
-	  if (device_get_state(dev) == DS_BUSY)
-	    device_unbusy(dev);
 	  if (!DRIVER_DETACH (osdev))
 	    {
 	      printf (DRIVER_NICK ": Unloading busy device\n");
