--- libnfc/drivers/acr122_usb.c.orig	2022-02-01 22:26:36 UTC
+++ libnfc/drivers/acr122_usb.c
@@ -419,6 +419,9 @@ acr122_usb_open(const nfc_context *context, const nfc_
         continue;
       // Reset device
       usb_reset(data.pudh);
+      // Reopen the device
+      if ((data.pudh = usb_open(dev)) == NULL)
+        continue;
       // Retrieve end points
       acr122_usb_get_end_points(dev, &data);
       // Claim interface
