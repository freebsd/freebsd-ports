--- src/audio_oss.c.orig	Tue Apr  3 06:00:44 2001
+++ src/audio_oss.c	Sat Sep  7 10:57:08 2002
@@ -33,9 +33,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
-#if defined(__FreeBSD__)
-#include <machine/soundcard.h>
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <soundcard.h>
 #else
 #include <sys/soundcard.h>
--- src/midi.rawmidi.c.orig	Sat Mar 31 04:16:38 2001
+++ src/midi.rawmidi.c	Sat Sep  7 10:57:13 2002
@@ -39,9 +39,7 @@
 #include <fcntl.h>
 
 #ifdef ENABLE_MIDI_SEQMIDI
-#if defined(__FreeBSD__)
-#include <machine/soundcard.h>
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <soundcard.h>
 #else
 #include <sys/soundcard.h>
--- src/mixer_oss.c.orig	Thu Mar 22 20:10:13 2001
+++ src/mixer_oss.c	Sat Sep  7 10:57:26 2002
@@ -33,9 +33,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
-#if defined(__FreeBSD__)
-#include <machine/soundcard.h>
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <soundcard.h>
 #else
 #include <sys/soundcard.h>
