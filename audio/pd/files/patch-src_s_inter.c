--- src/s_inter.c.orig	2011-03-20 07:22:27.000000000 +0900
+++ src/s_inter.c	2011-04-06 20:20:35.000000000 +0900
@@ -1251,7 +1251,11 @@
              sys_gui("pdtk_watchdog\n");
 #endif
          sys_get_audio_apis(buf);
+#if defined(__FreeBSD__)
+         strcpy(buf2, "{}");
+#else
          sys_get_midi_apis(buf2);
+#endif
          sys_set_searchpath();     /* tell GUI about path and startup flags */
          sys_set_extrapath();
          sys_set_startup();
