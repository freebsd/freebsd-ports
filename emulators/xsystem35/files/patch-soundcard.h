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
