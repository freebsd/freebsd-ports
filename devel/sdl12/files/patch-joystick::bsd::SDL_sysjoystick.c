
$FreeBSD$

--- src/joystick/bsd/SDL_sysjoystick.c.orig	Sat Oct  5 08:32:49 2002
+++ src/joystick/bsd/SDL_sysjoystick.c	Mon Jul 14 21:12:23 2003
@@ -53,6 +53,11 @@
 #include <libusbhid.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#include <sys/joystick.h>
+#endif
+
 #include "SDL_error.h"
 #include "SDL_joystick.h"
 #include "SDL_sysjoystick.h"
@@ -192,7 +197,18 @@
 	joy->hwdata = hw;
 	hw->fd = fd;
 	hw->path = strdup(path);
-	hw->type = BSDJOY_UHID;
+	if (! strncmp(path, "/dev/joy", 8))
+	{
+		hw->type = BSDJOY_JOY;
+		joy->naxes = 2;
+		joy->nbuttons = 2;
+		joy->nhats = 0;
+		joy->nballs = 0;
+		joydevnames[joy->index] = strdup("Gameport joystick");
+		goto usbend;
+	}
+	else
+	  hw->type = BSDJOY_UHID;
 	hw->repdesc = hid_get_report_desc(fd);
 	if (hw->repdesc == NULL) {
 		SDL_SetError("%s: USB_GET_REPORT_DESC: %s", hw->path,
@@ -201,6 +217,7 @@
 	}
 
 	rep = &hw->inreport;
+	rep->rid = 0;
 	if (report_alloc(rep, hw->repdesc, REPORT_INPUT) < 0) {
 		goto usberr;
 	}
@@ -210,7 +227,7 @@
 		goto usberr;
 	}
 
-#ifdef USBHID_NEW
+#if defined(USBHID_NEW) || (defined(__FreeBSD__) && __FreeBSD_version >= 500111)
 	hdata = hid_start_parse(hw->repdesc, 1 << hid_input, rep->rid);
 #else
 	hdata = hid_start_parse(hw->repdesc, 1 << hid_input);
@@ -275,6 +292,7 @@
 	}
 	hid_end_parse(hdata);
 
+usbend:
 	/* The poll blocks the event thread. */
 	fcntl(fd, F_SETFL, O_NONBLOCK);
 
@@ -294,13 +312,62 @@
 	struct report *rep;
 	int nbutton, naxe = -1;
 	Sint32 v;
+	struct joystick gameport;
+	static int x, y, xmin=0xffff, ymin=0xffff, xmax=0, ymax=0;
+
+	if (!strncmp(joy->hwdata->path, "/dev/joy", 8)) {
+		if (read(joy->hwdata->fd, &gameport, sizeof(gameport)) != sizeof(gameport)) {
+			return;
+		}
+		if (abs(x - gameport.x) > 8) {
+			x = gameport.x;
+			if (x < xmin) {
+				xmin = x;
+			}
+			if (x > xmax) {
+				xmax = x;
+			}
+			if (xmin == xmax) {
+				xmin--;
+				xmax++;
+			}
+			v = (Sint32)x;
+			v -= (xmax + xmin + 1)/2;
+			v *= 32768/((xmax - xmin + 1)/2);
+			SDL_PrivateJoystickAxis(joy, 0, v);
+		}
+		if (abs(y - gameport.y) > 8) {
+			y = gameport.y;
+			if (y < ymin) {
+				ymin = y;
+			}
+			if (y > ymax) {
+				ymax = y;
+			}
+			if (ymin == ymax) {
+				ymin--;
+				ymax++;
+			}
+			v = (Sint32)y;
+			v -= (ymax + ymin + 1)/2;
+			v *= 32768/((ymax - ymin + 1)/2);
+			SDL_PrivateJoystickAxis(joy, 1, v);
+		}
+		if (gameport.b1 != joy->buttons[0]) {
+			SDL_PrivateJoystickButton(joy, 0, gameport.b1);
+		}
+		if (gameport.b2 != joy->buttons[1]) {
+			SDL_PrivateJoystickButton(joy, 1, gameport.b2);
+		}
+		return;
+	}
 	
 	rep = &joy->hwdata->inreport;
 
 	if (read(joy->hwdata->fd, REP_BUF_DATA(rep), rep->size) != rep->size) {
 		return;
 	}
-#ifdef USBHID_NEW
+#if defined(USBHID_NEW) || (defined(__FreeBSD__) && __FreeBSD_version >= 500111)
 	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input, rep->rid);
 #else
 	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input);
@@ -370,8 +437,10 @@
 void
 SDL_SYS_JoystickClose(SDL_Joystick *joy)
 {
-	report_free(&joy->hwdata->inreport);
-	hid_dispose_report_desc(joy->hwdata->repdesc);
+	if (strncmp(joy->hwdata->path, "/dev/joy", 8))	{
+		report_free(&joy->hwdata->inreport);
+		hid_dispose_report_desc(joy->hwdata->repdesc);
+	}
 	close(joy->hwdata->fd);
 	free(joy->hwdata->path);
 	free(joy->hwdata);
@@ -399,11 +468,24 @@
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
