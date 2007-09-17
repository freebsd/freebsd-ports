--- ../../tags/asunder-0.8.1/src/main.c	Fri Sep 14 10:35:12 2007
+++ src/main.c	Fri Sep 14 14:32:54 2007
@@ -22,7 +22,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#include <linux/cdrom.h>
+#include <sys/cdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
@@ -210,8 +210,8 @@
     static bool alreadyKnowGood = false; /* check when program just started */
     static bool alreadyCleared = true; /* no need to clear when program just started */
     
-    status = ioctl(fd, CDROM_DISC_STATUS, CDSL_CURRENT);
-    if (status == CDS_AUDIO || status == CDS_MIXED)
+    status = ioctl(fd, CDIOREADTOCHEADER);
+    if (status >= 0)
     {
         if (!alreadyKnowGood)
         {
@@ -308,7 +308,7 @@
     //~ {
         //~ ioctl(fd, CDROMCLOSETRAY, CDSL_CURRENT);
     //~ } else {
-            ioctl(fd, CDROMEJECT, CDSL_CURRENT);
+            ioctl(fd, CDIOCEJECT);
     //~ }
     
     close(fd);
@@ -367,8 +367,8 @@
 {
     int fd;
     int status;
-    struct cdrom_tochdr th;
-    struct cdrom_tocentry te;
+    struct ioc_toc_header th;
+    struct ioc_read_toc_single_entry te;
     int i;
     
     cddb_disc_t * disc = NULL;
@@ -385,15 +385,15 @@
     }
 
     // read disc status info
-    status = ioctl(fd, CDROM_DISC_STATUS, CDSL_CURRENT);
-    if ((status == CDS_AUDIO) || (status == CDS_MIXED))
+    status = ioctl(fd, CDIOREADTOCHEADER);
+    if (status >= 0)
     {
         // see if we can read the disc's table of contents (TOC).
-        if (ioctl(fd, CDROMREADTOCHDR, &th) == 0)
+        if (ioctl(fd, CDIOREADTOCHEADER, &th) == 0)
         {
 #ifdef DEBUG
-            printf("starting track: %d\n", th.cdth_trk0);
-            printf("ending track: %d\n", th.cdth_trk1);
+            printf("starting track: %d\n", th.starting_track);
+            printf("ending track: %d\n", th.ending_track);
 #endif
             disc = cddb_disc_new();
             if (disc == NULL)
@@ -402,13 +402,13 @@
                 exit(-1);
             }
             
-            te.cdte_format = CDROM_LBA;
-            for (i=th.cdth_trk0; i<=th.cdth_trk1; i++)
+            te.address_format = CD_LBA_FORMAT;
+            for (i=th.starting_track; i<=th.ending_track; i++)
             {
-                te.cdte_track = i;
-                if (ioctl(fd, CDROMREADTOCENTRY, &te) == 0)
+                te.track = i;
+                if (ioctl(fd, CDIOREADTOCENTRY, &te) == 0)
                 {
-                    if (te.cdte_ctrl & CDROM_DATA_TRACK)
+                    if (te.entry.control & 0x04)
                     {
                         // track is a DATA track. make sure its "rip" box is not checked by default
                         track_format[i] = FALSE;
@@ -423,17 +423,17 @@
                         exit(-1);
                     }
                 
-                    cddb_track_set_frame_offset(track, te.cdte_addr.lba+SECONDS_TO_FRAMES(2));
+                    cddb_track_set_frame_offset(track, ntohl(te.entry.addr.lba)+SECONDS_TO_FRAMES(2));
                     snprintf(trackname, 9, "Track %d", i);
                     cddb_track_set_title(track, trackname);
                     cddb_track_set_artist(track, "Unknown Artist");
                     cddb_disc_add_track(disc, track);
                 }
             }
-            te.cdte_track = CDROM_LEADOUT;
-            if (ioctl(fd, CDROMREADTOCENTRY, &te) == 0)
+            te.track = 0xAA;
+            if (ioctl(fd, CDIOREADTOCENTRY, &te) == 0)
             {
-                cddb_disc_set_length(disc, (te.cdte_addr.lba+SECONDS_TO_FRAMES(2))/SECONDS_TO_FRAMES(1));
+                cddb_disc_set_length(disc, (ntohl(te.entry.addr.lba)+SECONDS_TO_FRAMES(2))/SECONDS_TO_FRAMES(1));
             }
         }
     }
