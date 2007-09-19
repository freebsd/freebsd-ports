--- kernel/drv/audigyls/audigyls.c.orig	2007-08-30 18:07:30.000000000 -0400
+++ kernel/drv/audigyls/audigyls.c	2007-09-19 12:55:02.000000000 -0400
@@ -1577,6 +1577,7 @@
       if (IOC_IS_OUTPUT (cmd))
 	switch (cmd & 0xff)
 	  {
+	  case SOUND_MIXER_RECMASK:
 	  case SOUND_MIXER_RECSRC:
 	    return *arg = 0;
 	    break;
@@ -1596,6 +1597,7 @@
       else
 	switch (cmd & 0xff)	/* Return Parameter */
 	  {
+	  case SOUND_MIXER_RECMASK:
 	  case SOUND_MIXER_RECSRC:
 	    return *arg = 0;
 	    break;
