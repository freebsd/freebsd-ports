
$FreeBSD$

--- src/joystick/bsd/SDL_sysjoystick.c.orig	Sun Mar 10 05:49:25 2002
+++ src/joystick/bsd/SDL_sysjoystick.c	Thu Apr 18 10:48:00 2002
@@ -41,7 +41,11 @@
 
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
-#include <usbhid.h>
+#if !defined(HAVE_LIBUSBHID_H)
+#include <libusb.h>
+#else
+#include <libusbhid.h>
+#endif
 
 #include "SDL_error.h"
 #include "SDL_joystick.h"
@@ -205,7 +209,8 @@
 	joy->nballs = 0;
 
 	while (hid_get_item(hdata, &hitem) > 0) {
-		char *s, *sp;
+		const char *s;
+		char *sp;
 
 		switch (hitem.kind) {
 		case hid_collection:
@@ -275,7 +280,7 @@
 	Sint32 v;
 	
 	rep = &joy->hwdata->inreport;
-	if (read(joy->hwdata->fd, rep->buf->data, rep->size) != rep->size) {
+	if (read(joy->hwdata->fd, rep->buf->ucr_data, rep->size) != rep->size) {
 		return;
 	}
 	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input);
@@ -310,7 +315,7 @@
 					goto scaleaxe;
 				}
 scaleaxe:
-				v = (Sint32)hid_get_data(rep->buf->data, &hitem);
+				v = (Sint32)hid_get_data(rep->buf->ucr_data, &hitem);
 				if (v != 127) {
 					if (v < 127) {
 						v = -(256 - v);
@@ -329,7 +334,7 @@
 				}
 				break;
 			case HUP_BUTTON:
-				v = (Sint32)hid_get_data(rep->buf->data,
+				v = (Sint32)hid_get_data(rep->buf->ucr_data,
 				    &hitem);
 				if (joy->buttons[nbutton] != v) {
 					SDL_PrivateJoystickButton(joy,
@@ -381,7 +386,12 @@
 {
 	int len;
 
+#if !defined(HAVE_LIBUSBHID_H)
 	len = hid_report_size(rd, repinfo[repind].kind, &r->rid);
+#else
+	len = hid_report_size(rd, r->rid, repinfo[repind].kind);
+#endif
+	
 	if (len < 0) {
 		SDL_SetError("Negative HID report size");
 		return (-1);
@@ -389,7 +399,7 @@
 	r->size = len;
 
 	if (r->size > 0) {
-		r->buf = malloc(sizeof(*r->buf) - sizeof(r->buf->data) +
+		r->buf = malloc(sizeof(*r->buf) - sizeof(r->buf->ucr_data) +
 		    r->size);
 		if (r->buf == NULL) {
 			SDL_OutOfMemory();
