--- daemons/hw_default.c.orig
+++ daemons/hw_default.c
@@ -38,6 +38,20 @@
 #include "transmit.h"
 #include "hw_default.h"
 
+/*
+ * Some(?) versions of the Linux mceusb /dev/lirc0 driver return
+ * trailing spaces while at least irrecord expects spaces at the
+ * beginning of a remote button event.  So if DELAYEDSPACE is
+ * defined delay a space until the next pulse if it comes right
+ * after a pulse.
+ *
+ * XXX make this a separate hw_mceusb device?
+ */
+#define DELAYEDSPACE
+#ifdef DELAYEDSPACE
+#include <errno.h>
+#endif
+
 extern struct ir_remote *repeat_remote;
 
 static __u32 supported_send_modes[] = {
@@ -81,6 +95,39 @@ struct hardware hw_default = {
 
 static int write_send_buffer(int lirc);
 
+#ifdef DELAYEDSPACE
+static int delayedspace = 100000;
+
+static int availabledata(void)
+{
+	fd_set fds;
+	int ret;
+	struct timeval tv;
+
+	FD_ZERO(&fds);
+	FD_SET(hw.fd, &fds);
+	do {
+		do {
+			tv.tv_sec = 0;
+			tv.tv_usec = 0;
+			ret = select(hw.fd + 1, &fds, NULL, NULL, &tv);
+		}
+		while (ret == -1 && errno == EINTR);
+		if (ret == -1) {
+			logprintf(LOG_ERR, "select() failed\n");
+			logperror(LOG_ERR, NULL);
+			continue;
+		}
+	}
+	while (ret == -1);
+
+	if (FD_ISSET(hw.fd, &fds)) {
+		return (1);
+	}
+	return (0);
+}
+#endif
+
 /**********************************************************************
  *
  * decode stuff
@@ -115,6 +162,13 @@ int default_readdata(lirc_t timeout)
 			dosigterm(SIGTERM);
 	}
 #else
+#ifdef DELAYEDSPACE
+	if (delayedspace) {
+		data = delayedspace;
+		delayedspace = 0;
+		return data;
+	}
+#endif
 	ret = read(hw.fd, &data, sizeof(data));
 	if (ret != sizeof(data)) {
 		logprintf(LOG_ERR, "error reading from %s (ret %d, expected %d)",
@@ -125,6 +179,19 @@ int default_readdata(lirc_t timeout)
 		return 0;
 	}
 
+#ifdef DELAYEDSPACE
+	if (hw.rec_mode == LIRC_MODE_MODE2 && (data & PULSE_BIT) && availabledata() /* waitfordata((long)timeout) */) {
+		ret = read(hw.fd, &delayedspace, sizeof(delayedspace));
+		if (ret != sizeof(delayedspace)) {
+			logprintf(LOG_ERR, "error reading space from %s (ret %d, expected %d)",
+				  hw.device, ret, sizeof(delayedspace));
+			logperror(LOG_ERR, NULL);
+			default_deinit();
+
+			return 0;
+		}
+	}
+#endif
 	if (data == 0) {
 		static int data_warning = 1;
 
