$FreeBSD$

--- src/s_main.c.orig	Wed Oct 29 20:38:54 2003
+++ src/s_main.c	Tue Nov 11 22:45:46 2003
@@ -253,8 +253,8 @@ int sys_main(int argc, char **argv)
     if (sys_startgui(sys_guidir->s_name))	/* start the gui */
     	return(1);
     	    /* open audio and MIDI */
-    sys_open_midi(sys_nmidiin, sys_midiindevlist,
-    	sys_nmidiout, sys_midioutdevlist);
+//    sys_open_midi(sys_nmidiin, sys_midiindevlist,
+//    	sys_nmidiout, sys_midioutdevlist);
     sys_open_audio(sys_nsoundin, sys_soundindevlist, sys_nchin, sys_chinlist,
     	sys_nsoundout, sys_soundoutdevlist, sys_nchout, sys_choutlist,
 	    sys_main_srate, sys_main_advance, 1);
