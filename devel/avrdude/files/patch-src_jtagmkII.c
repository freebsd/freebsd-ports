--- src/jtagmkII.c.orig	2022-05-07 20:39:47 UTC
+++ src/jtagmkII.c
@@ -1840,8 +1840,8 @@ void jtagmkII_close(PROGRAMMER * pgm)
 
   avrdude_message(MSG_NOTICE2, "%s: jtagmkII_close()\n", progname);
 
-  if (pgm->flag & PGM_FL_IS_PDI) {
-    /* When in PDI mode, restart target. */
+  if (pgm->flag & (PGM_FL_IS_PDI|PGM_FL_IS_JTAG)) {
+    /* When in PDI or JTAG mode, restart target. */
     buf[0] = CMND_GO;
     avrdude_message(MSG_NOTICE2, "%s: jtagmkII_close(): Sending GO command: ",
 	      progname);
