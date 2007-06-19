--- audio/midi_drivers/fmopldrv.h.orig	Wed Aug  7 03:10:31 2002
+++ audio/midi_drivers/fmopldrv.h	Thu Jun 14 01:30:28 2007
@@ -76,7 +76,7 @@
 	/* output a packed midi command to the midi stream
 	 * valid only if mode is MO_SIMPLE
 	 */
-	void OplDriver::send(uint32 b);
+	void send(uint32 b);
 
 	/* retrieve a string representation of an error code */
 	static const char *get_error_name(int error_code);
