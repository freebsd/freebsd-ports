--- src/joystick/bsd/SDL_sysjoystick.c.orig	Sat Oct  5 01:32:49 2002
+++ src/joystick/bsd/SDL_sysjoystick.c	Sun Apr  6 23:40:03 2003
@@ -53,6 +53,10 @@
 #include <libusbhid.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
+
 #include "SDL_error.h"
 #include "SDL_joystick.h"
 #include "SDL_sysjoystick.h"
@@ -201,6 +205,7 @@
 	}
 
 	rep = &hw->inreport;
+	rep->rid = 0;
 	if (report_alloc(rep, hw->repdesc, REPORT_INPUT) < 0) {
 		goto usberr;
 	}
@@ -210,7 +215,7 @@
 		goto usberr;
 	}
 
-#ifdef USBHID_NEW
+#if defined(USBHID_NEW) || (defined(__FreeBSD__) && __FreeBSD_version >= 500111)
 	hdata = hid_start_parse(hw->repdesc, 1 << hid_input, rep->rid);
 #else
 	hdata = hid_start_parse(hw->repdesc, 1 << hid_input);
@@ -300,7 +305,7 @@
 	if (read(joy->hwdata->fd, REP_BUF_DATA(rep), rep->size) != rep->size) {
 		return;
 	}
-#ifdef USBHID_NEW
+#if defined(USBHID_NEW) || (defined(__FreeBSD__) && __FreeBSD_version >= 500111)
 	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input, rep->rid);
 #else
 	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input);
@@ -399,11 +404,24 @@
 {
 	int len;
 
-#ifdef USBHID_NEW
+#ifdef __FreeBSD__
+# if (__FreeBSD_version >= 470000)
+#  if ((__FreeBSD_version <= 500111) && (__FreeBSD_version >= 480000))
+	len = hid_report_size(rd, r->rid, repinfo[repind].kind);
+#  else
+	len = hid_report_size(rd, repinfo[repind].kind, r->rid);
+#  endif
+# else
 	len = hid_report_size(rd, repinfo[repind].kind, &r->rid);
+#endif
 #else
+# ifdef USBHID_NEW
+	len = hid_report_size(rd, repinfo[repind].kind, &r->rid);
+# else
 	len = hid_report_size(rd, repinfo[repind].kind, r->rid);
+# endif
 #endif
+
 	if (len < 0) {
 		SDL_SetError("Negative HID report size");
 		return (-1);
