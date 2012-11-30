--- lib/gsimidi_pcm/midi_to_pcm.c.orig	2012-11-30 14:13:53.000000000 +0100
+++ lib/gsimidi_pcm/midi_to_pcm.c	2012-11-30 14:14:47.000000000 +0100
@@ -820,7 +820,7 @@
 	for (t = 0; t < d->reverbCount; t++) {
 		if (d->reverbTaps[t].offset == offset) {
 			d->reverbTaps[t].amount = amount;
-			return; // WHS: Return what?? False ??
+			return False; // WHS: Return what?? False ??
 		}
 	}
 	taps = calloc (sizeof (MidiReverbTap), d->reverbCount + 1);
