--- interface/cooked_interface.c.orig	Wed Apr 19 15:41:04 2000
+++ interface/cooked_interface.c	Fri Nov  7 17:16:03 2003
@@ -1,6 +1,8 @@
 /******************************************************************
  * CopyPolicy: GNU Public License 2 applies
  * Copyright (C) Monty xiphmont@mit.edu
+ * FreeBSD porting (c) 2003
+ * 	Simon 'corecode' Schubert <corecode@corecode.ath.cx>
  *
  * CDROM code specific to the cooked ioctl interface
  *
@@ -10,6 +12,7 @@
 #include "common_interface.h"
 #include "utils.h"
 
+#ifdef Linux
 static int cooked_readtoc (cdrom_drive *d){
   int i;
   int tracks;
@@ -129,6 +132,142 @@
   return(sectors);
 }
 
+#elif defined(__FreeBSD__)
+static int
+cooked_readtoc(cdrom_drive *d)
+{
+	int i;
+	struct ioc_toc_header hdr;
+	struct ioc_read_toc_single_entry entry;
+
+	if (ioctl(d->ioctl_fd, CDIOREADTOCHEADER, &hdr) == -1) {
+		int ret;
+
+		if (errno == EPERM) {
+			ret = -102;
+			cderror(d, "102: ");
+		} else {
+			ret = -4;
+			cderror(d, "004: Unable to read table of contents header: ");
+		}
+		cderror(d, strerror(errno));
+		cderror(d, "\n");
+		return ret;
+	}
+
+	entry.address_format = CD_LBA_FORMAT;
+	for (i = hdr.starting_track; i <= hdr.ending_track; ++i) {
+		entry.track = i;
+		
+		if (ioctl(d->ioctl_fd, CDIOREADTOCENTRY, &entry) == -1) {
+			cderror(d, "005: Unable to read table of contents entry\n");
+			return -5;
+		}
+
+		d->disc_toc[i - hdr.starting_track].bFlags = entry.entry.control;
+		d->disc_toc[i - hdr.starting_track].bTrack = entry.entry.track;
+		d->disc_toc[i - hdr.starting_track].dwStartSector = be32_to_cpu(entry.entry.addr.lba);
+	}
+	
+	entry.track = 0xaa;	/* leadout */
+
+	if (ioctl(d->ioctl_fd, CDIOREADTOCENTRY, &entry) == -1) {
+		cderror(d, "005: Unable to read table of contents entry\n");
+		return -5;
+	}
+
+	d->disc_toc[i - hdr.starting_track].bFlags = entry.entry.control;
+	d->disc_toc[i - hdr.starting_track].bTrack = entry.entry.track;
+	d->disc_toc[i - hdr.starting_track].dwStartSector = be32_to_cpu(entry.entry.addr.lba);
+	
+	d->cd_extra = FixupTOC(d, hdr.ending_track - hdr.starting_track + 2);	/* with TOC */
+
+	return hdr.ending_track - hdr.starting_track + 1;
+}
+
+static int
+cooked_setspeed(cdrom_drive *d, int speed)
+{
+#ifdef CDRIOCREADSPEED
+	speed *= 177;
+	return ioctl(d->ioctl_fd, CDRIOCREADSPEED, &speed);
+#else
+	return -1;
+#endif
+}
+
+
+static long
+cooked_read(cdrom_drive *d, void *p, long begin, long sectors)
+{
+	int retry_count = 0;
+/* CDIOCREADAUDIO has been removed in FreeBSD 5.1-CURRENT */
+#if __FreeBSD_version >= 501106
+	int bsize = CD_FRAMESIZE_RAW;
+#else
+	struct ioc_read_audio arg;
+
+	if (sectors > d->nsectors)
+		sectors = d->nsectors;
+
+	arg.address_format = CD_LBA_FORMAT;
+	arg.address.lba = begin;
+	arg.buffer = p;
+#endif
+
+#if  __FreeBSD_version >= 501106
+	if (ioctl(d->ioctl_fd, CDRIOCSETBLOCKSIZE, &bsize) == -1)
+		return -7;
+#endif
+	for (;;) {
+/* CDIOCREADAUDIO has been removed in FreeBSD 5.1-CURRENT */
+#if  __FreeBSD_version >= 501106
+		if (pread(d->ioctl_fd, p, sectors*bsize, begin*bsize) != sectors*bsize) {
+#else
+		arg.nframes = sectors;
+		if (ioctl(d->ioctl_fd, CDIOCREADAUDIO, &arg) == -1) {
+#endif
+			if (!d->error_retry)
+				return -7;
+
+			switch (errno) {
+			case ENOMEM:
+				if (sectors == 1) {
+					cderror(d, "300: Kernel memory error\n");
+					return -300;
+				}
+				/* FALLTHROUGH */
+			default:
+				if (sectors == 1) {
+					if (retry_count > MAX_RETRIES - 1) {
+						char b[256];
+						snprintf(b, sizeof(b),
+						    "010: Unable to access sector %ld; "
+						    "skipping...\n", begin);
+						cderror(d, b);
+						return -10;
+					}
+					break;
+				}
+			}
+
+			if (retry_count > 4 && sectors > 1)
+				sectors = sectors * 3 / 4;
+
+			++retry_count;
+
+			if (retry_count > MAX_RETRIES) {
+				cderror(d, "007: Unknown, unrecoverable error reading data\n");
+				return -7;
+			}
+		} else
+			break;
+	}
+
+	return sectors;
+}
+#endif
+
 /* hook */
 static int Dummy (cdrom_drive *d,int Switch){
   return(0);
@@ -193,6 +332,7 @@
 int cooked_init_drive (cdrom_drive *d){
   int ret;
 
+#ifdef Linux
   switch(d->drive_type){
   case MATSUSHITA_CDROM_MAJOR:	/* sbpcd 1 */
   case MATSUSHITA_CDROM2_MAJOR:	/* sbpcd 2 */
@@ -243,6 +383,9 @@
   default:
     d->nsectors=40; 
   }
+#elif defined(__FreeBSD__)
+  d->nsectors = 26;		/* FreeBSD only support 64K I/O transfer size */
+#endif
   d->enable_cdda = Dummy;
   d->read_audio = cooked_read;
   d->set_speed = cooked_setspeed;
