--- lib/gsimidi_pcm/midi_parse.c.orig	Sun Jan 14 20:01:27 2001
+++ lib/gsimidi_pcm/midi_parse.c	Wed Aug 18 18:34:03 2004
@@ -349,6 +349,7 @@
     case 0xfc:	    /* Midi stop */
     case 0xfe:	    /* Active sense */
     case 0xff:	    /* Reset */
+    ;
     }
 }
 
