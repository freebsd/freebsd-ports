--- firmware/fx2/common/usb_common.c.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/usb_common.c	2012-10-07 19:37:57.000000000 -0500
@@ -28,12 +28,12 @@
 #include "usb_descriptors.h"
 #include "usb_requests.h"
 
-extern xdata char str0[];
-extern xdata char str1[];
-extern xdata char str2[];
-extern xdata char str3[];
-extern xdata char str4[];
-extern xdata char str5[];
+extern __xdata char str0[];
+extern __xdata char str1[];
+extern __xdata char str2[];
+extern __xdata char str3[];
+extern __xdata char str4[];
+extern __xdata char str5[];
 
 
 #define	bRequestType	SETUPDAT[0]
@@ -48,15 +48,15 @@
 #define MSB(x)	(((unsigned short) x) >> 8)
 #define LSB(x)	(((unsigned short) x) & 0xff)
 
-volatile bit _usb_got_SUDAV;
+volatile __bit _usb_got_SUDAV;
 
 unsigned char	_usb_config = 0;
 unsigned char	_usb_alt_setting = 0;	// FIXME really 1/interface
 
-xdata unsigned char *current_device_descr;
-xdata unsigned char *current_devqual_descr;
-xdata unsigned char *current_config_descr;
-xdata unsigned char *other_config_descr;
+__xdata unsigned char *current_device_descr;
+__xdata unsigned char *current_devqual_descr;
+__xdata unsigned char *current_config_descr;
+__xdata unsigned char *other_config_descr;
 
 static void
 setup_descriptors (void)
@@ -81,21 +81,21 @@
 }
 
 static void
-isr_SUDAV (void) interrupt
+isr_SUDAV (void) __interrupt
 {
   clear_usb_irq ();
   _usb_got_SUDAV = 1;
 }
 
 static void
-isr_USBRESET (void) interrupt
+isr_USBRESET (void) __interrupt
 {
   clear_usb_irq ();
   setup_descriptors ();
 }
 
 static void
-isr_HIGHSPEED (void) interrupt
+isr_HIGHSPEED (void) __interrupt
 {
   clear_usb_irq ();
   setup_descriptors ();
@@ -133,7 +133,7 @@
 // return pointer to control and status register for endpoint.
 // only called with plausible_endpoints
 
-xdata volatile unsigned char *
+__xdata volatile unsigned char *
 epcs (unsigned char ep)
 {
   if (ep == 0x01)		// ep1 has different in and out CS regs
@@ -234,7 +234,7 @@
 	  if (wValueL >= nstring_descriptors)
 	    fx2_stall_ep0 ();
 	  else {
-	    xdata char *p = string_descriptors[wValueL];
+	    __xdata char *p = string_descriptors[wValueL];
 	    SUDPTRH = MSB (p);
 	    SUDPTRL = LSB (p);
 	  }
