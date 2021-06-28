--- src/x11/fg_joystick_x11.c.orig	2021-03-21 08:11:11 UTC
+++ src/x11/fg_joystick_x11.c
@@ -41,196 +41,135 @@
 
 #include <fcntl.h>
 
+/*this should be defined in a header file */
+#define MAX_NUM_JOYSTICKS  2
 
-/* BSD defines from "jsBSD.cxx" around lines 42-270 */
-
 #if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-
-#    ifdef HAVE_USB_JS
-#        if defined(__NetBSD__)
-#            ifdef HAVE_USBHID_H
-#                include <usbhid.h>
-#            else
-#                include <usb.h>
-#            endif
-#            include <dev/usb/usb.h>
-#        elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-#            ifdef HAVE_USBHID_H
-#                include <usbhid.h>
-#            else
-#                include <libusbhid.h>
-#            endif
-#            include <legacy/dev/usb/usb.h>
-#        endif
-#        include <dev/usb/usbhid.h>
-
-/* Compatibility with older usb.h revisions */
-#        if !defined(USB_MAX_DEVNAMES) && defined(MAXDEVNAMES)
-#            define USB_MAX_DEVNAMES MAXDEVNAMES
-#        endif
-#    endif
-
-struct os_specific_s {
-  char             fname [128 ];
-  int              fd;
-  int              is_analog;
-  /* The following structure members are specific to analog joysticks */
-  struct joystick  ajs;
-#    ifdef HAVE_USB_JS
-  /* The following structure members are specific to USB joysticks */
-  struct hid_item *hids;
-  int              hid_dlen;
-  int              hid_offset;
-  char            *hid_data_buf;
-  int              axes_usage [ _JS_MAX_AXES ];
-#    endif
-  /* We keep button and axes state ourselves, as they might not be updated
-   * on every read of a USB device
-   */
-  int              cache_buttons;
-  float            cache_axes [ _JS_MAX_AXES ];
-};
-
-/* Idents lower than USB_IDENT_OFFSET are for analog joysticks. */
-#    define USB_IDENT_OFFSET    2
-
-#    define USBDEV "/dev/usb"
-#    define UHIDDEV "/dev/uhid"
-#    define AJSDEV "/dev/joy"
-
-
-#endif
-
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-static int hatmap_x[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
-static int hatmap_y[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
-
-#    ifdef HAVE_USB_JS
+#  ifdef HAVE_USB_JS
 /*
-* fghJoystickFindUSBdev (and its helper, fghJoystickWalkUSBdev) try to locate
-* the full name of a USB device. If /dev/usbN isn't readable, we punt and
-* return the uhidN device name. We warn the user of this situation once.
-*/
+ * fghJoystickFindUSBdev (and its helper, fghJoystickWalkUSBdev) try to locate
+ * the full name of a USB device. If /dev/usbN isn't readable, we punt and
+ * return the uhidN device name. We warn the user of this situation once.
+ */
 static char *fghJoystickWalkUSBdev(int f, char *dev, char *out, int outlen)
 {
-    struct usb_device_info di;
-    int i, a;
-    char *cp;
+#if __FreeBSD_version < 800061
+  struct usb_device_info di;
+  int i, a;
+  char *cp;
 
-    for (a = 1; a < USB_MAX_DEVICES; a++) {
-        di.udi_addr = a;
-        if (ioctl(f, USB_DEVICEINFO, &di) != 0)
-            return NULL;
-        for (i = 0; i < USB_MAX_DEVNAMES; i++)
-            if (di.udi_devnames[i][0] &&
-                strcmp(di.udi_devnames[i], dev) == 0) {
-                cp = calloc(1, strlen(di.udi_vendor) + strlen(di.udi_product) + 2);
-                strcpy(cp, di.udi_vendor);
-                strcat(cp, " ");
-                strcat(cp, di.udi_product);
-                strncpy(out, cp, outlen - 1);
-                out[outlen - 1] = 0;
-                free(cp);
-                return out;
-            }
-    }
-    return NULL;
+  for (a = 1; a < USB_MAX_DEVICES; a++) {
+    di.udi_addr = a;
+    if (ioctl(f, USB_DEVICEINFO, &di) != 0)
+      return NULL;
+    for (i = 0; i < USB_MAX_DEVNAMES; i++)
+      if (di.udi_devnames[i][0] &&
+          strcmp(di.udi_devnames[i], dev) == 0) {
+        cp =  calloc( 1, strlen(di.udi_vendor) + strlen(di.udi_product) + 2);
+        strcpy(cp, di.udi_vendor);
+        strcat(cp, " ");
+        strcat(cp, di.udi_product);
+        strncpy(out, cp, outlen - 1);
+        out[outlen - 1] = 0;
+        free( cp );
+        return out;
+      }
+  }
+#endif
+  return NULL;
 }
 
 static int fghJoystickFindUSBdev(char *name, char *out, int outlen)
 {
-    int i, f;
-    char buf[50];
-    char *cp;
-    static int protection_warned = 0;
+  int i, f;
+  char buf[50];
+  char *cp;
+  static int protection_warned = 0;
 
-    for (i = 0; i < 16; i++) {
-        snprintf(buf, sizeof(buf), "%s%d", USBDEV, i);
-        f = open(buf, O_RDONLY);
-        if (f >= 0) {
-            cp = fghJoystickWalkUSBdev(f, name, out, outlen);
-            close(f);
-            if (cp)
-                return 1;
-        }
-        else if (errno == EACCES) {
-            if (!protection_warned) {
-                fgWarning("Can't open %s for read!", buf);
-                protection_warned = 1;
-            }
-        }
+  for (i = 0; i < 16; i++) {
+    snprintf(buf, sizeof(buf), "%s%d", USBDEV, i);
+    f = open(buf, O_RDONLY);
+    if (f >= 0) {
+      cp = fghJoystickWalkUSBdev(f, name, out, outlen);
+      close(f);
+      if (cp)
+        return 1;
     }
-    return 0;
+    else if (errno == EACCES) {
+      if (!protection_warned) {
+        fgWarning ( "Can't open %s for read!", buf );
+        protection_warned = 1;
+      }
+    }
+  }
+  return 0;
 }
-#endif
 
 static int fghJoystickInitializeHID(struct os_specific_s *os,
-                                    int *num_axes, int *num_buttons)
+       int *num_axes, int *num_buttons)
 {
     int size, is_joystick;
 #   ifdef HAVE_USBHID_H
-    int report_id = 0;
+        int report_id = 0;
 #   endif
     struct hid_data *d;
     struct hid_item h;
     report_desc_t rd;
 
-    if ((rd = hid_get_report_desc(os->fd)) == 0)
+    if ( ( rd = hid_get_report_desc( os->fd ) ) == 0 )
     {
-        fgWarning("error: %s: %s", os->fname, strerror(errno));
+        fgWarning ( "error: %s: %s", os->fname, strerror( errno ) );
         return FALSE;
     }
 
     os->hids = NULL;
 
 #   ifdef HAVE_USBHID_H
-    if (ioctl(os->fd, USB_GET_REPORT_ID, &report_id) < 0)
-    {
-        /*** XXX {report_id} may not be the right variable? ***/
-        fgWarning("error: %s%d: %s", UHIDDEV, report_id, strerror(errno));
-        return FALSE;
-    }
+        if( ioctl( os->fd, USB_GET_REPORT_ID, &report_id ) < 0)
+        {
+            /*** XXX {report_id} may not be the right variable? ***/
+            fgWarning ( "error: %s%d: %s", UHIDDEV, report_id, strerror( errno ) );
+            return FALSE;
+        }
 
-    size = hid_report_size(rd, hid_input, report_id);
+        size = hid_report_size( rd, hid_input, report_id );
 #   else
-    size = hid_report_size(rd, 0, hid_input);
+        size = hid_report_size( rd, 0, hid_input );
 #   endif
-    os->hid_data_buf = calloc(1, size);
+    os->hid_data_buf = calloc( 1, size );
     os->hid_dlen = size;
 
     is_joystick = 0;
 #   ifdef HAVE_USBHID_H
-    d = hid_start_parse(rd, 1 << hid_input, report_id);
+        d = hid_start_parse( rd, 1 << hid_input, report_id );
 #   else
-    d = hid_start_parse(rd, 1 << hid_input);
+        d = hid_start_parse( rd, 1 << hid_input );
 #   endif
-    while (hid_get_item(d, &h))
-    {
-        int usage, page, interesting_hid;
+        while( hid_get_item( d, &h ) )
+        {
+            int usage, page, interesting_hid;
 
-        page = HID_PAGE(h.usage);
-        usage = HID_USAGE(h.usage);
+            page = HID_PAGE( h.usage );
+            usage = HID_USAGE( h.usage );
 
-        /* This test is somewhat too simplistic, but this is how MicroSoft
-        * does, so I guess it works for all joysticks/game pads. */
-        is_joystick = is_joystick ||
-            (h.kind == hid_collection &&
-             page == HUP_GENERIC_DESKTOP &&
-             (usage == HUG_JOYSTICK || usage == HUG_GAME_PAD));
+            /* This test is somewhat too simplistic, but this is how MicroSoft
+             * does, so I guess it works for all joysticks/game pads. */
+            is_joystick = is_joystick ||
+                ( h.kind == hid_collection &&
+                  page == HUP_GENERIC_DESKTOP &&
+                  ( usage == HUG_JOYSTICK || usage == HUG_GAME_PAD ) );
 
-        if (h.kind != hid_input)
-            continue;
+            if( h.kind != hid_input )
+                continue;
 
-        if (!is_joystick)
-            continue;
+            if( !is_joystick )
+                continue;
 
-        interesting_hid = TRUE;
-        if (page == HUP_GENERIC_DESKTOP)
-        {
-            switch (usage)
+            interesting_hid = TRUE;
+            if( page == HUP_GENERIC_DESKTOP )
             {
+                switch( usage )
+                {
                 case HUG_X:
                 case HUG_RX:
                 case HUG_Y:
@@ -238,53 +177,51 @@ static int fghJoystickInitializeHID(struct os_specific
                 case HUG_Z:
                 case HUG_RZ:
                 case HUG_SLIDER:
-                    if (*num_axes < _JS_MAX_AXES)
+                    if( *num_axes < _JS_MAX_AXES )
                     {
-                        os->axes_usage[*num_axes] = usage;
-                        (*num_axes)++;
+                        os->axes_usage[ *num_axes ] = usage;
+                        ( *num_axes )++;
                     }
                     break;
                 case HUG_HAT_SWITCH:
                     /* Allocate two axes for a hat */
-                    if (*num_axes + 1 < _JS_MAX_AXES)
+                    if( *num_axes + 1 < _JS_MAX_AXES )
                     {
-                        os->axes_usage[*num_axes] = usage;
+                        os->axes_usage[ *num_axes ] = usage;
                         (*num_axes)++;
-                        os->axes_usage[*num_axes] = usage;
+                        os->axes_usage[ *num_axes ] = usage;
                         (*num_axes)++;
                     }
                     break;
                 default:
                     interesting_hid = FALSE;
                     break;
+                }
             }
-        }
-        else if (page == HUP_BUTTON)
-        {
-            interesting_hid = (usage > 0) &&
-                (usage <= _JS_MAX_BUTTONS);
+            else if( page == HUP_BUTTON )
+            {
+                interesting_hid = ( usage > 0 ) &&
+                    ( usage <= _JS_MAX_BUTTONS );
 
-            if (interesting_hid && usage - 1 > *num_buttons)
-                *num_buttons = usage - 1;
-        }
+                if( interesting_hid && usage - 1 > *num_buttons )
+                    *num_buttons = usage - 1;
+            }
 
-        if (interesting_hid)
-        {
-            h.next = os->hids;
-            os->hids = calloc(1, sizeof(struct hid_item));
-            *os->hids = h;
+            if( interesting_hid )
+            {
+                h.next = os->hids;
+                os->hids = calloc( 1, sizeof ( struct hid_item ) );
+                *os->hids = h;
+            }
         }
-    }
-    hid_end_parse(d);
+        hid_end_parse( d );
 
-    return os->hids != NULL;
+        return os->hids != NULL;
 }
-#    endif
-#endif
+#  endif /* HAVE_USB_JS */
+#endif /* FreeBSD or NetBSD */
 
 
-/*this should be defined in a header file */
-#define MAX_NUM_JOYSTICKS  2
 extern SFG_Joystick *fgJoystick [ MAX_NUM_JOYSTICKS ];
 
 void fgPlatformJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes )
@@ -500,7 +437,7 @@ void fgPlatformJoystickOpen( SFG_Joystick* joy )
         joy->num_axes    =  2;
         joy->num_buttons = 32;
 
-        fghJoystickRawRead( joy, buttons, axes );
+        fgJoystickRawRead( joy, buttons, axes );
         joy->error = axes[ 0 ] < -1000000000.0f;
         if( joy->error )
             return;
@@ -620,7 +557,7 @@ void fgPlatformJoystickOpen( SFG_Joystick* joy )
 
     do
     {
-        fghJoystickRawRead( joy, NULL, joy->center );
+        fgJoystickRawRead( joy, NULL, joy->center );
         counter++;
     } while( !joy->error &&
              counter < 100 &&
@@ -647,6 +584,23 @@ void fgPlatformJoystickOpen( SFG_Joystick* joy )
 #endif
 }
 
+void fgJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes )
+{
+    int i;
+
+    /* Defaults */
+    if( buttons )
+        *buttons = 0;
+
+    if( axes )
+        for( i = 0; i < joy->num_axes; i++ )
+            axes[ i ] = 1500.0f;
+
+    if( joy->error )
+        return;
+
+	fgPlatformJoystickRawRead ( joy, buttons, axes );
+}
 
 void fgPlatformJoystickInit( SFG_Joystick *fgJoystick[], int ident )
 {
