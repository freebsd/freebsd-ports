--- libcdplay.c.orig	2003-04-10 19:19:44.000000000 +0200
+++ libcdplay.c	2008-06-24 01:07:56.000000000 +0200
@@ -1,484 +1,186 @@
-/* $Revision: 1.4 $ */
-/*
- * This is libcdplay, a Linux-specific CD-ROM playing library. 
- *
- * This code is (C) 1998-2001 David E. Smith <dave@technopagan.org>
- * and released under the GNU GPL. See `COPYING' for details.
+/*-
+ * Copyright (c) 2008 Pietro Cerutti <gahr@gahr.ch>
  *
- * (Old versions were under the LGPL. This is no longer the case.)
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. All advertising materials mentioning features or use of this software
+ *    must display the following acknowledgement:
+ *	This product includes software developed by the University of
+ *	California, Berkeley and its contributors.
+ * 4. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
  *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ */
+
+
+/*
+ * This is a wrapper around libcdaudio
  */
 
 #include "libcdplay.h"
-#include "sha.h"
-#include "mbo.h"
-#include "dcd.h"
-#include "base64.h"
-#include <unistd.h>
-#include <string.h> 
-#include <errno.h>
-#include <fcntl.h>
-#include <linux/cdrom.h>
-#include <sys/ioctl.h>
-#include <stdlib.h>
 #include <stdio.h>
-#include <signal.h>
+#include <cdaudio.h>
 
+static int cd_desc;
+static struct disc_status status;
+static struct disc_info   info;
+static char disc_id[9];
 
