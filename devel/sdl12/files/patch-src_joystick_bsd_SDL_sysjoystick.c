--- src/joystick/bsd/SDL_sysjoystick.c.orig	2012-01-19 07:30:06.000000000 +0100
+++ src/joystick/bsd/SDL_sysjoystick.c	2015-05-06 22:52:50.648504057 +0900
@@ -77,12 +77,14 @@
 #include "../SDL_sysjoystick.h"
 #include "../SDL_joystick_c.h"
 
-#define MAX_UHID_JOYS	4
-#define MAX_JOY_JOYS	2
+#define MAX_UHID_JOYS	16
+#define MAX_JOY_JOYS	8
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
@@ -161,15 +165,40 @@
 {
 	char s[16];
 	int i, fd;
+	SDL_Joystick nj;
 
 	SDL_numjoysticks = 0;
 
 	SDL_memset(joynames, 0, sizeof(joynames));
 	SDL_memset(joydevnames, 0, sizeof(joydevnames));
 
-	for (i = 0; i < MAX_UHID_JOYS; i++) {
-		SDL_Joystick nj;
+	/* First see if the user specified one or more joysticks to use */
+	if (NULL != SDL_getenv("SDL_JOYSTICK_DEVICE")) {
+		char *envcopy, *envpath, *delim;
+		envcopy = SDL_strdup(SDL_getenv("SDL_JOYSTICK_DEVICE"));
+		envpath = envcopy;
+		while (NULL != envpath) {
+			delim = SDL_strchr(envpath, ':');
+			if (NULL != delim) {
+				*delim ++ = '\0';
+			}
+
+			nj.index = SDL_numjoysticks;
+			joynames[nj.index] = strdup(envpath);
+
+			if (0 == SDL_SYS_JoystickOpen(&nj)) {
+				SDL_SYS_JoystickClose(&nj);
+				SDL_numjoysticks ++;
+			} else {
+				SDL_free(joynames[nj.index]);
+				joynames[nj.index] = NULL;
+			}
+			envpath = delim;
+		}
+		SDL_free(envcopy);
+	}
 
+	for (i = 0; i < MAX_UHID_JOYS; i++) {
 		SDL_snprintf(s, SDL_arraysize(s), "/dev/uhid%d", i);
 
 		nj.index = SDL_numjoysticks;
@@ -253,13 +282,12 @@
 int
 SDL_SYS_JoystickOpen(SDL_Joystick *joy)
 {
-	char *path = joynames[joy->index];
+	char *path = joynames[joy->index], *sp, *s;
 	struct joystick_hwdata *hw;
 	struct hid_item hitem;
 	struct hid_data *hdata;
 	struct report *rep;
-	int fd;
-	int i;
+	int i, fd;
 
 	fd = open(path, O_RDONLY);
 	if (fd == -1) {
@@ -282,6 +310,9 @@
 	hw->ymin = 0xffff;
 	hw->xmax = 0;
 	hw->ymax = 0;
+	for (i = 0; i < JOYAXE_count; i ++) {
+		hw->axis_map[i] = -1;
+	}
 	if (! SDL_strncmp(path, "/dev/joy", 8)) {
 		hw->type = BSDJOY_JOY;
 		joy->naxes = 2;
@@ -292,13 +323,12 @@
 		goto usbend;
 	} else {
 		hw->type = BSDJOY_UHID;
+		sp = SDL_malloc(32);
+		SDL_snprintf(sp, 32, "Gamepad/Joystick (%d)", joy->index);
+		SDL_free(joydevnames[joy->index]);
+		joydevnames[joy->index] = sp;
 	}
 
-	{
-	    int ax;
-	    for (ax = 0; ax < JOYAXE_count; ax++)
-		hw->axis_map[ax] = -1;
-	}
 	hw->repdesc = hid_get_report_desc(fd);
 	if (hw->repdesc == NULL) {
 		SDL_SetError("%s: USB_GET_REPORT_DESC: %s", hw->path,
@@ -307,8 +337,8 @@
 	}
 	rep = &hw->inreport;
 #if defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063) || defined(__FreeBSD_kernel__)
-       rep->rid = hid_get_report_id(fd);
-       if (rep->rid < 0) {
+	rep->rid = hid_get_report_id(fd);
+	if (rep->rid < 0) {
 #else
 	if (ioctl(fd, USB_GET_REPORT_ID, &rep->rid) < 0) {
 #endif
@@ -336,13 +366,8 @@
 	joy->nbuttons = 0;
 	joy->nhats = 0;
 	joy->nballs = 0;
-	for (i=0; i<JOYAXE_count; i++)
-		hw->axis_map[i] = -1;
 
 	while (hid_get_item(hdata, &hitem) > 0) {
-		char *sp;
-		const char *s;
-
 		switch (hitem.kind) {
 		case hid_collection:
 			switch (HID_PAGE(hitem.usage)) {
@@ -351,9 +376,10 @@
 				case HUG_JOYSTICK:
 				case HUG_GAME_PAD:
 					s = hid_usage_in_page(hitem.usage);
-					sp = SDL_malloc(SDL_strlen(s) + 5);
-					SDL_snprintf(sp, SDL_strlen(s) + 5, "%s (%d)", s,
+					sp = SDL_malloc(SDL_strlen(s) + 8);
+					SDL_snprintf(sp, SDL_strlen(s) + 8, "%s (%d)", s,
 					    joy->index);
+					SDL_free(joydevnames[joy->index]);
 					joydevnames[joy->index] = sp;
 				}
 			}
@@ -361,24 +387,20 @@
 		case hid_input:
 			switch (HID_PAGE(hitem.usage)) {
 			case HUP_GENERIC_DESKTOP: {
-			    unsigned usage = HID_USAGE(hitem.usage);
-			    int joyaxe = usage_to_joyaxe(usage);
-			    if (joyaxe >= 0) {
-				hw->axis_map[joyaxe] = 1;
-			    } else if (usage == HUG_HAT_SWITCH) {
-				joy->nhats++;
-			    }
-			    break;
+				unsigned usage = HID_USAGE(hitem.usage);
+				int joyaxe = usage_to_joyaxe(usage);
+				if (joyaxe >= 0) {
+					hw->axis_map[joyaxe] = 1;
+				} else if (usage == HUG_HAT_SWITCH) {
+					joy->nhats++;
+				}
+				break;
 			}
 			case HUP_BUTTON:
 				joy->nbuttons++;
 				break;
-			default:
-				break;
 			}
 			break;
-		default:
-			break;
 		}
 	}
 	hid_end_parse(hdata);
@@ -386,6 +408,12 @@
 		if (hw->axis_map[i] > 0)
 			hw->axis_map[i] = joy->naxes++;
 
+	if (0 == joy->naxes &&
+	    0 == joy->nbuttons &&
+	    0 == joy->nhats &&
+	    0 == joy->nballs)
+		goto usberr;
+
 usbend:
 	/* The poll blocks the event thread. */
 	fcntl(fd, F_SETFL, O_NONBLOCK);
@@ -411,47 +439,47 @@
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
@@ -459,65 +487,61 @@
 	
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
+						naxe = joy->hwdata->axis_map[joyaxe];
+						/* scaleaxe */
+						v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
+									 &hitem);
+						v -= (hitem.logical_maximum + hitem.logical_minimum + 1)/2;
+						v *= 32768/((hitem.logical_maximum - hitem.logical_minimum + 1)/2);
+						if (v != joy->axes[naxe]) {
+							SDL_PrivateJoystickAxis(joy, naxe, v);
+						}
+					} else if (usage == HUG_HAT_SWITCH) {
+						v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
+									 &hitem);
+						SDL_PrivateJoystickHat(joy, 0,
+							hatval_to_sdl(v)-hitem.logical_minimum);
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
@@ -582,8 +606,12 @@
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
