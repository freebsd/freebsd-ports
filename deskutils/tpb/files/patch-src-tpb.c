--- src/tpb.c.orig	2005-07-18 14:15:59 UTC
+++ src/tpb.c
@@ -34,6 +34,16 @@
 #include <unistd.h>
 #include "config.h"
 
+#ifdef __FreeBSD__
+#include <sys/file.h>
+#include <sys/ioctl.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#ifdef __i386__
+#include <machine/apm_bios.h>
+#endif
+#endif
+
 #if ENABLE_NLS
 #include <libintl.h>
 #endif /* ENABLE_NLS */
@@ -161,6 +171,9 @@ int main(int argc, char **argv) /* {{{ *
   /* to initialize struct */
   memset(&last_thinkpad_state, 0x00, sizeof(t_thinkpad_state));
   if(get_nvram_state(&thinkpad_state) != 0) {
+#ifdef __FreeBSD__
+    fprintf(stderr, _("Neither acpi_ibm(4) nor nvram(4) driver loaded. Exiting..."));
+#endif
     _exit(1);
   }
   if(cfg.apm == STATE_ON) {
@@ -449,6 +462,25 @@ int main(int argc, char **argv) /* {{{ *
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
@@ -981,6 +1013,11 @@ Display *init_xgrabkey(void) /* {{{ */
 int get_nvram_state(t_thinkpad_state *thinkpad_state) /* {{{ */
 {
   static int fdsc = -1; /* -1 -> file not opened */
+#ifdef __FreeBSD__
+  u_int n = 0;
+  size_t len = sizeof(n);
+  if ( fdsc != -1 || sysctlbyname("dev.acpi_ibm.0.hotkey", &n, &len, NULL, 0) == -1 ) {
+#endif
   unsigned char buffer[114];
   struct {
     int pos;
@@ -1040,13 +1077,51 @@ int get_nvram_state(t_thinkpad_state *th
   thinkpad_state->powermgt_battery  =                                               (( buffer[0x39] & 0x38) >> 3);
 
   return 0;
+#ifdef __FreeBSD__
+  }    
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
+
+  return 0;
+#endif
 } /* }}} */
 
 /* get the current state from the apm subsystem */
 int get_apm_state(t_thinkpad_state *thinkpad_state) /* {{{ */
 {
-  unsigned int i;
   static int fdsc = -1; /* -1 -> file not opened */
+#ifndef __FreeBSD__
+  unsigned int i;
   char buffer[38];
   char *tokens[9];
 
@@ -1122,7 +1197,30 @@ int get_apm_state(t_thinkpad_state *thin
       thinkpad_state->ac_state = STATE_ON;
       break;
   }
+#else
+  u_long addr;
+  size_t len = sizeof(addr);
 
+  if ( fdsc != -1 || sysctlbyname("hw.acpi.acline", &addr, &len, NULL, 0) == -1 ) {
+#ifdef __i386__
+    // Try APM
+    if(fdsc == -1) { /* if not already opened, open apm */
+      if((fdsc = open("/dev/apm", O_RDONLY)) == -1)
+        return -1;
+    }
+
+    struct apm_info info;
+    if (ioctl(fdsc, APMIO_GETINFO, &info) == -1)
+      return -1;
+
+    if (info.ai_acline > 2)
+      return -1;
+    
+    addr = info.ai_acline;
+#endif
+  }
+  thinkpad_state->ac_state = (addr == 1) ? STATE_ON : STATE_OFF;
+#endif
   return 0;
 } /* }}} */
 
@@ -1285,6 +1383,13 @@ void set_nvram_volume_level(t_thinkpad_s
 
   /* only use writeback to nvram when cfg.mixersteps is different from DEFAULT_MIXERSTEPS */
   if(cfg.mixersteps != DEFAULT_MIXERSTEPS) {
+#ifdef __FreeBSD__
+    u_int n = thinkpad_state->volume_level;
+
+    if (sysctlbyname("dec.acpi_ibm.0.volume", NULL, NULL, &n, sizeof(n)) != 0)
+      fprintf(stderr, _("Unable to set volume sysctl"));
+    else {
+#endif
     /* open nvram */
     if((fdsc = open(cfg.nvram, O_RDWR|O_NONBLOCK)) == -1) {
       fprintf(stderr, _("Unable to open device %s: "), cfg.nvram);
@@ -1326,8 +1431,10 @@ void set_nvram_volume_level(t_thinkpad_s
     }
 
     close(fdsc);
+#ifdef __FreeBSD__
+    }
+#endif
   }
-
   return;
 
 } /* }}} */
