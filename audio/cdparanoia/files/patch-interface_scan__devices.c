--- interface/scan_devices.c.orig	2008-08-26 09:55:22 UTC
+++ interface/scan_devices.c
@@ -1,6 +1,8 @@
 /******************************************************************
  * CopyPolicy: GNU Lesser General Public License 2.1 applies
  * Copyright (C) 1998-2008 Monty xiphmont@mit.edu
+ * FreeBSD porting (c) 2003
+ * 	Simon 'corecode' Schubert <corecode@corecode.ath.cx>
  * 
  * Autoscan for or verify presence of a cdrom device
  * 
@@ -24,6 +26,8 @@
 
 #define MAX_DEV_LEN 20 /* Safe because strings only come from below */
 /* must be absolute paths! */
+
+#ifdef Linux
 static char *scsi_cdrom_prefixes[]={
   "/dev/scd",
   "/dev/sr",
@@ -52,6 +56,17 @@ static char *cdrom_devices[]={
   "/dev/cm206cd",
   "/dev/gscd",
   "/dev/optcd",NULL};
+#elif defined(__FreeBSD__)
+static char *cdrom_devices[] = {
+	"/dev/cd?",
+	"/dev/acd?",
+	"/dev/wcd?",
+	"/dev/mcd?",
+	"/dev/cd?c",
+	"/dev/acd?c",
+	"/dev/wcd?c",
+	"/dev/mcd?c", NULL};
+#endif
 
 /* Functions here look for a cdrom drive; full init of a drive type
    happens in interface.c */
@@ -61,6 +76,9 @@ cdrom_drive *cdda_find_a_cdrom(int messagedest,char **
   
   int i=0;
   cdrom_drive *d;
+#if defined(__FreeBSD__)
+  struct passwd *pwent;
+#endif
 
   while(cdrom_devices[i]!=NULL){
 
@@ -78,10 +96,12 @@ cdrom_drive *cdda_find_a_cdrom(int messagedest,char **
 	if((d=cdda_identify(buffer,messagedest,messages)))
 	  return(d);
 	idmessage(messagedest,messages,"",NULL);
+#ifdef Linux
 	buffer[pos-(cdrom_devices[i])]=j+97;
 	if((d=cdda_identify(buffer,messagedest,messages)))
 	  return(d);
 	idmessage(messagedest,messages,"",NULL);
+#endif
       }
     }else{
       /* Name.  Go for it. */
@@ -92,9 +112,21 @@ cdrom_drive *cdda_find_a_cdrom(int messagedest,char **
     }
     i++;
   }
+
+#if Linux
   idmessage(messagedest,messages,
 	    "\n\nNo cdrom drives accessible to %s found.\n",
 	    cuserid(NULL));
+#elif defined(__FreeBSD__)
+  pwent = getpwuid(geteuid());
+  if (pwent == NULL)
+    idmessage(messagedest,messages,
+	      "\n\nNo accessible cdrom drives found.\n", NULL);
+  else
+    idmessage(messagedest,messages,
+	      "\n\nNo cdrom drives accessible to %s found.\n",
+	      pwent->pw_name);
+#endif
   return(NULL);
 }
 
@@ -145,6 +179,7 @@ char *test_resolve_symlink(const char *file,int messag
 
 }
 
+#ifdef Linux
 cdrom_drive *cdda_identify_cooked(const char *dev, int messagedest,
 				  char **messages){
 
@@ -274,6 +309,61 @@ cdrom_drive *cdda_identify_cooked(const char *dev, int
   return(d);
 }
 
+#elif defined(__FreeBSD__)
+cdrom_drive *
+cdda_identify_cooked(const char *dev, int messagedest, char **messages)
+{
+	cdrom_drive *d;
+	struct stat st;
+
+	if (stat(dev, &st)) {
+		idperror(messagedest, messages, "\t\tCould not stat %s", dev);
+		return NULL;
+	}
+
+	if (!S_ISCHR(st.st_mode)) {
+		idmessage(messagedest, messages, "\t\t%s is no block device", dev);
+		return NULL;
+	}
+	
+	if ((d = calloc(1, sizeof(*d))) == NULL) {
+		idperror(messagedest, messages, "\t\tCould not allocate memory", NULL);
+		return NULL;
+	}
+	d->ioctl_fd = -1;
+
+	if ((d->ioctl_fd = open(dev, O_RDONLY)) == -1) {
+		idperror(messagedest, messages, "\t\tCould not open %s", dev);
+		goto cdda_identify_cooked_fail;
+	}
+
+	if (ioctl_ping_cdrom(d->ioctl_fd)) {
+		idmessage(messagedest, messages, "\t\tDevice %s is not a CDROM", dev);
+		goto cdda_identify_cooked_fail;
+	}
+
+	d->cdda_device_name = copystring(dev);
+	d->drive_model = copystring("Generic cooked ioctl CDROM");
+	d->interface = COOKED_IOCTL;
+	d->bigendianp = -1;
+	d->nsectors = -1;
+
+	idmessage(messagedest, messages, "\t\tCDROM sensed: %s\n", d->drive_model);
+
+	return d;
+
+cdda_identify_cooked_fail:
+	if (d != NULL) {
+		if (d->ioctl_fd != -1)
+			close(d->ioctl_fd);
+		free(d);
+	}
+	return NULL;
+}
+#endif
+
+
+#ifdef Linux
 struct  sg_id {
   long    l1; /* target | lun << 8 | channel << 16 | low_ino << 24 */
   long    l2; /* Unique id */
@@ -400,6 +490,7 @@ matchfail:
   if(dev!=-1)close(dev);
   return(NULL);
 }
+#endif
 
 void strscat(char *a,char *b,int n){
   int i;
@@ -411,6 +502,7 @@ void strscat(char *a,char *b,int n){
   strcat(a," ");
 }
 
+#ifdef Linux
 /* At this point, we're going to punt compatability before SG2, and
    allow only SG2 and SG3 */
 static int verify_SG_version(cdrom_drive *d,int messagedest,
@@ -780,6 +872,90 @@ cdda_identify_scsi_fail:
   }
   return(NULL);
 }
+#elif defined(__FreeBSD__)
+
+cdrom_drive *cdda_identify_scsi(const char *dummy,
+    const char *device,
+    int messagedest,
+    char **messages)
+{
+	char *devname;
+	cdrom_drive *d = NULL;
+
+	if (device == NULL) {
+		idperror(messagedest, messages, "\t\tNo device specified", NULL);
+		return NULL;
+	}
+
+	if ((devname = test_resolve_symlink(device, messagedest, messages)) == NULL)
+		return NULL;
+
+	if ((d = calloc(1, sizeof(*d))) == NULL) {
+		idperror(messagedest, messages, "\t\tCould not allocate memory", NULL);
+		free(devname);
+		return NULL;
+	}
+
+	if ((d->dev = cam_open_device(devname, O_RDWR)) == NULL) {
+		idperror(messagedest, messages, "\t\tCould not open SCSI device: %s", cam_errbuf);
+		goto cdda_identify_scsi_fail;
+	}
+
+	if ((d->ccb = cam_getccb(d->dev)) == NULL) {
+		idperror(messagedest, messages, "\t\tCould not allocate ccb", NULL);
+		goto cdda_identify_scsi_fail;
+	}
+
+	if (strncmp(d->dev->inq_data.vendor, "TOSHIBA", 7) == 0 &&
+	    strncmp(d->dev->inq_data.product, "CD_ROM", 6) == 0 &&
+	    SID_TYPE(&d->dev->inq_data) == T_DIRECT) {
+		d->dev->inq_data.device = T_CDROM;
+		d->dev->inq_data.dev_qual2 |= 0x80;
+	}
+
+	if (SID_TYPE(&d->dev->inq_data) != T_CDROM &&
+	    SID_TYPE(&d->dev->inq_data) != T_WORM) {
+		idmessage(messagedest, messages,
+		    "\t\tDevice is neither a CDROM nor a WORM device\n", NULL);
+		goto cdda_identify_scsi_fail;
+	}
+
+	d->cdda_device_name = copystring(devname);
+	d->ioctl_fd = -1;
+	d->bigendianp = -1;
+	d->nsectors = -1;
+	d->lun = d->dev->target_lun;
+	d->interface = GENERIC_SCSI;
+
+	d->private=calloc(1,sizeof(*d->private));
+	if ((d->private->sg_buffer=(unsigned char *)(d->private->sg_hd=malloc(MAX_BIG_BUFF_SIZE))) == NULL) {
+		idperror(messagedest, messages, "Could not allocate buffer memory", NULL);
+		goto cdda_identify_scsi_fail;
+	}
+
+	if ((d->drive_model = calloc(36,1)) == NULL) {
+	}
+
+	strscat(d->drive_model, d->dev->inq_data.vendor, SID_VENDOR_SIZE);
+	strscat(d->drive_model, d->dev->inq_data.product, SID_PRODUCT_SIZE);
+	strscat(d->drive_model, d->dev->inq_data.revision, SID_REVISION_SIZE);
+
+	idmessage(messagedest, messages, "\nCDROM model sensed: %s", d->drive_model);
+
+	return d;
+
+cdda_identify_scsi_fail:
+	free(devname);
+	if (d) {
+		if (d->ccb)
+			cam_freeccb(d->ccb);
+		if (d->dev)
+			cam_close_device(d->dev);
+		free(d);
+	}
+	return NULL;
+}
+#endif
 
 #ifdef CDDA_TEST
 
