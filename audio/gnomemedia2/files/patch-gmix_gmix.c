--- gmix/gmix.c.orig	Sun Mar 16 16:09:01 2003
+++ gmix/gmix.c	Sun Mar 16 16:13:09 2003
@@ -591,6 +591,11 @@
 	/* Masks for the channel data - OSS blows compared to ALSA */
 	int recmask, recsrc, stereodee;
 
+	/* FreeBSD device name detection */
+	FILE *sndstat;
+	char line[256];
+	char *devname, *p;
+
 	/*
 	 * create new device configureation
 	 */
@@ -659,7 +665,26 @@
 	} 
 #else
 	new_device->card_name = g_strdup_printf ("OSS-%d-%d", num + 1, num + 1);
-	g_snprintf (new_device->info.name, 31, "Card %d", num+1);
+	/* get soundcard name from /dev/sndstat on FreeBSD */
+	sndstat = fopen("/dev/sndstat", "r");
+	if (!sndstat)
+		g_snprintf (new_device->info.name, 31, "Card %d", num+1);
+	else {
+		while (fgets (line, 255, sndstat)) {
+			if (!strncmp (line, "pcm", 3) && (atoi (&line[3]) == num))
+			{
+				devname = line;
+				while (*devname++ != '<')
+					;
+				p = devname;
+				while (*p != '>')
+					p++;
+				*p = '\0';
+				g_snprintf (new_device->info.name, 31, devname);
+			}
+		}
+		fclose(sndstat);
+	}
 #endif
 	/* 
 	 * several bitmasks describing the mixer