-#define DISC_MAGIC 42
-static int cdrive;			/* fd for the cd, natch */
-static int disc_present = DISC_MAGIC;	/* ugly hack for cd_present() */
-static char discid[33];
-
-static void int_cd_discid();
-
-/* Plays just the one track specified by trknum. */
-u_char cd_play_track (u_char trknum) {
-  struct cdrom_ti trkidx;
-  #ifdef DEBUG
-    fprintf (stderr,"Entering cd_play_track (%i)\n", trknum);
-  #endif
-  if (!cd_present()) return -1;
-  memset (&trkidx, 0, sizeof (struct cdrom_ti)); 
-  trkidx.cdti_trk0 = trkidx.cdti_trk1 = trknum;
-  if (cd_data_track(trknum)) return -1;
-#ifdef OLD_STOP_BEHAVIOUR
-  if(ioctl (cdrive, CDROMSTOP) == -1)
-    fprintf(stderr, "CDROMSTOP failed: %s\n", strerror(errno));
-#else
-  if(ioctl (cdrive, CDROMSTART) == -1)
-    fprintf(stderr, "CDROMSTART failed: %s\n", strerror(errno));
-#endif
-  if(ioctl (cdrive, CDROMPLAYTRKIND, &trkidx) == -1) {
-    struct cdrom_tocentry toce0, toce1;
-    struct cdrom_msf play;
-    toce0.cdte_format = CDROM_MSF;
-    toce0.cdte_track = trknum;
-    if(ioctl (cdrive, CDROMREADTOCENTRY, &toce0) == -1)
-      fprintf(stderr, "CDROMREADTOCENTRY[1] failed: %s\n", strerror(errno));
-    toce1.cdte_format = CDROM_MSF;
-    toce1.cdte_track = ((trknum == cd_last_track()) ? CDROM_LEADOUT : (trknum+1));
-    if(ioctl (cdrive, CDROMREADTOCENTRY, &toce1) == -1) {
-      fprintf(stderr, "CDROMREADTOCENTRY[2] (CDROM_LEADOUT) failed: %s\n",
-       strerror(errno));
-    }
-    play.cdmsf_min0=toce0.cdte_addr.msf.minute;
-    play.cdmsf_sec0=toce0.cdte_addr.msf.second;
-    play.cdmsf_frame0=toce0.cdte_addr.msf.frame;
-    play.cdmsf_min1=toce1.cdte_addr.msf.minute;
-    play.cdmsf_sec1=toce1.cdte_addr.msf.second;
-    play.cdmsf_frame1=toce1.cdte_addr.msf.frame;
-    if(ioctl (cdrive, CDROMPLAYMSF, &play) == -1)
-     fprintf(stderr, "CDROMPLAYMSF failed: %s\n", strerror(errno));
-  }
-  return trknum;
-} /* cd_play_track */
-
-/* Plays a sequential list of tracks, from trk1 to trk2. Unused. ;) */
-u_char cd_play_sequence (u_char trk1, u_char trk2) {
-  struct cdrom_ti trkidx;
-  #ifdef DEBUG
-    fprintf (stderr, "Entering cd_play_sequence (%i to %i)\n", trk1, trk2);
-  #endif
-  if (!cd_present()) return -1;
-  memset (&trkidx, 0, sizeof (struct cdrom_ti));
-  trkidx.cdti_trk0 = trk1;
-  trkidx.cdti_trk1 = trk2;
-#ifdef OLD_STOP_BEHAVIOUR
-  if(ioctl (cdrive, CDROMSTOP) == -1)
-    fprintf(stderr, "CDROMSTOP failed: %s\n", strerror(errno));
-#else
-  if(ioctl (cdrive, CDROMSTART) == -1)
-    fprintf(stderr, "CDROMSTART failed: %s\n", strerror(errno));
-#endif
-  if(ioctl (cdrive, CDROMPLAYTRKIND, &trkidx) == -1) {
-    struct cdrom_tocentry toce0, toce1;
-    struct cdrom_msf play;
-    toce0.cdte_format = CDROM_MSF;
-    toce0.cdte_track = trk1;
-    if(ioctl (cdrive, CDROMREADTOCENTRY, &toce0) == -1)
-      fprintf(stderr, "CDROMREADTOCENTRY[1] failed: %s\n", strerror(errno));
-    toce1.cdte_format = CDROM_MSF;
-    toce1.cdte_track = ((trk2 == cd_last_track()) ? CDROM_LEADOUT : (trk2+1));
-    if(ioctl (cdrive, CDROMREADTOCENTRY, &toce1) == -1) {
-      fprintf(stderr, "CDROMREADTOCENTRY[2] (CDROM_LEADOUT) failed: %s\n",
-       strerror(errno));
-    }
-    play.cdmsf_min0=toce0.cdte_addr.msf.minute;
-    play.cdmsf_sec0=toce0.cdte_addr.msf.second;
-    play.cdmsf_frame0=toce0.cdte_addr.msf.frame;
-    play.cdmsf_min1=toce1.cdte_addr.msf.minute;
-    play.cdmsf_sec1=toce1.cdte_addr.msf.second;
-    play.cdmsf_frame1=toce1.cdte_addr.msf.frame;
-    if(ioctl (cdrive, CDROMPLAYMSF, &play) == -1)
-      fprintf(stderr, "CDROMPLAYMSF failed: %s\n", strerror(errno));
-  }
-  return trk2;
-} /* play_seq */
-
-/* Plays from trknum to the end of the disc */
-u_char cd_play_disc (u_char trknum) {
-  struct cdrom_ti trkidx;
-  #ifdef DEBUG
-    fprintf (stderr,"Entering cd_play_disc (%i)\n", trknum);
-  #endif
-  if (!cd_present()) return -1;
-  memset (&trkidx, 0, sizeof(struct cdrom_ti));
-  trkidx.cdti_trk0 = trknum;
-  trkidx.cdti_trk1 = cd_last_track();
-#ifdef OLD_STOP_BEHAVIOUR
-  if(ioctl(cdrive, CDROMSTOP) == -1) /* has to be stopped to reset */
-    fprintf(stderr, "CDROMSTOP failed: %s\n", strerror(errno)); 
-#else
-  if(ioctl(cdrive, CDROMSTART) == -1)
-    fprintf(stderr, "CDROMSTART failed: %s\n", strerror(errno)); 
-#endif
-  if(ioctl(cdrive, CDROMPLAYTRKIND, &trkidx) == -1) {
-    struct cdrom_tocentry toce0, toce1;
-    struct cdrom_msf play;
-    toce0.cdte_format = CDROM_MSF;
-    toce0.cdte_track = trknum;
-    if(ioctl (cdrive, CDROMREADTOCENTRY, &toce0) == -1)
-      fprintf(stderr, "CDROMREADTOCENTRY[1] failed: %s\n", strerror(errno));
-    toce1.cdte_format = CDROM_MSF;
-    toce1.cdte_track = CDROM_LEADOUT;
-    if(ioctl (cdrive, CDROMREADTOCENTRY, &toce1) == -1) {
-      fprintf(stderr, "CDROMREADTOCENTRY[2] (CDROM_LEADOUT) failed: %s\n",
-       strerror(errno));
-    }
-    play.cdmsf_min0=toce0.cdte_addr.msf.minute;
-    play.cdmsf_sec0=toce0.cdte_addr.msf.second;
-    play.cdmsf_frame0=toce0.cdte_addr.msf.frame;
-    play.cdmsf_min1=toce1.cdte_addr.msf.minute;
-    play.cdmsf_sec1=toce1.cdte_addr.msf.second;
-    play.cdmsf_frame1=toce1.cdte_addr.msf.frame;
-    if(ioctl (cdrive, CDROMPLAYMSF, &play) == -1)
-      fprintf(stderr, "CDROMPLAYMSF failed: %s\n", strerror(errno));
-  }
-  return trknum;
-} /* play_track */
-
-
-/* This doesn't do what you think. That's why you shouldn't use it... */
-int cd_active() {
-  struct cdrom_subchnl subchnl;
-  #if DEBUG > 1
-    fprintf (stderr, "Entering cd_active()\n");
-  #endif
-  memset (&subchnl, '\0', sizeof (struct cdrom_subchnl));
-  subchnl.cdsc_format=CDROM_MSF;
-  if(ioctl (cdrive, CDROMSUBCHNL, &subchnl) == -1)
-    fprintf(stderr, "CDROMSUBCHNL failed: %s\n", strerror(errno));
-  #ifdef DEBUG
-    fprintf (stderr, "subchannel status is %i\n", subchnl.cdsc_audiostatus);
-  #endif
-  switch (subchnl.cdsc_audiostatus) {
-    case CDROM_AUDIO_INVALID:     return TRUE;    
-    case CDROM_AUDIO_PLAY:
-    case CDROM_AUDIO_PAUSED:      return TRUE; /* no, it's NOT a typo */
-    default: return FALSE;
-  }
-  return FALSE;
-}
-
-/* return the track that's playing (or zero) */
-u_char cd_current_track() {
-  struct cdrom_subchnl subchnl;
-  #ifdef DEBUG
-    fprintf (stderr, "Calling cd_current_track()... ");
-  #endif
-  if (!cd_present()) return 0;
-  memset (&subchnl, '\0', sizeof(struct cdrom_subchnl));
-  subchnl.cdsc_format = CDROM_MSF;
-  if(ioctl(cdrive, CDROMSUBCHNL, &subchnl) == -1)
-    fprintf(stderr, "CDROMSUBCHNL failed: %s\n", strerror(errno));
-  if (FALSE == cd_active()) return 0;
-  #ifdef DEBUG
-    fprintf (stderr, "returning %i\n", subchnl.cdsc_trk);
-  #endif
-  return subchnl.cdsc_trk;
-} /* current_track */
-
-unsigned long raw_track_length (u_char trknum) {
-  long frames = 0;
-  struct cdrom_tocentry toce;
-  if (!cd_present()) return 0;
-  toce.cdte_format = CDROM_MSF;
-  toce.cdte_track = (trknum == cd_last_track()) ? CDROM_LEADOUT : trknum+1;
-  if(ioctl (cdrive, CDROMREADTOCENTRY, &toce) == -1)
-    fprintf(stderr, "CDROMREADTOCENTRY[3] failed: %s\n", strerror(errno));
-  frames = (toce.cdte_addr.msf.minute) * CD_FRAMES * 60;
-  frames += (toce.cdte_addr.msf.second) * CD_FRAMES;
-  frames += toce.cdte_addr.msf.frame;
-  return frames;
-} /* raw */
-
-unsigned long cd_track_length_frames (u_char trknum) {
-  long frames = raw_track_length(trknum);
-  long prevframes = raw_track_length (trknum-1);
-  if (!cd_present()) return 0;
-  frames -= prevframes;
-  #if DEBUG > 1
-    fprintf (stderr, "cd_track_length_frames: track %i is %lu frames\n",
-             trknum, frames);
-  #endif
-  return frames;
-}
-
-/* returns length of track trknum, rounded to nearest second */
-int cd_track_length (u_char trknum) {
-  long frames = cd_track_length_frames(trknum);
-  int seconds = frames / CD_FRAMES;
-  if (!cd_present()) return 0;
-  if ((frames % CD_FRAMES) > (CD_FRAMES / 2)) seconds++;
-  #ifdef DEBUG
-    fprintf (stderr, "cd_track_length: track %i is %i seconds\n",
-             trknum, seconds);
-  #endif
-  return seconds; 
-} /* track_length */
-
-unsigned long cd_disc_length_frames (void) {
-  long frames = raw_track_length(cd_last_track());
-  #if DEBUG > 1
-    fprintf (stderr, "cd_disc_length_frames: %lu\n", frames);
-  #endif
-  if (!cd_present()) return 0;
-  return frames;
-}
-
-int cd_disc_length (void) {
-  long frames = cd_disc_length_frames();
-  int seconds = frames / CD_FRAMES;
-  if (!cd_present()) return 0;
-  if ((frames % CD_FRAMES) > (CD_FRAMES / 2)) seconds++;
-  #ifdef DEBUG
-    fprintf (stderr, "cd_disc_length: %i\n", seconds);
-  #endif
-  return seconds;
-}
-
-int cd_hw_status (void) {
-  struct cdrom_subchnl cdsc;
-  memset (&cdsc, '\0', sizeof (struct cdrom_subchnl));
-  cdsc.cdsc_format = CDROM_MSF;
-  if(ioctl (cdrive, CDROMSUBCHNL, &cdsc) == -1)
-    fprintf(stderr, "CDROMSUBCHNL failed: %s\n", strerror(errno));
-  return cdsc.cdsc_audiostatus;
-}
-/* The status codes are defined in cdrom.h. They may include:
-   CDROM_AUDIO_PLAY (cd playing)
-   CDROM_AUDIO_PAUSED
-   CDROM_AUDIO_ERROR
-   CDROM_AUDIO_COMPLETED (done with last request, drive stopped)
-   CDROM_AUDIO_NO_STATUS (drive ready)
-
-   Unless you know what you're doing, you probably don't want to use this.
-*/
-
-/* this was Othmar's, but I sorta reversed it. */
-int cd_present(void) {
-  int status;
-  if (disc_present != DISC_MAGIC) status = disc_present;
-    else {
-      status = ioctl(cdrive, CDROM_DRIVE_STATUS);
-      disc_present = status;
-    }
-  #ifdef DEBUG
-    // fprintf (stderr, "cd_present(), status is %i\n", status);
-  #endif
-  if ((status == CDS_DISC_OK) || (status == CDS_NO_INFO)) return TRUE;
-  /* returning TRUE if the drive doesn't support the status ioctl is,
-     perhaps, risky, but one can only wonder... */
-  /* other status codes: no disc, tray open, drive not ready */
-  return FALSE;
-}
-
-/* toggle pause state */
-void cd_pause (void) {
-  int pause = cd_hw_status();
-  #ifdef DEBUG
-    fprintf (stderr, "Entering cd_pause. Current status is %i\n", pause);
-  #endif
-  switch (pause) {
-    case CDROM_AUDIO_PAUSED:
-      if(ioctl (cdrive, CDROMRESUME) == -1)
-	fprintf(stderr, "CDROMRESUME failed: %s\n", strerror(errno));
-      break;
-    case CDROM_AUDIO_PLAY:
-      if(ioctl (cdrive, CDROMPAUSE) == -1)
-	fprintf(stderr, "CDROMPAUSE failed: %s\n", strerror(errno));
-      break;
-    default: cd_play_disc(cd_first_track()); break;
-    /* the above was a really cool idea from Ronald Tol             */
-    /* Any state other than CDROM_AUDIO_PLAY implies that we're not */
-    /* playing right now, so what the hell? :) linux/cdrom.h lists  */
-    /* all the possible states, and this seems to make sense...     */
-  }
-}
-
-
-int cd_paused (void) {
-  int pause = cd_hw_status();
-  #ifdef DEBUG
-    fprintf (stderr, "Entering cd_paused\n");
-  #endif
-  if (CDROM_AUDIO_PAUSED == pause) return TRUE;
-  return FALSE;
-}
-
-
-void cd_stop (void) {
-  #ifdef DEBUG
-    fprintf (stderr, "Entering cd_stop()\n");
-  #endif
-  if(ioctl (cdrive, CDROMSTOP) == -1)
-    fprintf(stderr, "CDROMSTOP failed: %s\n", strerror(errno));
-}
-
-void cd_eject (void) {
-  #ifdef DEBUG
-    fprintf (stderr, "Entering cd_eject()\n");
-  #endif
-  if (ioctl(cdrive,CDROM_DRIVE_STATUS) == CDS_TRAY_OPEN)
-    ioctl(cdrive,CDROMCLOSETRAY);
-    else ioctl (cdrive, CDROMEJECT);
-}
-
-u_char cd_first_track (void) {
-  struct cdrom_tochdr tochdr;
-  #ifdef DEBUG
-    fprintf (stderr, "Calling cd_first_track()... ");
-  #endif
-  if (!cd_present()) return 0;
-  if(ioctl (cdrive, CDROMREADTOCHDR, &tochdr) == -1)
-    fprintf(stderr, "CDROMREADTOCHDR failed: %s\n", strerror(errno));
-  #ifdef DEBUG
-    fprintf (stderr, "returning %i\n", tochdr.cdth_trk0);
-  #endif
-  return tochdr.cdth_trk0;
-}
-
-u_char cd_last_track (void) {
-  struct cdrom_tochdr tochdr;
-  #ifdef DEBUG
-    fprintf (stderr, "Calling cd_last_track()... ");
-  #endif
-  if (!cd_present()) return 0;
-  if(ioctl (cdrive, CDROMREADTOCHDR, &tochdr) == -1)
-    fprintf(stderr, "CDROMREADTOCHDR failed: %s\n", strerror(errno));
-  #ifdef DEBUG
-    fprintf (stderr, "returning %i\n", tochdr.cdth_trk1);
-  #endif
-  return tochdr.cdth_trk1;
-}
-
-int cd_data_track (u_char trknum) {
-  struct cdrom_tocentry toce;
-  int i;
-  if (!cd_present()) return -1;
-  memset (&toce, '\0', sizeof(struct cdrom_tocentry));
-  toce.cdte_format = CDROM_MSF;
-  toce.cdte_track  = trknum;
-  ioctl(cdrive, CDROMREADTOCENTRY, &toce);
-  /* if(ioctl (cdrive, CDROMREADTOCENTRY, &toce) == -1) */
-    /* fprintf(stderr, "CDROMREADTOCENTRY[4] failed: %s\n", strerror(errno)); */
-    /* apparently this fails randomly on some drives for no good reason. */
-  i = (toce.cdte_ctrl & CDROM_DATA_TRACK ? TRUE : FALSE);
-  #ifdef DEBUG
-    fprintf (stderr, "toce.cdte_ctrl is %i\n", toce.cdte_ctrl);
-    fprintf (stderr, "cd_data_track(%i) returning %i\n", trknum, i);
-  #endif
-  return i;
-}
- 
-/* Hey, wow, it's the mandatory `initialize the drive' function. */
-int cd_init_player (char *device) {
-  #ifdef DEBUG
-    fprintf(stderr, "Calling cd_init_player(%s). Debugging ON.\n", device);
-  #endif
-
-  cdrive = open(device, O_RDONLY | O_NONBLOCK);
-  if (!cdrive) return -1;
-
-  if (!cd_present()) return -1;
-
-  int_cd_discid();
-  mbo_init(device);  
-  return cdrive;
-}
-
-/* never use this either. */
-int cd_fd (void) {
-  return cdrive;
-}
-
-/* Okay, this is just f'n silly. musicbrainz has a "Get CD Index"
- * function, but it won't work unless you've already retrieved
- * the information from the network. So I have to keep all the
- * "Get CD Index ID" code here.
- */
+int
+cd_init_player(char *device)
+{
+    cd_desc = cd_init_device(device);
+    mbo_init(device);
+    cd_stat(cd_desc, &info);
+    return (cd_desc);
+}
+
+u_char
+dcd_play_track(u_char trknum)
+{
+   return (cd_play_sequence(trknum, trknum));
+}
+
+u_char
+cd_play_disc(u_char trknum)
+{
+   return (cd_play_sequence(trknum, info.disc_total_tracks));
+}
+
+u_char
+cd_play_sequence(u_char trk1, u_char trk2)
+{
+    return (cd_play_track(cd_desc, (int) trk1, (int) trk2) ? -1 : trk1);
+}
+
+u_char
+cd_current_track(void)
+{
+    cd_poll(cd_desc, &status);
+    return (status.status_current_track);
+}
+
+unsigned long
+cd_disc_length_frames(void)
+{
+    cd_poll(cd_desc, &status);
+    return (status.status_disc_time.frames);
+}
+
+unsigned long
+cd_track_length_frames(u_char trknum)
+{
+    return (info.disc_track[trknum-1].track_length.frames);
+}
+
+int
+cd_disc_length(void)
+{
+    return (info.disc_length.minutes * 60 +
+	    info.disc_length.seconds);
+}
+
+int
+cd_track_length(u_char trknum)
+{
+    return (info.disc_track[trknum-1].track_length.minutes * 60 +
+	    info.disc_track[trknum-1].track_length.seconds);
+}
 
