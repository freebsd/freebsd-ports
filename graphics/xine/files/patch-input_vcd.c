--- input/input_vcd.c.orig	Tue Jan  2 20:32:52 2001
+++ input/input_vcd.c	Thu Jan 18 17:22:35 2001
@@ -17,6 +17,8 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
  *
+ * 10-01-2001 : Modified to support FreeBSD again. Bruno Schwander
+ *
  * $Id: input_vcd.c,v 1.15 2000/12/30 23:28:45 guenter Exp $
  */
 
@@ -32,11 +34,18 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <string.h>
+
 #if defined (__linux__)
 #include <linux/cdrom.h>
 #else
+
+#if defined (__FreeBSD__)
+#include <sys/cdio.h>
+#include <sys/cdrio.h>
+#else
 #error "you need to add cdrom / VCD support for your platform to input_vcd"
 #endif
+#endif
 
 #include "xine.h"
 #include "monitor.h"
@@ -44,7 +53,13 @@
 
 static uint32_t xine_debug;
 
+#if defined (__FreeBSD__)
+/* make a link to the right devnode, like /dev/racd0c */
 #define CDROM          "/dev/cdrom"
+#else
+#define CDROM          "/dev/cdrom"
+#endif
+
 #define VCDSECTORSIZE  2324
 
 typedef struct {
@@ -58,11 +73,15 @@
 typedef struct {
   int                    fd;
 
-  struct cdrom_tochdr    tochdr;
-  struct cdrom_tocentry  tocent[100];
+  struct ioc_toc_header  tochdr;
+  struct cd_toc_entry    *tocent;
+#ifdef __FreeBSD__
+  off_t			 cur_sector;
+#else
+  u_long                 cur_sector;
+#endif
   int                    total_tracks;
   int                    cur_track;
-  uint8_t                cur_min, cur_sec, cur_frame;
 
   char                  *filelist[100];
 
@@ -79,34 +98,32 @@
 }
 
 static int input_vcd_read_toc (void) {
-  int i;
+
+  struct ioc_read_toc_entry te;
+  int ntracks;
 
   /* read TOC header */
-  if ( ioctl(gVCD.fd, CDROMREADTOCHDR, &gVCD.tochdr) == -1 ) {
+  if ( ioctl(gVCD.fd, CDIOREADTOCHEADER, &gVCD.tochdr) == -1 ) {
     fprintf (stderr, "input_vcd : error in ioctl CDROMREADTOCHDR\n");
     return -1;
   }
 
-  /* read individual tracks */
-  for (i=gVCD.tochdr.cdth_trk0; i<=gVCD.tochdr.cdth_trk1; i++) {
-    gVCD.tocent[i-1].cdte_track = i;
-    gVCD.tocent[i-1].cdte_format = CDROM_MSF;
-    if ( ioctl(gVCD.fd, CDROMREADTOCENTRY, &gVCD.tocent[i-1]) == -1 ) {
-      fprintf (stderr, "input_vcd: error in ioctl CDROMREADTOCENTRY\n");
-      return -1;
-    }
-  }
-
-  /* read the lead-out track */
-  gVCD.tocent[gVCD.tochdr.cdth_trk1].cdte_track = CDROM_LEADOUT;
-  gVCD.tocent[gVCD.tochdr.cdth_trk1].cdte_format = CDROM_MSF;
 
-  if (ioctl(gVCD.fd, CDROMREADTOCENTRY, &gVCD.tocent[gVCD.tochdr.cdth_trk1]) == -1 ) {
+  ntracks = gVCD.tochdr.ending_track 
+    - gVCD.tochdr.starting_track + 2;
+  gVCD.tocent = (struct cd_toc_entry *)malloc(sizeof(*gVCD.tocent) * ntracks);
+  
+  te.address_format = CD_LBA_FORMAT;
+  te.starting_track = 0;
+  te.data_len = ntracks * sizeof(struct cd_toc_entry);
+  te.data = gVCD.tocent;
+  
+  if ( ioctl(gVCD.fd, CDIOREADTOCENTRYS, &te) == -1 ){
     fprintf (stderr, "input_vcd: error in ioctl CDROMREADTOCENTRY\n");
     return -1;
   }
 
-  gVCD.total_tracks = gVCD.tochdr.cdth_trk1;
+  gVCD.total_tracks = gVCD.tochdr.ending_track+1;
 
   return 0;
 }
@@ -149,10 +166,12 @@
     return 0;
   }
 
-  gVCD.cur_min   = gVCD.tocent[gVCD.cur_track].cdte_addr.msf.minute;
-  gVCD.cur_sec   = gVCD.tocent[gVCD.cur_track].cdte_addr.msf.second;
-  gVCD.cur_frame = gVCD.tocent[gVCD.cur_track].cdte_addr.msf.frame;
-  
+
+  gVCD.cur_sector = 
+    ntohl(gVCD.tocent
+	  [gVCD.cur_track - gVCD.tochdr.starting_track].addr.lba);
+
+
   return 1;
 }
 
@@ -160,95 +179,52 @@
 
 static uint32_t input_plugin_read (char *buf, uint32_t nlen) {
 
-  static struct cdrom_msf  msf ;
-  static cdsector_t        data;
-  struct cdrom_msf0       *end_msf;
+  static cdsector_t data;
+  int bsize = 2352;
 
   if (nlen != VCDSECTORSIZE)
     return 0;
 
-  do
-  {  
-    end_msf = &gVCD.tocent[gVCD.cur_track+1].cdte_addr.msf;
-
-    /*
-    printf ("cur: %02d:%02d:%02d  end: %02d:%02d:%02d\n",
-  	  gVCD.cur_min, gVCD.cur_sec, gVCD.cur_frame,
-  	  end_msf->minute, end_msf->second, end_msf->frame);
-    */
-
-    if ( (gVCD.cur_min>=end_msf->minute) && (gVCD.cur_sec>=end_msf->second)
-         && (gVCD.cur_frame>=end_msf->frame))
-      return 0;
-
-    msf.cdmsf_min0	= gVCD.cur_min;
-    msf.cdmsf_sec0	= gVCD.cur_sec;
-    msf.cdmsf_frame0	= gVCD.cur_frame;
-
-    memcpy (&data, &msf, sizeof (msf));
-
-    if (ioctl (gVCD.fd, CDROMREADRAW, &data) == -1) {
-      fprintf (stderr, "input_vcd: error in CDROMREADRAW\n");
+  if (ioctl (gVCD.fd, CDRIOCSETBLOCKSIZE, &bsize) == -1) {
+    fprintf (stderr, "sos input_vcd: error in CDRIOCSETBLOCKSIZE %d\n", errno);
+    return 0;
+  }
+  if (lseek (gVCD.fd, gVCD.cur_sector * bsize, SEEK_SET) == -1) {
+    fprintf (stderr, "sos input_vcd: seek error %d\n", errno);
+    return 0;
+  }
+  do{
+    if (read (gVCD.fd, &data, bsize) == -1) {
+      fprintf (stderr, "sos input_vcd: read error %d\n", errno);
       return 0;
     }
-
-
-    gVCD.cur_frame++;
-    if (gVCD.cur_frame>=75) {
-      gVCD.cur_frame = 0;
-      gVCD.cur_sec++;
-      if (gVCD.cur_sec>=60) {
-        gVCD.cur_sec = 0;
-        gVCD.cur_min++;
-      }
-    }
-    
-    /* Header ID check for padding sector. VCD uses this to keep constant
-       bitrate so the CD doesn't stop/start */
-  }
-  while((data.subheader[2]&~0x01)==0x60);
-  
-  memcpy (buf, data.data, VCDSECTORSIZE); /* FIXME */
+    gVCD.cur_sector++;
+  }while((data.subheader[2]&~0x01)==0x60);
+  memcpy (buf, data.data, VCDSECTORSIZE);
   return VCDSECTORSIZE;
 }
 
 static off_t input_plugin_seek (off_t offset, int origin) {
 
-  struct cdrom_msf0       *start_msf;
+
+  u_long start;
   uint32_t dist ;
   off_t sector_pos;
 
-  start_msf = &gVCD.tocent[gVCD.cur_track].cdte_addr.msf;
+  start = 
+    ntohl(gVCD.tocent
+	  [gVCD.cur_track - gVCD.tochdr.starting_track].addr.lba);
 
   switch (origin) {
   case SEEK_SET:
     dist = offset / VCDSECTORSIZE;
-
-    gVCD.cur_min = dist / (60*75) + start_msf->minute;
-    dist %= 60;
-    gVCD.cur_sec = dist / 75 + start_msf->second;
-    dist %= 75;
-    gVCD.cur_frame = dist + start_msf->frame;
-
-    xprintf (VERBOSE|INPUT, "%d => %02d:%02d:%02d\n",offset,gVCD.cur_min,gVCD.cur_sec,gVCD.cur_frame);
-
+    gVCD.cur_sector = start + dist;
     break;
   case SEEK_CUR:
     if (offset) 
       fprintf (stderr, "input_vcd: SEEK_CUR not implemented for offset != 0\n");
 
-    sector_pos = 75 - start_msf->frame;
-    
-    if (start_msf->second<60)
-      sector_pos += (59 - start_msf->second) * 75;
-    
-    if ( gVCD.cur_min > start_msf->minute) {
-      sector_pos += (gVCD.cur_min - start_msf->minute-1) * 60 * 75;
-      
-      sector_pos += gVCD.cur_sec * 60;
-      
-      sector_pos += gVCD.cur_frame ;
-    }
+    sector_pos = gVCD.cur_sector;
 
     return sector_pos * VCDSECTORSIZE;
 
@@ -263,26 +239,21 @@
 }
 
 static off_t input_plugin_get_length (void) {
-  struct cdrom_msf0       *end_msf, *start_msf;
-  off_t len ;
-
-  start_msf = &gVCD.tocent[gVCD.cur_track].cdte_addr.msf;
-  end_msf   = &gVCD.tocent[gVCD.cur_track+1].cdte_addr.msf;
 
-  len = 75 - start_msf->frame;
-
-  if (start_msf->second<60)
-    len += (59 - start_msf->second) * 75;
-
-  if (end_msf->minute > start_msf->minute) {
-    len += (end_msf->minute - start_msf->minute-1) * 60 * 75;
+  off_t len ;
 
-    len += end_msf->second * 60;
 
-    len += end_msf->frame ;
-  }
+  len = 
+    ntohl(gVCD.tocent
+	  [gVCD.cur_track+1 
+	  - gVCD.tochdr.starting_track].addr.lba)
+    - ntohl(gVCD.tocent
+	    [gVCD.cur_track 
+	    - gVCD.tochdr.starting_track].addr.lba);
   
+
   return len * VCDSECTORSIZE;
+
 }
 
 static uint32_t input_plugin_get_capabilities (void) {
@@ -294,30 +265,6 @@
 }
 
 static int input_plugin_eject (void) {
-  int ret, status;
-
-  if((gVCD.fd = open(CDROM, O_RDONLY|O_NONBLOCK)) > -1) {
-    if((status = ioctl(gVCD.fd, CDROM_DRIVE_STATUS, CDSL_CURRENT)) > 0) {
-      switch(status) {
-      case CDS_TRAY_OPEN:
-	if((ret = ioctl(gVCD.fd, CDROMCLOSETRAY)) != 0) {
-	  xprintf(VERBOSE|INPUT, "CDROMCLOSETRAY failed: %s\n", strerror(errno));  
-	}
-	break;
-      case CDS_DISC_OK:
-	if((ret = ioctl(gVCD.fd, CDROMEJECT)) != 0) {
-	  xprintf(VERBOSE|INPUT, "CDROMEJECT failed: %s\n", strerror(errno));  
-	}
-	break;
-      }
-    }
-    else {
-      xprintf(VERBOSE|INPUT, "CDROM_DRIVE_STATUS failed: %s\n", 
-	      strerror(errno));
-      close(gVCD.fd);
-      return 0;
-    }
-  }
 
   close(gVCD.fd);
   
@@ -339,9 +286,8 @@
 
   int i;
 
-  /* printf ("input_vcd: get_autoplay_list\n"); */
 
-  gVCD.fd = open (CDROM, O_RDONLY);
+  gVCD.fd = open (CDROM, O_RDWR);
 
   if (gVCD.fd == -1) {
     return NULL;
@@ -358,11 +304,9 @@
 
   *nFiles = gVCD.total_tracks;
   
-  /* printf ("%d tracks\n",gVCD.total_tracks); */
 
   for (i=0; i<gVCD.total_tracks; i++) {
     sprintf (gVCD.filelist[i], "vcd://%d",i);
-    /* printf ("list[%d] : %d %s\n", i, gVCD.filelist[i], gVCD.filelist[i]);  */
   }
 
   return gVCD.filelist;
@@ -413,5 +357,3 @@
 
   return &plugin_op;
 }
-
-
