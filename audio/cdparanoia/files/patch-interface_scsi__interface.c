--- interface/scsi_interface.c.orig	2019-07-25 21:55:03 UTC
+++ interface/scsi_interface.c
@@ -3,6 +3,8 @@
  * Original interface.c Copyright (C) 1994-1997 
  *            Eissfeldt heiko@colossus.escape.de
  * Current incarnation Copyright (C) 1998-2008 Monty xiphmont@mit.edu
+ * FreeBSD porting (c) 2003
+ * 	Simon 'corecode' Schubert <corecode@corecode.ath.cx>
  * 
  * Generic SCSI interface specific code.
  *
@@ -36,6 +38,7 @@ static void tweak_SG_buffer(cdrom_drive *d) {
   int table, reserved, cur, err;
   char buffer[256];
 
+#ifdef Linux
   /* SG_SET_RESERVED_SIZE doesn't actually allocate or reserve anything.
    * what it _does_ do is give you an error if you ask for a value
    * larger than q->max_sectors (the length of the device's bio request
@@ -54,6 +57,10 @@ static void tweak_SG_buffer(cdrom_drive *d) {
      implement working sg lists with SG_IO devices, so who knows... */
   if (ioctl(d->cdda_fd, SG_GET_SG_TABLESIZE, &table) < 0)
     table=1;
+#else
+  reserved = 26 * CD_FRAMESIZE_RAW;	/* FreeBSD only supports 64K I/O transfer size */
+  table = 1;
+#endif
 
   sprintf(buffer,"\tDMA scatter/gather table entries: %d\n\t"
 	  "table entry size: %d bytes\n\t"
@@ -93,6 +100,7 @@ static void tweak_SG_buffer(cdrom_drive *d) {
   cdmessage(d,buffer);
 }
 
+#ifdef Linux
 static void clear_garbage(cdrom_drive *d){
   fd_set fdset;
   struct timeval tv;
@@ -123,6 +131,7 @@ static void clear_garbage(cdrom_drive *d){
     flag=1;
   }
 }
+#endif
 
 static int check_sbp_error(const unsigned char status,
 			   const unsigned char *sbp) {
@@ -172,6 +181,7 @@ static int check_sbp_error(const unsigned char status,
   return 0;
 }
 
+#ifdef Linux
 /* process a complete scsi command. */
 static int sg2_handle_scsi_cmd(cdrom_drive *d,
 			       unsigned char *cmd,
@@ -332,7 +342,9 @@ static int sg2_handle_scsi_cmd(cdrom_drive *d,
   }
   return(0);
 }
+#endif
 
+#ifdef Linux
 static int sgio_handle_scsi_cmd(cdrom_drive *d,
 				unsigned char *cmd,
 				unsigned int cmd_len, 
@@ -417,7 +429,9 @@ static int sgio_handle_scsi_cmd(cdrom_drive *d,
   errno = 0;
   return 0;
 }
+#endif
 
+#ifdef Linux
 static int handle_scsi_cmd(cdrom_drive *d,
 			   unsigned char *cmd,
 			   unsigned int cmd_len, 
@@ -433,6 +447,117 @@ static int handle_scsi_cmd(cdrom_drive *d,
 
 }
 
+#elif defined(__FreeBSD__)
+static int handle_scsi_cmd(cdrom_drive *d,
+			   unsigned char *cmd,
+			   unsigned int cmd_len,
+			   unsigned int in_size,
+			   unsigned int out_size,
+			   unsigned char bytefill,
+			   int bytecheck,
+			   unsigned char *sense){
+	int result;
+	int error_code, sense_key, asc, ascq;
+	
+	bzero(&d->ccb->csio, sizeof(d->ccb->csio));
+
+	memcpy(d->ccb->csio.cdb_io.cdb_bytes, cmd, cmd_len);
+
+	if (bytecheck && in_size == 0)
+		memset(d->private->sg_buffer, bytefill, out_size);
+
+	cam_fill_csio(&d->ccb->csio,
+	    /* retries */ 0,
+	    /* cbfcnp */ NULL,
+	    /* flags */ CAM_DEV_QFRZDIS | (in_size ? CAM_DIR_OUT : CAM_DIR_IN),
+	    /* tag_action */ MSG_SIMPLE_Q_TAG,
+	    /* data_ptr */ in_size ? cmd + cmd_len : d->private->sg_buffer,
+	    /* dxfer_len */ out_size ? out_size : in_size,
+	    /* sense_len */ SSD_FULL_SIZE,
+	    /* cdb_len */ cmd_len,
+	    /* timeout */ 60000);	/* XXX */
+
+	struct timespec tv1, tv2;
+	int tret1=clock_gettime(d->private->clock,&tv1);
+	if ((result = cam_send_ccb(d->dev, d->ccb)) < 0 ||
+	    (d->ccb->ccb_h.status & CAM_STATUS_MASK) == 0 /* hack? */)
+		return TR_EREAD;
+	int tret2=clock_gettime(d->private->clock,&tv2);
+
+	if ((d->ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP &&
+	    (d->ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_SCSI_STATUS_ERROR) {
+		fprintf (stderr, "\t\terror returned from SCSI command:\n"
+				 "\t\tccb->ccb_h.status == %d\n", d->ccb->ccb_h.status);
+		errno = EIO;
+		return TR_UNKNOWN;
+	}
+
+	if (d->ccb->csio.dxfer_len != out_size) {
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
+	if(bytecheck && out_size){
+		long i, flag=0;
+		for(i=in_size;i<out_size;i++)
+			if(d->private->sg_buffer[i]!=bytefill){
+				flag=1;
+				break;
+			}
+		if(!flag){
+			errno=EINVAL;
+			return(TR_ILLEGAL);
+		}
+	}
+
+	if(tret1<0 || tret2<0)
+		d->private->last_milliseconds=-1;
+	else
+		d->private->last_milliseconds = (tv2.tv_sec-tv1.tv_sec)*1000. + (tv2.tv_nsec-tv1.tv_nsec)/1000000.;
+
+	return 0;
+}
+#endif
+
 static int test_unit_ready(cdrom_drive *d){
   unsigned char sense[SG_MAX_SENSE];
   unsigned char key, ASC, ASCQ;
@@ -453,6 +581,7 @@ static int test_unit_ready(cdrom_drive *d){
   return 1;
 }
 
+#ifdef Linux
 static void reset_scsi(cdrom_drive *d){
   int arg,tries=0;
   d->enable_cdda(d,0);
@@ -472,6 +601,27 @@ static void reset_scsi(cdrom_drive *d){
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
+		if (((d->ccb->ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP) ||
+		    ((d->ccb->ccb_h.status & CAM_STATUS_MASK) == CAM_BDR_SENT))
+			cdmessage(d,"OK\n");
+		else
+			cdmessage(d,"FAILED\n");
+	}
+	d->enable_cdda(d,1);
+}
+#endif
+
 static int mode_sense_atapi(cdrom_drive *d,int size,int page){ 
   unsigned char sense[SG_MAX_SENSE];
   unsigned char cmd[10]= {0x5A,   /* MODE_SENSE */
@@ -1074,29 +1226,35 @@ static long scsi_read_map (cdrom_drive *d, void *p, lo
 
     if((err=map(d,(p?buffer:NULL),begin,sectors,sense))){
       if(d->report_all){
+#ifdef __FreeBSD__
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
 		(int)(sense[2]&0xf),
 		(int)(sense[12]),
 		(int)(sense[13]));
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
-		(int)(sense[2]&0xf),
-		(int)(sense[12]),
-		(int)(sense[13]));
-	fprintf(stderr,"                 Transport error: %s\n",strerror_tr[err]);
-	fprintf(stderr,"                 System error: %s\n",strerror(errno));
       }
       
       switch(errno){
@@ -1583,6 +1741,7 @@ static void check_cache(cdrom_drive *d){
   }
 }
 
+#ifdef Linux
 static int check_atapi(cdrom_drive *d){
   int atapiret=-1;
   int fd = d->cdda_fd; /* check the device we'll actually be using to read */
@@ -1614,6 +1773,53 @@ static int check_atapi(cdrom_drive *d){
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
   unsigned char *b;
   cdmessage(d,"\nChecking for MMC style command set...\n");
@@ -1660,6 +1866,7 @@ static void check_exceptions(cdrom_drive *d,exception 
   }
 }
 
+#ifdef Linux
 /* request vendor brand and model */
 unsigned char *scsi_inquiry(cdrom_drive *d){
   unsigned char sense[SG_MAX_SENSE];
@@ -1671,6 +1878,7 @@ unsigned char *scsi_inquiry(cdrom_drive *d){
   }
   return (d->private->sg_buffer);
 }
+#endif
 
 int scsi_init_drive(cdrom_drive *d){
   int ret;
