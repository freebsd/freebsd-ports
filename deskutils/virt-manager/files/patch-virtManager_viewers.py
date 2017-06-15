--- virtManager/viewers.py.orig	2016-06-17 21:37:47 UTC
+++ virtManager/viewers.py
@@ -538,16 +538,23 @@ class SpiceViewer(Viewer):
         GObject.GObject.connect(self._spice_session, "channel-new",
                                 self._channel_new_cb)
 
-        self._usbdev_manager = SpiceClientGLib.UsbDeviceManager.get(
-                                    self._spice_session)
-        self._usbdev_manager.connect("auto-connect-failed",
-                                    self._usbdev_redirect_error)
-        self._usbdev_manager.connect("device-error",
-                                    self._usbdev_redirect_error)
+        # Distros might have usb redirection compiled out, like OpenBSD
+        # https://bugzilla.redhat.com/show_bug.cgi?id=1348479
+        try:
+            self._usbdev_manager = SpiceClientGLib.UsbDeviceManager.get(
+                                        self._spice_session)
+            self._usbdev_manager.connect("auto-connect-failed",
+                                        self._usbdev_redirect_error)
+            self._usbdev_manager.connect("device-error",
+                                        self._usbdev_redirect_error)
 
-        autoredir = self.config.get_auto_redirection()
-        if autoredir:
-            gtk_session.set_property("auto-usbredir", True)
+            autoredir = self.config.get_auto_redirection()
+            if autoredir:
+                gtk_session.set_property("auto-usbredir", True)
+        except:
+            self._usbdev_manager = None
+            logging.debug("Error initializing spice usb device manager",
+                exc_info=True)
 
 
     #####################
