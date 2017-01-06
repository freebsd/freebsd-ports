--- unix/unix.cpp	2007-04-28 19:51:08.000000000 -0500
+++ unix/unix.cpp	2007-10-03 16:53:16.000000000 -0500
@@ -173,7 +173,7 @@
 #include <fcntl.h>
 #include <sys/time.h>
 /* FIXME: Linux alpha (aristocat) has a broken timercmp. Make testcase */
-#if defined(__linux)
+#if defined(__linux) || defined(__FreeBSD__)
 # ifndef timercmp
 #  define timercmp(tvp, uvp, cmp)\
         ((tvp)->tv_sec cmp (uvp)->tv_sec ||\
@@ -197,7 +197,7 @@
 pthread_mutex_t mutex;
 #endif
 
-#if !defined(NOSOUND) && defined(__linux)
+#if !defined(NOSOUND) && (defined(__linux) || defined(__FreeBSD__))
 #include <sys/soundcard.h>
 #include <sys/mman.h>
 #endif
@@ -210,6 +210,11 @@
 #endif
 #endif
 
+#if defined(__FreeBSD__)
+typedef sig_t SIG_PF;
+#include <err.h>
+#endif
+
 //Breaks sol9 and probably others.
 //#if defined(__sun) && defined(__GNUC__)
 //typedef void (*SIG_PF)();
@@ -233,11 +238,12 @@
 
 #ifdef NETPLAY_SUPPORT
 #include "netplay.h"
-
 #ifdef _DEBUG
 #define NP_DEBUG 2
 #endif
+#endif
 
+#if defined(NETPLAY_SUPPORT) || defined(JOYSTICK_SUPPORT)
 /* accessors into controls.cpp static variables */
 uint16 MovieGetJoypad(int i);
 void MovieSetJoypad(int i, uint16 buttons);
@@ -245,22 +251,86 @@
 /* Joypads status information */
 uint32 old_joypads[8];
 uint32 joypads[8];
-
 #endif
 
 #ifdef JOYSTICK_SUPPORT
+#define        JOYSTICK_MAX_DEVICES    4
+int JoystickShift = 0;
+uint8 js_mod [8] = {0, 0, 0, 0, 0, 0, 0, 0};
 #if defined(__linux)
+#define        JOYSTICK_MAX_BUTTONS    4
 #include <linux/joystick.h>
-uint8 js_mod [8] = {0, 0, 0, 0, 0, 0, 0, 0};
 int js_fd [8] = {-1, -1, -1, -1, -1, -1, -1, -1};
 char *js_device [8] = {"/dev/js0", "/dev/js1", "/dev/js2", "/dev/js3", "/dev/js4", "/dev/js5", "/dev/js6", "/dev/js7" };
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/param.h>
+       
+extern "C" {
+#define class klass
+#include <dev/usb/usb.h>
+#include <dev/usb/usbhid.h>   
+#undef class
+       
+#if __FreeBSD_version < 500111
+#include <libusbhid.h>
+#else
+#include <usbhid.h>
+#endif
+}
+
+#define        JOYSTICK_MAX_BUTTONS    16
+
+#define JOYSTICK_MAP_BUTTON_INITIALIZER                                \
+    {                                                          \
+       SNES_Y_MASK, SNES_B_MASK, SNES_A_MASK,                  \
+       SNES_X_MASK, SNES_TL_MASK, SNES_TR_MASK,                \
+       SNES_TL_MASK, SNES_TR_MASK,                             \
+       SNES_SELECT_MASK, SNES_START_MASK, 0, 0, 0, 0, 0, 0     \
+    }
+
+int js_map_button[JOYSTICK_MAX_BUTTONS][16] = {
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER,
+       JOYSTICK_MAP_BUTTON_INITIALIZER
+};
+char *js_device [4] = {"/dev/uhid0", "/dev/uhid1", "/dev/uhid2", "/dev/uhid3"};
+struct js_range {
+       int min, max, lower_third, higher_third;
+};
+struct js_info {
+       char *buf;
+       int reportlen;
+       int offset;
+       struct js_range x, y;
+       int buttons;
+       struct hid_item *hids;
+       int fd;
+       int joy;
+} js_info[4];
+int js_count = 0;
+#endif
+
 void InitJoysticks ();
 void ReadJoysticks ();
 #endif
 
-#if !defined(NOSOUND) && defined (__linux)
+#if !defined(NOSOUND) && (defined (__linux) || defined(__FreeBSD__))
 #define CONFIGURABLE_SOUND_DEVICE
     char *sound_device = "/dev/dsp";
 #endif
@@ -285,7 +355,7 @@
 const char *inc_format="%03d";
 
 //FIXME: I see no reason not to configureenable this for all Unixen
-#if defined(DEBUGGER) && (defined(__linux) || defined(__sun))
+#if defined(DEBUGGER) && (defined(__linux) || defined(__sun) || defined(__FreeBSD__))
 static void sigbrkhandler(int)
 {
     CPU.Flags |= DEBUG_MODE_FLAG;
@@ -326,22 +396,54 @@
 
 void S9xParseArg (char **argv, int &i, int argc)
 {
+#ifdef JOYSTICK_SUPPORT
     if (strcmp (argv [i], "-j") == 0 ||
 	     strcasecmp (argv [i], "-nojoy") == 0) {
-#ifdef JOYSTICK_SUPPORT
 	Settings.JoystickEnabled = FALSE;
+    } 
+
+#ifdef __FreeBSD__
+    else if (strcasecmp(argv[i], "-joyshift") == 0)
+       JoystickShift = 1;
+#endif
+    else if (strncasecmp(argv[i], "-joydev", sizeof("-joydev") - 1) == 0) {
+       char *end, *snum = argv[i] + sizeof("-joydev") - 1;
+       unsigned long num;
+
+       if (*snum == '\0' || argc < i + 1)
+               S9xUsage();
+       if ((num = strtoul(snum, &end, 10)) < JOYSTICK_MAX_DEVICES &&
+           num > 0 && *end == '\0')
+               js_device[num - 1] = argv[++i];
+       else
+            S9xUsage ();
+        }
+    else if (strncasecmp(argv[i], "-joymap", sizeof("-joymap") - 1) == 0) {
+       static const int button_masks[] = {
+               SNES_A_MASK, SNES_B_MASK, SNES_X_MASK, SNES_Y_MASK,
+               SNES_TL_MASK, SNES_TR_MASK, SNES_START_MASK, SNES_SELECT_MASK
+       };
+       char *end, *snum = argv[i] + sizeof("-joymap") - 1;
+       unsigned long num;
+       int *js_buttons, b;
+
+       if (argc < i + (sizeof(button_masks) / sizeof(int)) || *snum == '\0')
+               S9xUsage();
+       num = strtoul(snum, &end, 10);
+       if (*end != '\0')
+               S9xUsage();
+       if (num == 0 || num > 4)        /* hardcode: max joysticks */
+               S9xUsage();
+       js_buttons = js_map_button[num - 1];
+       for (b = 0; b < (sizeof(button_masks) / sizeof(int)); b++)
+               if ((num = strtoul(argv[++i], &end, 10)) <= 16 && num != 0 &&
+                   *end == '\0')
+                       js_buttons[num - 1] = button_masks[b];
+     }
+
+    else 
 #endif
-    } else if (strncasecmp (argv [i], "-joydev", 7) == 0 && argv[i][7]>='1' && argv[i][7]<='8' && argv[i][8]=='\0')
-    {
-        int j = argv[i][7]-'1';
-	if (i + 1 < argc) {
-#ifdef JOYSTICK_SUPPORT
-	    js_device[j] = argv[++i];
-#else
-            S9xMessage(S9X_WARNING, S9X_USAGE, "Joystick support is not available!");
-#endif
-        } else S9xUsage ();
-    } else if (strcasecmp (argv [i], "-sounddev") == 0) {
+   if (strcasecmp (argv [i], "-sounddev") == 0) {
     if (i + 1 < argc) {
 #if defined(CONFIGURABLE_SOUND_DEVICE)
         sound_device = argv[++i];
@@ -552,7 +654,7 @@
 #if !defined(__MSDOS) && defined(DEBUGGER)
 #if defined(__unix) && !defined(__NeXT__)
     struct sigaction sa;
-#if defined(__linux)
+#if defined(__linux) || defined(__FreeBSD__)
     sa.sa_handler = sigbrkhandler;
 #else
     sa.sa_handler = (SIG_PF) sigbrkhandler;
@@ -770,6 +872,7 @@
 }
 
 #ifdef JOYSTICK_SUPPORT
+#ifdef __linux
 void InitJoysticks ()
 {
 #ifdef JSIOCGVERSION
@@ -854,6 +957,189 @@
     }
 #endif
 }
+#endif
+#if defined(__FreeBSD__)
+
+/*
+ * USB HID code for FreeBSD/NetBSD
+ * Brian Feldman <green@FreeBSD.org>
+ *
+ * Reference used:
+ * X-Mame USB HID joystick driver for NetBSD.
+ *
+ * Written by Krister Walfridsson <cato@df.lth.se>
+ */
+
+int
+InitJoystickFd(int fd, char *dev) {
+       report_desc_t rd;
+       struct hid_data *d;
+       struct hid_item h, new_h;
+       struct js_info *my_info;
+       int reportlen, report_id, is_joystick;
+
+       my_info = &js_info[js_count];
+       rd = hid_get_report_desc(fd);
+       if (rd == 0) {
+               warn("%s", dev);
+               return (-1);
+       }
+       report_id = 0;
+#if __FreeBSD_version < 500111
+       reportlen = hid_report_size(rd, report_id, hid_input);
+#else
+       reportlen = hid_report_size(rd, hid_input, report_id);
+#endif
+       my_info->buf = (char *)malloc(reportlen);
+       if (my_info->buf == NULL)
+               err(1, "malloc");
+       my_info->reportlen = reportlen;
+       my_info->offset = report_id != 0;
+       my_info->buttons = 0;
+       my_info->hids = NULL;
+
+       is_joystick = 0;
+#if __FreeBSD_version < 500111
+       for (d = hid_start_parse(rd, 1 << hid_input);
+#else
+       for (d = hid_start_parse(rd, 1 << hid_input, report_id);
+#endif
+           hid_get_item(d, &h);) {
+               int usage, page, link_it = 0;
+               struct js_range *axis;
+
+               page = HID_PAGE(h.usage);
+               usage = HID_USAGE(h.usage);
+               if (!is_joystick)
+                       is_joystick = (h.kind == hid_collection &&
+                           page == HUP_GENERIC_DESKTOP &&
+                           (usage == HUG_JOYSTICK || usage == HUG_GAME_PAD));
+               if (h.kind != hid_input || !is_joystick)
+                       continue;
+               axis = NULL;
+               if (page == HUP_GENERIC_DESKTOP) {
+                       switch (usage) {
+                       case HUG_X:
+                       case HUG_RX:
+                               axis = &my_info->x;
+                               break;
+                       case HUG_Y:
+                       case HUG_RY:
+                               axis = &my_info->y;
+                               break;
+                       }
+               }
+               if (axis != NULL) {
+                       axis->min = h.logical_minimum;
+                       axis->max = h.logical_maximum;
+                       axis->lower_third = axis->min +
+                          (axis->max - axis->min) / 3;
+                       axis->higher_third = axis->min +
+                          (axis->max - axis->min) * 2 / 3;
+                       link_it = 1;
+               }
+               if (!link_it) {
+                       if (page != HUP_BUTTON || usage > 16)
+                               continue;
+                       if (usage > my_info->buttons)
+                               my_info->buttons = usage;
+               }
+               new_h = h;
+               new_h.next = my_info->hids;
+               my_info->hids = (struct hid_item *)
+                   malloc(sizeof(*my_info->hids));
+               if (my_info->hids == NULL)
+                       err(1, "malloc");
+               *my_info->hids = new_h;
+       }
+       printf("Joystick %s: %d buttons, X range %d - %d, Y range %d - %d\n",
+           dev, my_info->buttons, my_info->x.min, my_info->x.max,
+           my_info->y.min, my_info->y.max);
+       my_info->fd = fd;
+       if (JoystickShift) {
+               my_info->joy = js_count + 1;
+       } else
+               my_info->joy = js_count;
+       return (0);
+}
+
+void
+InitJoysticks() {
+       int i, fd;
+
+       for (i = 0; i < (sizeof(js_device) / sizeof(js_device[0])); i++) {
+               fd = open(js_device[i], O_RDONLY | O_NONBLOCK);
+               if (fd == -1)
+                       continue;
+               if (InitJoystickFd(fd, js_device[i]) == 0)
+                       js_count++;
+               else
+                       close(fd);
+       }
+}
+
+void
+ReadJoysticks() {
+       struct hid_item *h;
+       int page, usage, njoy, joy;
+
+       for (njoy = 0; njoy < js_count; njoy++) {
+               struct js_info *jsi;
+
+               jsi = &js_info[njoy];
+               joy = jsi->joy;
+
+               if (read(jsi->fd, jsi->buf, jsi->reportlen) != jsi->reportlen)
+                       continue;
+               for (h = jsi->hids; h != NULL; h = h->next) {
+                       int d;
+
+                       d = hid_get_data(jsi->buf + jsi->offset, h);
+                       page = HID_PAGE(h->usage);
+                       usage = HID_USAGE(h->usage);
+
+                       switch (page) {
+                       case HUP_GENERIC_DESKTOP:
+                               switch (usage) {
+                               case HUG_X:
+                               case HUG_RX:
+                                       if (d < jsi->x.lower_third) {
+                                               joypads[joy] |= SNES_LEFT_MASK;
+                                               joypads[joy] &= ~SNES_RIGHT_MASK;
+                                       } else if (d < jsi->x.higher_third) {
+                                               joypads[joy] &= ~SNES_LEFT_MASK;
+                                               joypads[joy] &= ~SNES_RIGHT_MASK;
+                                       } else {
+                                               joypads[joy] &= ~SNES_LEFT_MASK;
+                                               joypads[joy] |= SNES_RIGHT_MASK;
+                                       }
+                                       break;
+                               case HUG_Y:
+                               case HUG_RY:
+                                       if (d < jsi->y.lower_third) {
+                                               joypads[joy] |= SNES_UP_MASK;
+                                               joypads[joy] &= ~SNES_DOWN_MASK;
+                                       } else if (d < jsi->y.higher_third) {
+                                               joypads[joy] &= ~SNES_UP_MASK;
+                                               joypads[joy] &= ~SNES_DOWN_MASK;
+                                       } else {
+                                               joypads[joy] &= ~SNES_UP_MASK;
+                                               joypads[joy] |= SNES_DOWN_MASK;
+                                       }
+                                       break;
+                               }
+                               break;
+                       case HUP_BUTTON:
+                               if (d)
+                                       joypads[joy] |= js_map_button[njoy][usage - 1];
+                               else
+                                       joypads[joy] &= ~js_map_button[njoy][usage - 1];
+                               break;
+                       }
+               }
+       }
+}
+#endif // defined(__FreeBSD__)
 #endif // defined (JOYSTICK_SUPPORT)
 
 START_EXTERN_C
@@ -1162,8 +1448,8 @@ void _splitpath(const char *path, char *
 {
   *drive = 0;
 
-  char *slash = strrchr(path, SLASH_CHAR);
-  char *dot = strrchr(path, '.');
+  const char *slash = strrchr(path, SLASH_CHAR);
+  const char *dot = strrchr(path, '.');
 
   if (dot && slash && dot < slash)
   {
@@ -1716,7 +2002,7 @@
 }
 #endif
 
-#if !defined(NOSOUND) && defined(__linux)
+#if !defined(NOSOUND) && (defined(__linux) || defined(__FreeBSD__))
 static int Rates[8] =
 {
     0, 8000, 11025, 16000, 22050, 32000, 44100, 48000
@@ -1847,7 +2133,7 @@
 #endif
 
 
-#if !defined(NOSOUND) && (defined (__linux) || defined (__sun))
+#if !defined(NOSOUND) && (defined (__linux) || defined (__sun) || defined(__FreeBSD__))
 void S9xUnixProcessSound (void)
 {
 }
@@ -1890,7 +2176,7 @@
 }
 #endif
 
-#if !defined(NOSOUND) && (defined (__linux) || defined (__sun))
+#if !defined(NOSOUND) && (defined (__linux) || defined (__sun) || defined(__FreeBSD__))
 void S9xGenerateSound ()
 {
     /* Linux and Sun versions */
@@ -1985,7 +2271,7 @@
     /* If not, this will be called by timer */
     if (Settings.Mute)
         return NULL;
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     audio_buf_info info;
 
     if (!Settings.ThreadSound &&
