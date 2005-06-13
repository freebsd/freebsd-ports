--- src/tpb.c.orig	Sun Aug 22 15:45:11 2004
+++ src/tpb.c	Mon Jun 13 17:31:34 2005
@@ -34,6 +34,10 @@
 #include <unistd.h>
 #include "config.h"
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
+
 #if ENABLE_NLS
 #include <libintl.h>
 #endif /* ENABLE_NLS */
@@ -163,6 +167,9 @@
   /* to initialize struct */
   memset(&last_thinkpad_state, 0x00, sizeof(t_thinkpad_state));
   if(get_nvram_state(&thinkpad_state) != 0) {
+#ifdef __FreeBSD__
+    fprintf(stderr, _("acpi_ibm(4) driver not loaded. Exiting..."));
+#endif
     _exit(1);
   }
   if(cfg.apm == STATE_ON) {
@@ -449,6 +456,25 @@
 #endif /* HAVE_LIBXOSD */
     } /* }}} */
 
+    /* determine the state of Bluetooth {{{ */
+    if(thinkpad_state.bluetooth_toggle != last_thinkpad_state.bluetooth_toggle) {
+      if(cfg.verbose == STATE_ON) {
+        printf(_("Bluetooth is %s\n"), thinkpad_state.bluetooth_toggle == 1 ? _("on") : _("off"));
+      }
+      if(cfg.callback != NULL) {
+        snprintf(callback_cmd, sizeof(callback_cmd), "%s bluetooth %s", cfg.callback, thinkpad_state.bluetooth_toggle == 1 ? "on" : "off");
+        if(fork_app(callback_cmd) != 0) {
+          _exit(0);
+        }
+      }
+#ifdef HAVE_LIBXOSD
+      if(osd_ptr != NULL) {
+        xosd_display(osd_ptr, 0, XOSD_string, thinkpad_state.bluetooth_toggle == 1 ? _("Bluetooth enabled") : _("Bluetooth disabled"));
+        xosd_display(osd_ptr, 1, XOSD_string, "");
+      }
+#endif /* HAVE_LIBXOSD */
+    } /* }}} */
+
     /* determine the state of display  {{{ */
     if((thinkpad_state.display_toggle != last_thinkpad_state.display_toggle ||
 	thinkpad_state.display_state != last_thinkpad_state.display_state) &&
@@ -972,6 +998,7 @@
 /* get the current state from the nvram */
 int get_nvram_state(t_thinkpad_state *thinkpad_state) /* {{{ */
 {
+#ifndef __FreeBSD__
   static int fdsc = -1; /* -1 -> file not opened */
   unsigned char buffer[114];
   struct {
@@ -1030,13 +1057,52 @@
   thinkpad_state->mute_toggle       = (thinkpad_state->mute_toggle       & ~0x01) | (( buffer[0x60] & 0x40) >> 6);
   thinkpad_state->powermgt_ac       =                                               (( buffer[0x39] & 0x07)     );
   thinkpad_state->powermgt_battery  =                                               (( buffer[0x39] & 0x38) >> 3);
+#else
+  u_int n = 0;
+  size_t len = sizeof(n);
+  if ( sysctlbyname("dev.acpi_ibm.0.hotkey", &n, &len, NULL, 0) == -1 )
+    return -1;
 
+  thinkpad_state->thinkpad_toggle   = (thinkpad_state->thinkpad_toggle   & ~0x01) | (( n & (1<<3)) >> 3);
+  thinkpad_state->zoom_toggle       = (thinkpad_state->zoom_toggle       & ~0x01) | (( n & (1<<4)) >> 4);
+  thinkpad_state->display_toggle    = (thinkpad_state->display_toggle    & ~0x01) | (( n & (1<<6)) >> 6);
+  thinkpad_state->home_toggle       = (thinkpad_state->home_toggle       & ~0x01) | (( n & (1<<0))     );
+  thinkpad_state->search_toggle     = (thinkpad_state->search_toggle     & ~0x01) | (( n & (1<<1)) >> 1);
+  thinkpad_state->mail_toggle       = (thinkpad_state->mail_toggle       & ~0x01) | (( n & (1<<2)) >> 2);
+  thinkpad_state->hibernate_toggle  = (thinkpad_state->hibernate_toggle  & ~0x01) | (( n & (1<<7)) >> 7);
+  thinkpad_state->expand_toggle     = (thinkpad_state->expand_toggle     & ~0x01) | (( n & (1<<9)) >> 9);
+  thinkpad_state->brightness_toggle = (thinkpad_state->brightness_toggle & ~0x01) | (( n & (1<<10)) >> 10);
+  thinkpad_state->volume_toggle     = (thinkpad_state->volume_toggle     & ~0x01) | (( n & (1<<11)) >> 11);
+
+  /* Don't fail if the wlan, bluetooth or thinklight sysctls are not present. They are generated dynamically */
+  if ( sysctlbyname("dev.acpi_ibm.0.wlan", &n, &len, NULL, 0) != -1 )
+    thinkpad_state->wireless_toggle = n;
+
+  if ( sysctlbyname("dev.acpi_ibm.0.bluetooth", &n, &len, NULL, 0) != -1 )
+    thinkpad_state->bluetooth_toggle = n;
+
+  if ( sysctlbyname("dev.acpi_ibm.0.thinklight", &n, &len, NULL, 0) != -1 )
+    thinkpad_state->thinklight_toggle = n;
+
+  if ( sysctlbyname("dev.acpi_ibm.0.lcd_brightness", &n, &len, NULL, 0) == -1 )
+    return -1;
+  thinkpad_state->brightness_level = n;
+
+  if ( sysctlbyname("dev.acpi_ibm.0.volume", &n, &len, NULL, 0) == -1 )
+    return -1;
+  thinkpad_state->volume_level = n;
+
+  if ( sysctlbyname("dev.acpi_ibm.0.mute", &n, &len, NULL, 0) == -1 )
+    return -1;
+  thinkpad_state->mute_toggle = n;
+#endif
   return 0;
 } /* }}} */
 
 /* get the current state from the apm subsystem */
 int get_apm_state(t_thinkpad_state *thinkpad_state) /* {{{ */
 {
+#ifndef __FreeBSD__
   unsigned int i;
   static int fdsc = -1; /* -1 -> file not opened */
   char buffer[38];
@@ -1114,7 +1180,15 @@
       thinkpad_state->ac_state = STATE_ON;
       break;
   }
+#else
+  u_long addr;
+  size_t len = sizeof(addr);
+
+  if ( sysctlbyname("hw.acpi.acline", &addr, &len, NULL, 0) == -1 )
+    return -1;
 
+  thinkpad_state->ac_state = (addr == 1) ? STATE_ON : STATE_OFF;
+#endif
   return 0;
 } /* }}} */
 
@@ -1276,6 +1350,12 @@
 
   /* only use writeback to nvram when cfg.mixersteps is different from DEFAULT_MIXERSTEPS */
   if(cfg.mixersteps != DEFAULT_MIXERSTEPS) {
+#ifdef __FreeBSD__
+    u_int n = thinkpad_state->volume_level;
+
+    if (sysctlbyname("dec.acpi_ibm.0.volume", NULL, NULL, &n, sizeof(n)))
+      fprintf(stderr, _("Unable to set volume sysctl"));
+#else
     /* open nvram */
     if((fdsc = open(cfg.nvram, O_RDWR|O_NONBLOCK)) == -1) {
       fprintf(stderr, _("Unable to open device %s: "), cfg.nvram);
@@ -1317,8 +1397,8 @@
     }
 
     close(fdsc);
+#endif
   }
-
   return;
 
 } /* }}} */
