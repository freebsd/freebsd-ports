--- gmixer.c.orig	1999-02-22 16:11:10 UTC
+++ gmixer.c
@@ -1,10 +1,11 @@
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <strings.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <gtk/gtk.h>
 #include "icons/gmixer.xpm"
 #include "icons/mix_logo.xpm"
@@ -378,6 +379,27 @@ void usage(char *prog_name)
 	exit(0);
 }
 
+void fill_volctrls ()
+{
+	int i;
+	char str[3];
+
+	/* if you raise upper limit beyond 100, you have to make str longer. */
+	for (i = 17; i < SOUND_MIXER_NRDEVICES && i < 100 ; i++ )
+	{
+		snprintf (str, 3, "%2d", i);
+		volctrls[i].mixer_id = (gpointer) str;
+		volctrls[i].vol_widget = NULL;
+		volctrls[i].right_widget = NULL;
+		volctrls[i].enable_widget = NULL;
+		volctrls[i].rec_widget = NULL;
+		volctrls[i].stereo_widget = NULL;
+		volctrls[i].vol_left = NULL;
+		volctrls[i].vol_right = NULL;
+		volctrls[i].xpm = mix_unknown_xpm;
+	}
+}
+
 int main (int argc, char *argv[])
 {
 	char *homedir;
@@ -385,6 +407,7 @@ int main (int argc, char *argv[])
 	char *default_dev = "/dev/mixer";
 	int i;
 	g_print ("gmixer 0.98 (22.2.1999)\nCopyleft (C) 1998,1999 - Sergey Kiselev <sergey@junior.technion.ac.il>\n");
+	fill_volctrls();
 	homedir = getenv("HOME");
 	snprintf (rcfile, NAME_LEN, "%s/.gmixerrc", homedir);
 	mixer_dev = default_dev;
