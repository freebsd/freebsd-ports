--- ./src/midi.rawmidi.c.orig	Sun Sep  8 03:19:30 2002
+++ ./src/midi.rawmidi.c	Sun Sep  8 03:20:02 2002
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
