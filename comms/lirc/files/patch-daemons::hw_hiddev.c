--- daemons/hw_hiddev.c.orig	Sun Jul 10 18:04:11 2005
+++ daemons/hw_hiddev.c	Thu Nov 23 14:41:52 2006
@@ -19,14 +19,19 @@
 #include <stdio.h>
 #include <sys/fcntl.h>
 
+#ifdef __FreeBSD__
+#include <usbhid.h>
+#else  /* assume Linux */
 #include <linux/types.h>
 #include <linux/hiddev.h>
+#endif
 
 #include "hardware.h"
 #include "ir_remote.h"
 #include "lircd.h"
 #include "receive.h"
-
+#include <errno.h>
+#include <string.h>
 
 static int hiddev_init();
 static int hiddev_deinit(void);
@@ -103,7 +108,11 @@
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
 	
@@ -143,38 +152,117 @@
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
+		int16_t value;
+        };
+#endif
 	struct hiddev_event event;
 	int rd;
 	/* Remotec Mediamaster specific */
 	static int wheel_count = 0;
 	static int x_movement = 0;
+        static int repeat_count = 0;
 	int y_movement=0;
 	int x_direction=0;
 	int y_direction=0;
 	
 	LOGPRINTF(1, "hiddev_rec");
 	
+#ifdef __FreeBSD__
+	rd = read(hw.fd, inbuf, sizeof inbuf);
+                if (rd != sizeof inbuf) {
+		logprintf(LOG_ERR,
+                                  "Really read %d bytes from '%s', expected %d",
+                                  rd,
+                                  hw.device,
+                                  sizeof inbuf );
+		return 0;
+	}
+	event.hid = 0x10046;             /* XXX not in FreeBSD */
+	event.value = * (int16_t *) (&inbuf [1]);
+                rd = sizeof event;                          /* to make code happy */
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
 		return 0;
 	}
 
 	LOGPRINTF(1, "hid 0x%X  value 0x%X", event.hid, event.value);
 
 	pre_code = event.hid;
-	main_code = event.value;
-
+	main_code = event.value & 0xffff;                   /* only 16 bits */
 	/*
 	 * This stuff is probably dvico specific.
 	 * I don't have any other hid devices to test...
 	 */
-	if (event.hid == 0x10046) {
-		repeat_flag = (main_code & dvico_repeat_mask);
+	if (pre_code == 0x10046) {
+                if (main_code & dvico_repeat_mask) /* repeated press */
+                	repeat_count++;                /* count them */
+                else
+                	repeat_count = 0;              /* reset */
+                repeat_flag = repeat_count > 2; /* real repeat flag */
 		main_code = (main_code & ~dvico_repeat_mask);
-		return decode_all(remotes);
+                        /*
+                         * Skip this if we're working around the premature
+                         * repeat.
+                         */
+                        if (repeat_flag || (repeat_count == 0))
+                        {
+				char *foo;
+
+                        	foo = decode_all(remotes);
+                                /*
+                                 * XXX Experimental code.  Chop off the first 12
+                                 * bytes of the hex code, which FreeBSD does not
+                                 * provide, and which I suspect nobody cares
+                                 * about.
+                                 *
+                                 * For some reason, we can get NULL back here,
+                                 * so we need to check for that before returning
+                                 * address 0xc.
+                                 */
+                                if (foo)
+                                  foo = &foo [12];     /* chop off the leading chars. */
+                                return foo;
+                        }
+                        else
+                        	return 0;                    /* no data */
 	}
 	/* Remotec Mediamaster specific code */
 	/* Y-Coordinate,
