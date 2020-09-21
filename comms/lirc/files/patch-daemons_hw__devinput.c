--- daemons/hw_devinput.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/hw_devinput.c
@@ -376,9 +376,15 @@ int devinput_decode(struct ir_remote *remote, ir_code 
 	return 1;
 }
 
+/* simulate key repeat if receiving the same scancode again */
+#define RPT_SCAN
+
 char *devinput_rec(struct ir_remote *remotes)
 {
 	struct input_event event;
+#ifdef RPT_SCAN
+	static struct input_event rptevent, scancodeevent;
+#endif
 	int rd;
 	ir_code value;
 
@@ -399,6 +405,56 @@ char *devinput_rec(struct ir_remote *remotes)
 	LOGPRINTF(1, "time %ld.%06ld  type %d  code %d  value %d", event.time.tv_sec, event.time.tv_usec, event.type,
 		  event.code, event.value);
 
+#ifdef RPT_SCAN
+	repeat_state = RPT_UNKNOWN;
+	if (event.type == EV_KEY) {
+		if (event.code == rptevent.code &&
+		    event.value == 1 &&
+		    event.type == rptevent.type &&
+		    scancodeevent.type == EV_MSC) {
+			struct timeval difft;
+
+			difft = event.time;
+			difft.tv_sec -= scancodeevent.time.tv_sec;
+			difft.tv_usec -= scancodeevent.time.tv_usec;
+			if (difft.tv_usec < 0) {
+				difft.tv_sec--;
+				difft.tv_usec += 1000000;
+			}
+			if (difft.tv_sec == 0 && difft.tv_usec < 150000) {
+				repeat_state = RPT_YES;
+			}
+		}
+		rptevent = event;
+		scancodeevent.time = event.time;
+	} else if (event.type == EV_MSC && event.code == MSC_SCAN) {
+		if (scancodeevent.type == EV_MSC &&
+		    event.value == scancodeevent.value) {
+			if (rptevent.type == EV_KEY && rptevent.value != 0) {
+				struct timeval difft;
+
+			        difft = event.time;
+				difft.tv_sec -= scancodeevent.time.tv_sec;
+				difft.tv_usec -= scancodeevent.time.tv_usec;
+				if (difft.tv_usec < 0) {
+					difft.tv_sec--;
+					difft.tv_usec += 1000000;
+				}
+				scancodeevent = event;
+				event = rptevent;
+				if (difft.tv_sec == 0 && difft.tv_usec < 250000) {
+					event.value = 2;
+					repeat_state = RPT_YES;
+				} else {
+					event.value = 1;
+					repeat_state = RPT_NO;
+				}
+			}
+		} else if (rptevent.type == EV_KEY && rptevent.value <= 1) {
+			scancodeevent = event;
+		}
+	}
+#endif
 	value = (unsigned)event.value;
 #ifdef EV_SW
 	if (value == 2 && (event.type == EV_KEY || event.type == EV_SW)) {
@@ -418,6 +474,9 @@ char *devinput_rec(struct ir_remote *remotes)
 		if (event.value == 2) {
 			repeat_state = RPT_YES;
 		} else {
+#ifdef RPT_SCAN
+			if (repeat_state == RPT_UNKNOWN)
+#endif
 			repeat_state = RPT_NO;
 		}
 	} else {
