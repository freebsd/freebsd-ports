--- daemons/hw-types.c.orig
+++ daemons/hw-types.c
@@ -105,7 +105,7 @@ struct hardware *hw_list[] = {
 	&hw_awlibusb,
 #endif
 	&hw_bte,
-#ifdef HAVE_LINUX_HIDDEV_H
+#if defined(HAVE_LINUX_HIDDEV_H) || defined(HAVE_USBHID_H)
 	&hw_bw6130,
 #endif
 #ifdef HAVE_LIBUSB
@@ -125,7 +125,7 @@ struct hardware *hw_list[] = {
 #ifdef HAVE_SOUNDCARD
 	&hw_dsp,
 #endif
-#ifdef HAVE_LINUX_HIDDEV_H
+#if defined(HAVE_LINUX_HIDDEV_H) || defined(HAVE_USBHID_H)
 	&hw_dvico,
 #endif
 	&hw_ea65,