-char *cd_discid(void) {
-  return discid;
+int
+cd_track_time(void)
+{
+    cd_poll(cd_desc, &status);
+    return (status.status_track_time.minutes * 60 + status.status_track_time.seconds);
 }
 
-static void int_cd_discid (void) {
-  SHA_INFO sha;
-  unsigned char digest[20];
-  unsigned long size;
-  char temp[9];
-  int i, lba;
-  int trackz = cd_last_track();
-  struct cdrom_tocentry toce;
-
-  if (!cd_present()) return;;
-
-  #if DEBUG > 1
-    fprintf (stderr, "Entering cd_discid()\n");
-  #endif
-
-  memset (discid, '\0', sizeof(discid));
-  memset (&toce, '\0', sizeof(toce));
-
-  sha_init(&sha);
-  sprintf (temp, "%02X", cd_first_track());
-  sha_update(&sha, (unsigned char *)temp, strlen(temp));
-  sprintf (temp, "%02X", cd_last_track());
-  sha_update(&sha, (unsigned char *)temp, strlen(temp));
-
-  toce.cdte_track = CDROM_LEADOUT;
-  toce.cdte_format = CDROM_LBA;
-  if(ioctl(cdrive, CDROMREADTOCENTRY, &toce) == -1)
-    fprintf(stderr, "CDROMREADTOCENTRY[5] failed: %s\n", strerror(errno));
-  lba = toce.cdte_addr.lba + 150;
-  sprintf (temp, "%08X", lba);
-  sha_update(&sha, (unsigned char *)temp, strlen(temp));
-  
-  for (i=1; i < 100; i++) {
-    if (i <= trackz) {
-      toce.cdte_format = CDROM_LBA;
-      toce.cdte_track = i;
-      if(ioctl (cdrive, CDROMREADTOCENTRY, &toce) == -1)
-	fprintf(stderr, "CDROMREADTOCENTRY[6] failed: %s\n", strerror(errno));
-      lba = toce.cdte_addr.lba + 150;
-      sprintf(temp, "%08X", lba);
-    }
-    else sprintf (temp, "%08X", 0);
-    sha_update(&sha, (unsigned char *)temp, strlen(temp));
-  }
-  sha_final(digest, &sha);
-  #if DEBUG > 1
-    fprintf (stderr, "SHA digest finalized.\n");
-  #endif
-  bin_to_base64(discid, digest, 20, size);
-  #ifdef DEBUG
-    fprintf (stderr, "cd_discid returning %s\n", discid);
-  #endif
+int
+cd_data_track(u_char trknum)
+{
+    return (info.disc_track[trknum-1].track_type == CDAUDIO_TRACK_DATA);
 }
 
-/* there used to be more stuff here, but it's been more-or-less
-   subsumed by the musicbrainz crapulence. */
+u_char
+cd_first_track(void)
+{
+    return (1);
+}
+
+u_char
+cd_last_track(void)
+{
+    return (info.disc_total_tracks);
+}
 
-/* char *cd_discid(void); */
-/* char *cd_subid(void);  */
+int
+cd_active(void)
+{
+    cd_poll(cd_desc, &status);
+    return (status.status_mode == CDAUDIO_PLAYING ||
+	    status.status_mode == CDAUDIO_PAUSED);
+}
+
+int
+cd_paused(void)
+{
+    cd_poll(cd_desc, &status);
+    return (status.status_mode == CDAUDIO_PAUSED);
+}
+
+int
+cd_present(void)
+{
+    return (info.disc_present);
+}
+
+int
+cd_hw_status(void)
+{
+    return 0;
+}
+
+char *
+cd_discid(void)
+{
+    snprintf(disc_id, sizeof(disc_id), "%0x", cddb_discid(cd_desc));
+    return (disc_id);
+}
+
+void
+dcd_stop(void)
+{
+    cd_stop(cd_desc);
+}
+
+void
+dcd_pause(void)
+{
+    if(cd_paused())
+	cd_resume(cd_desc);
+    else
+	cd_pause(cd_desc);
+}
+
+void
+dcd_eject(void)
+{
+    cd_eject(cd_desc);
+}
