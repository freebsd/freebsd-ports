--- src/s_midi_oss_pm.c.orig	2020-07-07 04:07:26.811553000 -0700
+++ src/s_midi_oss_pm.c	2020-07-07 04:05:55.736126000 -0700
@@ -0,0 +1,144 @@
+/* Copyright (c) 1997-1999 Guenter Geiger, Miller Puckette, Larry Troxler,
+* Winfried Ritsch, Karl MacMillan, and others.
+* For information on usage and redistribution, and for a DISCLAIMER OF ALL
+* WARRANTIES, see the file, "LICENSE.txt," in this distribution.  */
+
+/* MIDI I/O for Linux using OSS */
+
+#include <stdio.h>
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+#include <stdlib.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <errno.h>
+#include <string.h>
+#include "m_pd.h"
+#include "s_stuff.h"
+
+#define NSEARCH 10
+static int oss_nmidiindevs, oss_nmidioutdevs;
+static char oss_indevnames[NSEARCH][4], oss_outdevnames[NSEARCH][4];
+static int oss_nmidiin;
+static int oss_midiinfd[MAXMIDIINDEV];
+static int oss_nmidiout;
+static int oss_midioutfd[MAXMIDIOUTDEV];
+
+static void oss_midiout(int fd, int n)
+{
+    char b = n;
+    if ((write(fd, (char *) &b, 1)) != 1)
+        perror("midi write");
+}
+
+#define O_MIDIFLAG O_NDELAY
+
+#define md_msglen(x) (((x)<0xC0)?2:((x)<0xE0)?1:((x)<0xF0)?2:\
+    ((x)==0xF2)?2:((x)<0xF4)?1:0)
+
+
+#if 0   /* this is the "select" version which doesn't work with OSS
+        driver for emu10k1 (it doesn't implement select.) */
+#else
+
+    /* this version uses the asynchronous "read()" ... */
+void sys_poll_midi_oss_pm(void)
+{
+    int i, throttle = 100;
+    struct timeval timout;
+    int did = 1, maxfd = 0;
+    while (did)
+    {
+        fd_set readset, writeset, exceptset;
+        did = 0;
+        if (throttle-- < 0)
+            break;
+        for (i = 0; i < oss_nmidiin; i++)
+        {
+            char c;
+            int ret = read(oss_midiinfd[i], &c, 1);
+            if (ret < 0)
+            {
+                if (errno != EAGAIN)
+                    perror("MIDI");
+            }
+            else if (ret != 0)
+            {
+                sys_midibytein(i, (c & 0xff));
+                did = 1;
+            }
+        }
+    }
+}
+#endif
+
+void midi_oss_init(void)
+{
+    int fd, devno;
+    struct stat statbuf;
+    char namebuf[80];
+         /* we only try to detect devices before trying to open them, because
+         when they're open, they migth not be possible to reopen here */
+    static int initted = 0;
+    if (initted)
+        return;
+    initted = 1;
+    oss_nmidiindevs = oss_nmidioutdevs = 0;
+
+    for (devno = 0; devno < NSEARCH; devno++)
+    {
+        if (devno == 0)
+        {
+                /* try to open the device for reading */
+            fd = open("/dev/midi", O_RDONLY | O_NDELAY);
+            if (fd >= 0)
+            {
+                close(fd);
+                strcpy(oss_indevnames[oss_nmidiindevs++], "");
+            }
+            fd = open("/dev/midi", O_WRONLY | O_NDELAY);
+            if (fd >= 0)
+            {
+                close(fd);
+                strcpy(oss_outdevnames[oss_nmidioutdevs++], "");
+            }
+        }
+        if (oss_nmidiindevs >= NSEARCH || oss_nmidioutdevs >= NSEARCH)
+            break;
+
+        sprintf(namebuf, "/dev/midi%d", devno);
+        fd = open(namebuf, O_RDONLY | O_NDELAY);
+        if (fd >= 0)
+        {
+            close(fd);
+            sprintf(oss_indevnames[oss_nmidiindevs++], "%d", devno);
+        }
+        fd = open(namebuf, O_WRONLY | O_NDELAY);
+        if (fd >= 0)
+        {
+            close(fd);
+            sprintf(oss_outdevnames[oss_nmidioutdevs++], "%d", devno);
+        }
+        if (oss_nmidiindevs >= NSEARCH || oss_nmidioutdevs >= NSEARCH)
+            break;
+
+        sprintf(namebuf, "/dev/midi%2.2d", devno);
+        fd = open(namebuf, O_RDONLY | O_NDELAY);
+        if (fd >= 0)
+        {
+            close(fd);
+            sprintf(oss_indevnames[oss_nmidiindevs++], "%d", devno);
+        }
+        fd = open(namebuf, O_WRONLY | O_NDELAY);
+        if (fd >= 0)
+        {
+            close(fd);
+            sprintf(oss_outdevnames[oss_nmidioutdevs++], "%d", devno);
+        }
+        if (oss_nmidiindevs >= NSEARCH || oss_nmidioutdevs >= NSEARCH)
+            break;
+
+    }
+}
