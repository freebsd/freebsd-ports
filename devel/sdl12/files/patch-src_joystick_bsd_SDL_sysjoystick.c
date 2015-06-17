--- src/joystick/bsd/SDL_sysjoystick.c.orig	2012-01-19 07:30:06.000000000 +0100
+++ src/joystick/bsd/SDL_sysjoystick.c	2015-05-06 22:52:50.648504057 +0900
@@ -82,7 +82,9 @@
 #define MAX_JOYS	(MAX_UHID_JOYS + MAX_JOY_JOYS)
 
 struct report {
-#if defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063)
+#if defined(__FREEBSD__) && (__FreeBSD_kernel_version > 900000)
+	void *buf;			/* Buffer */
+#elif defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063)
 	struct	usb_gen_descriptor *buf;	/* Buffer */
 #else
 	struct	usb_ctl_report *buf;	/* Buffer */
@@ -148,8 +150,10 @@
 static int	report_alloc(struct report *, struct report_desc *, int);
 static void	report_free(struct report *);
 
-#if defined(USBHID_UCR_DATA) || defined(__FreeBSD_kernel__)
+#if defined(USBHID_UCR_DATA) || (defined(__FreeBSD_kernel__) && __FreeBSD_kernel_version <= 800063)
 #define REP_BUF_DATA(rep) ((rep)->buf->ucr_data)
+#elif (defined(__FREEBSD__) && (__FreeBSD_kernel_version > 900000))
+#define REP_BUF_DATA(rep) ((rep)->buf)
 #elif (defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063))
 #define REP_BUF_DATA(rep) ((rep)->buf->ugd_data)
 #else
@@ -411,47 +415,47 @@
 	struct joystick gameport;
  
 	if (joy->hwdata->type == BSDJOY_JOY) {
-		if (read(joy->hwdata->fd, &gameport, sizeof gameport) != sizeof gameport)
-			return;
-		if (abs(joy->hwdata->x - gameport.x) > 8) {
-			joy->hwdata->x = gameport.x;
-			if (joy->hwdata->x < joy->hwdata->xmin) {
-				joy->hwdata->xmin = joy->hwdata->x;
-			}
-			if (joy->hwdata->x > joy->hwdata->xmax) {
-				joy->hwdata->xmax = joy->hwdata->x;
-			}
-			if (joy->hwdata->xmin == joy->hwdata->xmax) {
-				joy->hwdata->xmin--;
-				joy->hwdata->xmax++;
-			}
-			v = (Sint32)joy->hwdata->x;
-			v -= (joy->hwdata->xmax + joy->hwdata->xmin + 1)/2;
-			v *= 32768/((joy->hwdata->xmax - joy->hwdata->xmin + 1)/2);
-			SDL_PrivateJoystickAxis(joy, 0, v);
-		}
-		if (abs(joy->hwdata->y - gameport.y) > 8) {
-			joy->hwdata->y = gameport.y;
-			if (joy->hwdata->y < joy->hwdata->ymin) {
-				joy->hwdata->ymin = joy->hwdata->y;
+		while (read(joy->hwdata->fd, &gameport, sizeof gameport) == sizeof gameport) {
+			if (abs(joy->hwdata->x - gameport.x) > 8) {
+				joy->hwdata->x = gameport.x;
+				if (joy->hwdata->x < joy->hwdata->xmin) {
+					joy->hwdata->xmin = joy->hwdata->x;
+				}
+				if (joy->hwdata->x > joy->hwdata->xmax) {
+					joy->hwdata->xmax = joy->hwdata->x;
+				}
+				if (joy->hwdata->xmin == joy->hwdata->xmax) {
+					joy->hwdata->xmin--;
+					joy->hwdata->xmax++;
+				}
+				v = (Sint32)joy->hwdata->x;
+				v -= (joy->hwdata->xmax + joy->hwdata->xmin + 1)/2;
+				v *= 32768/((joy->hwdata->xmax - joy->hwdata->xmin + 1)/2);
+				SDL_PrivateJoystickAxis(joy, 0, v);
+			}
+			if (abs(joy->hwdata->y - gameport.y) > 8) {
+				joy->hwdata->y = gameport.y;
+				if (joy->hwdata->y < joy->hwdata->ymin) {
+					joy->hwdata->ymin = joy->hwdata->y;
+				}
+				if (joy->hwdata->y > joy->hwdata->ymax) {
+					joy->hwdata->ymax = joy->hwdata->y;
+				}
+				if (joy->hwdata->ymin == joy->hwdata->ymax) {
+					joy->hwdata->ymin--;
+					joy->hwdata->ymax++;
+				}
+				v = (Sint32)joy->hwdata->y;
+				v -= (joy->hwdata->ymax + joy->hwdata->ymin + 1)/2;
+				v *= 32768/((joy->hwdata->ymax - joy->hwdata->ymin + 1)/2);
+				SDL_PrivateJoystickAxis(joy, 1, v);
 			}
-			if (joy->hwdata->y > joy->hwdata->ymax) {
-				joy->hwdata->ymax = joy->hwdata->y;
+			if (gameport.b1 != joy->buttons[0]) {
+				SDL_PrivateJoystickButton(joy, 0, gameport.b1);
 			}
-			if (joy->hwdata->ymin == joy->hwdata->ymax) {
-				joy->hwdata->ymin--;
-				joy->hwdata->ymax++;
+			if (gameport.b2 != joy->buttons[1]) {
+				SDL_PrivateJoystickButton(joy, 1, gameport.b2);
 			}
-			v = (Sint32)joy->hwdata->y;
-			v -= (joy->hwdata->ymax + joy->hwdata->ymin + 1)/2;
-			v *= 32768/((joy->hwdata->ymax - joy->hwdata->ymin + 1)/2);
-			SDL_PrivateJoystickAxis(joy, 1, v);
-		}
-		if (gameport.b1 != joy->buttons[0]) {
-			SDL_PrivateJoystickButton(joy, 0, gameport.b1);
-		}
-		if (gameport.b2 != joy->buttons[1]) {
-			SDL_PrivateJoystickButton(joy, 1, gameport.b2);
 		}
 		return;
 	}
@@ -459,65 +463,61 @@
 	
 	rep = &joy->hwdata->inreport;
 
-	if (read(joy->hwdata->fd, REP_BUF_DATA(rep), rep->size) != rep->size) {
-		return;
-	}
+	while (read(joy->hwdata->fd, REP_BUF_DATA(rep), rep->size) == rep->size) {
 #if defined(USBHID_NEW) || (defined(__FREEBSD__) && __FreeBSD_kernel_version >= 500111) || defined(__FreeBSD_kernel__)
-	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input, rep->rid);
+		hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input, rep->rid);
 #else
-	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input);
+		hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input);
 #endif
-	if (hdata == NULL) {
-		fprintf(stderr, "%s: Cannot start HID parser\n",
-		    joy->hwdata->path);
-		return;
-	}
+		if (hdata == NULL) {
+			/*fprintf(stderr, "%s: Cannot start HID parser\n", joy->hwdata->path);*/
+			continue;
+		}
 
-	for (nbutton = 0; hid_get_item(hdata, &hitem) > 0;) {
-		switch (hitem.kind) {
-		case hid_input:
-			switch (HID_PAGE(hitem.usage)) {
-			case HUP_GENERIC_DESKTOP: {
-			    unsigned usage = HID_USAGE(hitem.usage);
-			    int joyaxe = usage_to_joyaxe(usage);
-			    if (joyaxe >= 0) {
-				naxe = joy->hwdata->axis_map[joyaxe];
-				/* scaleaxe */
-				v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
-							 &hitem);
-				v -= (hitem.logical_maximum + hitem.logical_minimum + 1)/2;
-				v *= 32768/((hitem.logical_maximum - hitem.logical_minimum + 1)/2);
-				if (v != joy->axes[naxe]) {
-				    SDL_PrivateJoystickAxis(joy, naxe, v);
+		for (nbutton = 0; hid_get_item(hdata, &hitem) > 0;) {
+			switch (hitem.kind) {
+			case hid_input:
+				switch (HID_PAGE(hitem.usage)) {
+				case HUP_GENERIC_DESKTOP: {
+					unsigned usage = HID_USAGE(hitem.usage);
+					int joyaxe = usage_to_joyaxe(usage);
+					if (joyaxe >= 0) {
+					naxe = joy->hwdata->axis_map[joyaxe];
+					/* scaleaxe */
+					v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
+								 &hitem);
+					v -= (hitem.logical_maximum + hitem.logical_minimum + 1)/2;
+					v *= 32768/((hitem.logical_maximum - hitem.logical_minimum + 1)/2);
+					if (v != joy->axes[naxe]) {
+						SDL_PrivateJoystickAxis(joy, naxe, v);
+					}
+					} else if (usage == HUG_HAT_SWITCH) {
+					v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
+								 &hitem);
+					SDL_PrivateJoystickHat(joy, 0,
+						hatval_to_sdl(v)-hitem.logical_minimum);
+					}
+					break;
 				}
-			    } else if (usage == HUG_HAT_SWITCH) {
-				v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
-							 &hitem);
-				SDL_PrivateJoystickHat(joy, 0,
-					hatval_to_sdl(v)-hitem.logical_minimum);
-			    }
-			    break;
-			}
-			case HUP_BUTTON:
-				v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
-				    &hitem);
-				if (joy->buttons[nbutton] != v) {
-					SDL_PrivateJoystickButton(joy,
-					    nbutton, v);
+				case HUP_BUTTON:
+					v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
+						&hitem);
+					if (joy->buttons[nbutton] != v) {
+						SDL_PrivateJoystickButton(joy,
+							nbutton, v);
+					}
+					nbutton++;
+					break;
+				default:
+					continue;
 				}
-				nbutton++;
 				break;
 			default:
-				continue;
+				break;
 			}
-			break;
-		default:
-			break;
 		}
+		hid_end_parse(hdata);
 	}
-	hid_end_parse(hdata);
-
-	return;
 }
 
 /* Function to close a joystick after use */
@@ -582,8 +582,12 @@
 	r->size = len;
 
 	if (r->size > 0) {
+#if defined(__FREEBSD__) && (__FreeBSD_kernel_version > 900000)
+		r->buf = SDL_malloc(r->size);
+#else
 		r->buf = SDL_malloc(sizeof(*r->buf) - sizeof(REP_BUF_DATA(r)) +
 		    r->size);
+#endif
 		if (r->buf == NULL) {
 			SDL_OutOfMemory();
 			return (-1);
