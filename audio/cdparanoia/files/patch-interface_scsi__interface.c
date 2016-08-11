--- interface/scsi_interface.c.orig	2001-03-24 01:15:46 UTC
+++ interface/scsi_interface.c
@@ -3,6 +3,8 @@
  * Original interface.c Copyright (C) 1994-1997 
  *            Eissfeldt heiko@colossus.escape.de
  * Current blenderization Copyright (C) 1998-1999 Monty xiphmont@mit.edu
+ * FreeBSD porting (c) 2003
+ * 	Simon 'corecode' Schubert <corecode@corecode.ath.cx>
  * 
  * Generic SCSI interface specific code.
  *
@@ -23,6 +25,7 @@ static void tweak_SG_buffer(cdrom_drive 
   int table,reserved;
   char buffer[256];
 
+#ifdef Linux
   /* maximum transfer size? */
   if(ioctl(d->cdda_fd,SG_GET_RESERVED_SIZE,&reserved)){
     /* Up, guess not. */
@@ -59,8 +62,17 @@ static void tweak_SG_buffer(cdrom_drive 
     cdmessage(d,"\tCouldn't disable command queue!  Continuing anyway...\n");
   }
 
+#elif defined(__FreeBSD__)
+  d->nsectors = 26;		/* FreeBSD only supports 64K I/O transfer size */
+  d->bigbuff = d->nsectors * CD_FRAMESIZE_RAW;
+  
+  sprintf(buffer,"\tSetting default read size to %d sectors (%d bytes).\n\n",
+      d->nsectors,d->nsectors*CD_FRAMESIZE_RAW);
+  cdmessage(d,buffer);
+#endif
 }
 
+#ifdef Linux
 static void reset_scsi(cdrom_drive *d){
   int arg;
   d->enable_cdda(d,0);
@@ -74,6 +86,30 @@ static void reset_scsi(cdrom_drive *d){
   d->enable_cdda(d,1);
 }
 
+#elif defined(__FreeBSD__)
+static void reset_scsi(cdrom_drive *d) {
+	d->enable_cdda(d,0);
+
+	d->ccb->ccb_h.func_code = XPT_RESET_DEV;
+	d->ccb->ccb_h.timeout = 5000;
+
+	cdmessage(d, "sending SCSI reset... ");
+	if (cam_send_ccb(d->dev, d->ccb)) {
+		cdmessage(d, "error sending XPT_RESET_DEV CCB");
+	} else {
+	
+		if (((d->ccb->ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP) ||
+		    ((d->ccb->ccb_h.status & CAM_STATUS_MASK) == CAM_BDR_SENT))
+			cdmessage(d,"OK\n");
+		else
+			cdmessage(d,"FAILED\n");
+	}
+
+	d->enable_cdda(d,1);
+}
+#endif
+
+#ifdef Linux
 static void clear_garbage(cdrom_drive *d){
   fd_set fdset;
   struct timeval tv;
@@ -104,8 +140,10 @@ static void clear_garbage(cdrom_drive *d
     flag=1;
   }
 }
+#endif
 
 /* process a complete scsi command. */
+#ifdef Linux
 static int handle_scsi_cmd(cdrom_drive *d,
 			   unsigned int cmd_len, 
 			   unsigned int in_size, 
@@ -284,6 +322,95 @@ static int handle_scsi_cmd(cdrom_drive *
   return(0);
 }
 
+#elif defined(__FreeBSD__)
+static int handle_scsi_cmd(cdrom_drive *d,
+			   unsigned int cmd_len, 
+			   unsigned int out_size, 
+			   unsigned int in_size,
+			   unsigned char bytefill,
+			   int bytecheck) {
+	int result;
+	int error_code, sense_key, asc, ascq;
+	
+	bzero(&d->ccb->csio, sizeof(d->ccb->csio));
+
+	memcpy(d->ccb->csio.cdb_io.cdb_bytes, d->sg_buffer, cmd_len);
+
+	if (bytecheck && out_size == 0)
+		memset(d->sg_buffer, bytefill, in_size);
+
+	cam_fill_csio(&d->ccb->csio,
+	    /* retries */ 0,
+	    /* cbfcnp */ NULL,
+	    /* flags */ CAM_DEV_QFRZDIS | (out_size ? CAM_DIR_OUT : CAM_DIR_IN),
+	    /* tag_action */ MSG_SIMPLE_Q_TAG,
+	    /* data_ptr */ out_size ? d->sg_buffer + cmd_len : d->sg_buffer,
+	    /* dxfer_len */ out_size ? out_size : in_size,
+	    /* sense_len */ SSD_FULL_SIZE,
+	    /* cdb_len */ cmd_len,
+	    /* timeout */ 60000);	/* XXX */
+
+	if ((result = cam_send_ccb(d->dev, d->ccb)) < 0 ||
+	    (d->ccb->ccb_h.status & CAM_STATUS_MASK) == 0 /* hack? */)
+		return TR_EREAD;
+
+	if ((d->ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP &&
+	    (d->ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_SCSI_STATUS_ERROR) {
+		fprintf (stderr, "\t\terror returned from SCSI command:\n"
+				 "\t\tccb->ccb_h.status == %d\n", d->ccb->ccb_h.status);
+		errno = EIO;
+		return TR_UNKNOWN;
+	}
+
+	if (d->ccb->csio.dxfer_len != in_size) {
+		errno = EIO;
+		return TR_EREAD;
+	}
+
+	scsi_extract_sense(&d->ccb->csio.sense_data, &error_code, &sense_key,
+			   &asc, &ascq);
+
+	switch (error_code) {
+	case SSD_CURRENT_ERROR:
+	case SSD_DEFERRED_ERROR:
+#if (CAM_VERSION > 0x15)
+	case SSD_DESC_CURRENT_ERROR:
+	case SSD_DESC_DEFERRED_ERROR:
+#endif
+		switch (sense_key) {
+		case SSD_KEY_NO_SENSE:
+			errno = EIO;
+			return TR_UNKNOWN;
+		case SSD_KEY_RECOVERED_ERROR:
+			break;
+		case SSD_KEY_NOT_READY:
+			errno = EBUSY;
+			return TR_BUSY;
+		case SSD_KEY_MEDIUM_ERROR:
+			errno = EIO;
+			if ((asc == 0x0c) && (ascq == 0x09))
+				return TR_STREAMING;
+			else
+				return TR_MEDIUM;
+		case SSD_KEY_HARDWARE_ERROR:
+			errno = EIO;
+			return TR_FAULT;
+		case SSD_KEY_ILLEGAL_REQUEST:
+			errno = EINVAL;
+			return TR_ILLEGAL;
+		default:
+			errno = EIO;
+			return TR_UNKNOWN;
+		}
+	default:
+		break;
+	}
+
+	return 0;
+}
+#endif
+
+
 /* Group 1 (10b) command */
 
 static int mode_sense_atapi(cdrom_drive *d,int size,int page){ 
@@ -833,30 +960,37 @@ static long scsi_read_map (cdrom_drive *
   while(1) {
     if((err=map(d,(p?buffer:NULL),begin,sectors))){
       if(d->report_all){
+#ifdef Linux
 	struct sg_header *sg_hd=(struct sg_header *)d->sg;
+#elif defined(__FreeBSD__)
+	int error_code, sense_key, asc, ascq;
+#endif
 	char b[256];
 
 	sprintf(b,"scsi_read error: sector=%ld length=%ld retry=%d\n",
 		begin,sectors,retry_count);
+	fputs(b, stderr);
 	cdmessage(d,b);
+#if defined(__FreeBSD__)
+	scsi_extract_sense(&d->ccb->csio.sense_data, &error_code, &sense_key,
+			   &asc, &ascq);
+#endif
 	sprintf(b,"                 Sense key: %x ASC: %x ASCQ: %x\n",
+#ifdef Linux
 		(int)(sg_hd->sense_buffer[2]&0xf),
 		(int)(sg_hd->sense_buffer[12]),
 		(int)(sg_hd->sense_buffer[13]));
+#elif defined(__FreeBSD__)
+		sense_key, asc, ascq);
+#endif
+	fputs(b, stderr);
 	cdmessage(d,b);
 	sprintf(b,"                 Transport error: %s\n",strerror_tr[err]);
+	fputs(b, stderr);
 	cdmessage(d,b);
 	sprintf(b,"                 System error: %s\n",strerror(errno));
+	fputs(b, stderr);
 	cdmessage(d,b);
-
-	fprintf(stderr,"scsi_read error: sector=%ld length=%ld retry=%d\n",
-		begin,sectors,retry_count);
-	fprintf(stderr,"                 Sense key: %x ASC: %x ASCQ: %x\n",
-		(int)(sg_hd->sense_buffer[2]&0xf),
-		(int)(sg_hd->sense_buffer[12]),
-		(int)(sg_hd->sense_buffer[13]));
-	fprintf(stderr,"                 Transport error: %s\n",strerror_tr[err]);
-	fprintf(stderr,"                 System error: %s\n",strerror(errno));
       }
 
       if(!d->error_retry)return(-7);
@@ -1307,6 +1441,7 @@ static void check_fua_bit(cdrom_drive *d
   return;
 }
 
+#ifdef Linux
 static int check_atapi(cdrom_drive *d){
   int atapiret=-1;
   int fd = d->cdda_fd; /* this is the correct fd (not ioctl_fd), as the 
@@ -1333,6 +1468,53 @@ static int check_atapi(cdrom_drive *d){
   }
 }  
 
+#elif defined(__FreeBSD__)
+static int
+check_atapi(cdrom_drive *d)
+{
+	bzero(&(&d->ccb->ccb_h)[1], sizeof(d->ccb->cpi) - sizeof(d->ccb->ccb_h));
+	
+	d->ccb->ccb_h.func_code = XPT_PATH_INQ;
+
+	cdmessage(d, "\nChecking for ATAPICAM...\n");
+
+	if (cam_send_ccb(d->dev, d->ccb) < 0) {
+		cderror(d, "\terror sending XPT_PATH_INQ CCB: ");
+		cderror(d, cam_errbuf);
+		cderror(d, "\n");
+		return -1;
+	}
+
+	if ((d->ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
+		cderror(d, "\tXPT_PATH_INQ CCB failed: ");
+		cderror(d, cam_errbuf);
+		cderror(d, "\n");
+		return -1;
+	}
+
+	/*
+	 * if the bus device name is `ata', we're (obviously)
+	 * running ATAPICAM.
+	 * same for the new ahci(4) and siis(4) drivers and future others
+	 * which use SATA transport too...
+	 */
+
+	if (strncmp(d->ccb->cpi.dev_name, "ata", 3) == 0 ||
+#if __FreeBSD_version >= 800102
+	    d->ccb->cpi.transport == XPORT_SATA ||
+#endif
+	    d->ccb->cpi.transport == XPORT_ATA) {
+		cdmessage(d, "\tDrive is ATAPI (using ATAPICAM or direct CAM (S)ATA transport)\n");
+		d->is_atapi = 1;
+	} else {
+		cdmessage(d, "\tDrive is SCSI\n");
+		d->is_atapi = 0;
+	}
+	
+	return d->is_atapi;
+}
+#endif
+
 static int check_mmc(cdrom_drive *d){
   char *b;
   cdmessage(d,"\nChecking for MMC style command set...\n");
@@ -1379,6 +1561,7 @@ static void check_exceptions(cdrom_drive
   }
 }
 
+#ifdef Linux
 /* request vendor brand and model */
 unsigned char *scsi_inquiry(cdrom_drive *d){
   memcpy(d->sg_buffer,(char[]){ 0x12,0,0,0,56,0},6);
@@ -1389,6 +1572,7 @@ unsigned char *scsi_inquiry(cdrom_drive 
   }
   return (d->sg_buffer);
 }
+#endif
 
 
 int scsi_init_drive(cdrom_drive *d){
@@ -1458,8 +1642,12 @@ int scsi_init_drive(cdrom_drive *d){
   check_fua_bit(d);
 
   d->error_retry=1;
+#ifdef Linux
   d->sg=realloc(d->sg,d->nsectors*CD_FRAMESIZE_RAW + SG_OFF + 128);
   d->sg_buffer=d->sg+SG_OFF;
+#elif defined(__FreeBSD__)
+  d->sg_buffer = realloc(d->sg_buffer, d->nsectors * CD_FRAMESIZE_RAW);
+#endif
   d->report_all=1;
   return(0);
 }
