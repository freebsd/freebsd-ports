--- setup/FreeBSD/oss/build/bsdpci.inc.orig	2014-02-14 22:59:55 UTC
+++ setup/FreeBSD/oss/build/bsdpci.inc
@@ -92,8 +92,6 @@ osspci_detach (device_t dev)
       osdev = device_list[i];
       if (osdev->dip == dev)
 	{
-	  if (device_get_state(dev) == DS_BUSY)
-	    device_unbusy(dev);
 	  if (!DRIVER_DETACH (osdev))
 	    {
 	      printf (DRIVER_NICK ": Unloading busy device\n");
@@ -150,4 +148,6 @@ static device_method_t osspci_methods[] = {
   {0, 0}
 };
 
+#if __FreeBSD_version < 1400058
 static devclass_t osspci_devclass;
+#endif
