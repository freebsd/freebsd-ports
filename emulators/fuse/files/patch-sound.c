--- sound.c.orig   Thu Mar 29 16:09:24 2007
+++ sound.c    Thu Mar 29 16:09:50 2007
@@ -58,8 +58,8 @@
 int sound_stereo_ay_abc=0;    /* (AY stereo) true for ABC stereo, else ACB */
 int sound_stereo_ay_narrow=0; /* (AY stereo) true for narrow AY st. sep. */

-static int sound_stereo_ay=0; /* local copy of settings_current.stereo_ay */
-static int sound_stereo_beeper=0;   /* and settings_current.stereo_beeper */
+int sound_stereo_ay=0;    /* local copy of settings_current.stereo_ay */
+int sound_stereo_beeper=0;   /* and settings_current.stereo_beeper */


 /* assume all three tone channels together match the beeper volume (ish).
