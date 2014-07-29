--- daemons/hw_hiddev.c.orig
+++ daemons/hw_hiddev.c
@@ -22,9 +22,17 @@
 #include <stdio.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
+#include <errno.h>
 
+#ifdef HAVE_USBHID_H
+#include <usbhid.h>
+#endif
+#ifdef HAVE_LINUX_TYPES_H
 #include <linux/types.h>
+#endif
+#ifdef HAVE_LINUX_HIDDEV_H
 #include <linux/hiddev.h>
+#endif
 
 #include "hardware.h"
 #include "ir_remote.h"
@@ -135,6 +143,7 @@ struct hardware hw_sb0540 = {
 };
 #endif
 
+#ifdef HAVE_LINUX_HIDDEV_H
 /* Apple Mac mini USB IR Receiver */
 struct hardware hw_macmini = {
 	"/dev/usb/hiddev0",	/* "device" */
@@ -152,6 +161,7 @@ struct hardware hw_macmini = {
 	NULL,			/* readdata */
 	"macmini"		/* name */
 };
+#endif
 
 #ifdef HAVE_LINUX_HIDDEV_FLAG_UREF
 /* Samsung USB IR Receiver */
@@ -191,7 +201,11 @@ int hiddev_init()
 	logprintf(LOG_INFO, "initializing '%s'", hw.device);
 
 	if ((hw.fd = open(hw.device, O_RDONLY)) < 0) {
-		logprintf(LOG_ERR, "unable to open '%s'", hw.device);
+		logprintf(LOG_ERR,
+                          "unable to open '%s': %s (%d)",
+                          hw.device,
+                          strerror (errno),
+                          errno );
 		return 0;
 	}
 
@@ -235,8 +249,40 @@ int hiddev_decode(struct ir_remote *remo
 	return 1;
 }
 
+/*
+ * Read a record from the remote control, decode it and return a
+ * string of the form
+ *
+ * 00010046000042fe 00 start DVICO_MCE
+ *
+ * The first field is the complete event.  The second appears to tbe
+ * the repeat flag, the third the name of the the key, and the fourth
+ * some kind of identification.  I have no idea how much of this is
+ * used.
+ *
+ * The code below works around the extremely fast repeat holdoff on
+ * the DVICO control.  It's difficult to press a key without it
+ * repeating.  We work around this by ignoring the first 3 repeats.
+ *
+ * For FreeBSD, we have the problem of a different HID interface.
+ * Linux returns a struct hiddev_event, while FreeBSD returns data
+ * with no specific structure.  Part of the Linux structure is the
+ * hid, which FreeBSD doesn't seem to supply.  Work around these
+ * issues by reading the FreeBSD data and packing it into a Linux
+ * struct hiddev_event.  This requires lying about the hid.
+ */
+
 char *hiddev_rec(struct ir_remote *remotes)
 {
+#ifdef __FreeBSD__
+#define HIDRECLEN 3                             /* get this from hid_init() */
+	char inbuf [HIDRECLEN];
+        struct hiddev_event
+        {
+		unsigned hid;
+		int32_t value;
+        };
+#endif
 	struct hiddev_event event;
 	struct hiddev_event asus_events[8];
 	int rd;
@@ -253,9 +299,41 @@ char *hiddev_rec(struct ir_remote *remot
 
 	last = end;
 	gettimeofday(&start, NULL);
+#ifdef __FreeBSD__
+	if (!strcmp(hw.name, "dvico")) {
+		rd = read(hw.fd, inbuf, sizeof inbuf);
+		if (rd != sizeof inbuf) {
+			logprintf(LOG_ERR,
+					  "Really read %d bytes from '%s', expected %d",
+					  rd,
+					  hw.device,
+					  sizeof inbuf );
+			return 0;
+		}
+		event.hid = 0x10046;             /* XXX not in FreeBSD */
+		event.value = * (int16_t *) (&inbuf [1]);
+	} else {
+		rd = read(hw.fd, &event.value, sizeof event.value);
+		if (rd != sizeof event.value) {
+			logprintf(LOG_ERR,
+					  "Really read %d bytes from '%s', expected %d",
+					  rd,
+					  hw.device,
+					  sizeof event.value );
+			return 0;
+		}
+		event.hid = 0x10046;             /* XXX not in FreeBSD */
+	}
+	rd = sizeof event;                          /* to make code happy */
+#else
 	rd = read(hw.fd, &event, sizeof event);
+#endif
 	if (rd != sizeof event) {
-		logprintf(LOG_ERR, "error reading '%s'", hw.device);
+		logprintf(LOG_ERR,
+                                  "Read %d bytes from '%s', expected %d",
+                                  rd,
+                                  hw.device,
+                                  sizeof event );
 		logperror(LOG_ERR, NULL);
 		hiddev_deinit();
 		return 0;
@@ -515,6 +593,7 @@ char *sb0540_rec(struct ir_remote *remot
 }
 #endif
 
+#ifdef HAVE_LINUX_HIDDEV_H
 /*
  * Apple Mac mini USB IR Receiver specific code.
  *
@@ -566,6 +645,7 @@ char *macmini_rec(struct ir_remote *remo
 
 	return decode_all(remotes);
 }
+#endif
 
 /*
  * Samsung/Cypress USB IR Receiver specific code
