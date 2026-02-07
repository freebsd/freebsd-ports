--- libcdplay.h.orig	2003-01-04 03:15:49.000000000 +0100
+++ libcdplay.h	2008-06-24 01:08:06.000000000 +0200
@@ -11,7 +11,8 @@
 #define __CD_PLAYER_LIB
 
 #include <sys/types.h>
-#include <linux/cdrom.h>
+
+typedef unsigned char u_char;
 
 /* Initialization. Takes the drive to set up (like "/dev/cdrom") and
  * returns the drive's file descriptor. Note that you shouldn't ever
@@ -23,11 +24,11 @@
 
 /* Playing operations - tracks, disc, etc.
  * These operations return the track number you fed them, or -1 in case of
- * an error (like trying to play a data track in cd_play_track).
+ * an error (like trying to play a data track in dcd_play_track).
  */
-u_char cd_play_track (u_char trknum);
-u_char cd_play_sequence (u_char trk1, u_char trk2);
+u_char dcd_play_track (u_char trknum);
 u_char cd_play_disc (u_char trknum);
+u_char cd_play_sequence (u_char trk1, u_char trk2);
 
 
 /* Informational operations */
@@ -38,6 +39,7 @@
 /* rounded to the nearest second */
 int cd_disc_length (void);
 int cd_track_length (u_char trknum);
+int cd_track_time (void);
 int cd_data_track (u_char trknum);
 
 u_char cd_first_track(void); /* almost always `1' */
@@ -45,11 +47,11 @@
 
 
 /* Simple commands. */
-void cd_stop(void);
-void cd_eject(void);
-void cd_pause(void);    /* toggles pause/resume status internally */
+void dcd_stop(void);
+void dcd_eject(void);
+void dcd_pause(void);    /* toggles pause/resume status internally */
 int cd_active(void);    /* if playing or paused, return TRUE */
-int cd_paused(void);    /* boolean for pause(TRUE) or not */
+int dcd_paused(void);    /* boolean for pause(TRUE) or not */
 int cd_present(void);   /* is there a disc in the drive? */
 
 /* The RAW frame count is really only useful for cddb calculations. */
