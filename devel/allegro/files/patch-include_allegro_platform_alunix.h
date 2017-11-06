$OpenBSD: patch-include_allegro_platform_alunix_h,v 1.1 2010/04/26 02:56:30 jakemsr Exp $
--- include/allegro/platform/alunix.h.orig	2007-06-16 01:52:28 UTC
+++ include/allegro/platform/alunix.h
@@ -69,6 +69,8 @@ AL_VAR(TIMER_DRIVER, timerdrv_unix_sigal
 #define DIGI_ALSA             AL_ID('A','L','S','A')
 #define MIDI_ALSA             AL_ID('A','M','I','D')
 #define DIGI_JACK             AL_ID('J','A','C','K')
+#define DIGI_SNDIO            AL_ID('S','I','O','D')
+#define MIDI_SNDIO            AL_ID('M','I','O','M')
 
 
 #ifdef ALLEGRO_WITH_OSSDIGI
@@ -85,6 +87,12 @@ AL_VAR(MIDI_DRIVER, midi_oss);
 
 #ifndef ALLEGRO_WITH_MODULES
 
+#ifdef ALLEGRO_WITH_SNDIODIGI
+AL_VAR(DIGI_DRIVER, digi_sndio);
+#define DIGI_DRIVER_SNDIO                                         \
+      {  DIGI_SNDIO,       &digi_sndio,           TRUE  },
+#endif /* ALLEGRO_WITH_SNDIODIGI */
+
 #ifdef ALLEGRO_WITH_ESDDIGI
 AL_VAR(DIGI_DRIVER, digi_esd);
 #define DIGI_DRIVER_ESD                                          \
