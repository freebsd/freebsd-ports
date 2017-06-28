--- src/unix/usnddrv.c.orig	2004-09-24 14:45:03 UTC
+++ src/unix/usnddrv.c
@@ -24,6 +24,9 @@ BEGIN_DIGI_DRIVER_LIST
 #if (defined ALLEGRO_WITH_JACKDIGI) && (!defined ALLEGRO_WITH_MODULES)
    DIGI_DRIVER_JACK
 #endif
+#if (defined ALLEGRO_WITH_SNDIODIGI) && (!defined ALLEGRO_WITH_MODULES)
+   DIGI_DRIVER_SNDIO
+#endif
 #if (defined ALLEGRO_WITH_SGIALDIGI) && (!defined ALLEGRO_WITH_MODULES)
    DIGI_DRIVER_SGIAL
 #endif
