--- tapedev.c.orig	Wed Jul  3 13:21:52 2002
+++ tapedev.c	Mon Sep  2 11:43:24 2002
@@ -195,6 +195,7 @@
 /*-------------------------------------------------------------------*/
 /* Static data areas                                                 */
 /*-------------------------------------------------------------------*/
+#ifdef GNU_MTIO_SUPPORT
 static struct mt_tape_info tapeinfo[] = MT_TAPE_INFO;
 static struct mt_tape_info densinfo[] = {
     {0x01, "NRZI (800 bpi)"},
@@ -222,6 +223,7 @@
     {0x8C, "EXB-8505 compressed"},
     {0x90, "EXB-8205 compressed"},
     {0, NULL}};
+#endif
 
 static PARSER ptab[] =
 {
@@ -1143,6 +1145,7 @@
 /*-------------------------------------------------------------------*/
 static U32 status_scsitape (DEVBLK *dev)
 {
+#ifdef HAVE_MTIO_H
 U32             stat;                   /* Tape status bits          */
 int             rc;                     /* Return code               */
 struct mtget    stblk;                  /* Area for MTIOCGET ioctl   */
@@ -1159,6 +1162,7 @@
                 dev->filename, strerror(errno));
         return 0;
     }
+#ifdef GNU_MTIO_SUPPORT
     stat = stblk.mt_gstat;
 
     /* Display tape status */
@@ -1191,10 +1195,14 @@
         dev->prvblkpos = -1;
         dev->blockid = 0;
     }
+#else
+	 stat = 0;
+#endif
 
     /* Return tape status */
     return stat;
 
+#endif
 } /* end function status_scsitape */
 
 /*-------------------------------------------------------------------*/
@@ -1205,6 +1213,7 @@
 /*-------------------------------------------------------------------*/
 static int open_scsitape (DEVBLK *dev, BYTE *unitstat)
 {
+#ifdef HAVE_MTIO_H
 int             rc;                     /* Return code               */
 int             i;                      /* Array subscript           */
 struct mtop     opblk;                  /* Area for MTIOCTOP ioctl   */
@@ -1249,6 +1258,7 @@
         return -1;
     }
 
+#ifdef GNU_MTIO_SUPPORT
     /* Intervention required if no tape is mounted */
     if (GMT_DR_OPEN(stblk.mt_gstat))
     {
@@ -1284,6 +1294,7 @@
 
     /* Set the tape device to process variable length blocks */
     opblk.mt_op = MTSETBLK;
+#endif
     opblk.mt_count = 0;
     rc = ioctl (dev->fd, MTIOCTOP, (char*)&opblk);
     if (rc < 0)
@@ -1312,6 +1323,12 @@
 
     return 0;
 
+#else
+
+	 logmsg ("HHC286I SCSI Support is disabled\n");
+	 return -1
+
+#endif
 } /* end function open_scsitape */
 
 /*-------------------------------------------------------------------*/
@@ -1324,6 +1341,7 @@
 /*-------------------------------------------------------------------*/
 static int read_scsitape (DEVBLK *dev, BYTE *buf, BYTE *unitstat)
 {
+#ifdef HAVE_MTIO_H
 int             rc;                     /* Return code               */
 
     /* Read data block from SCSI tape device */
@@ -1347,6 +1365,12 @@
     /* Return block length or zero if tapemark  */
     return rc;
 
+#else
+
+	 logmsg ("HHC286I SCSI Support is disabled\n");
+	 return -1;
+
+#endif
 } /* end function read_scsitape */
 
 /*-------------------------------------------------------------------*/
@@ -1358,6 +1382,7 @@
 static int write_scsitape (DEVBLK *dev, BYTE *buf, U16 len,
                         BYTE *unitstat)
 {
+#ifdef HAVE_MTIO_H
 int             rc;                     /* Return code               */
 
     /* Write data block to SCSI tape device */
@@ -1377,6 +1402,12 @@
     /* Return normal status */
     return 0;
 
+#else
+
+	 logmsg ("HHC286I SCSI Support is disabled\n");
+	 return -1;
+
+#endif
 } /* end function write_scsitape */
 
 /*-------------------------------------------------------------------*/
@@ -1387,6 +1418,7 @@
 /*-------------------------------------------------------------------*/
 static int write_scsimark (DEVBLK *dev, BYTE *unitstat)
 {
+#ifdef HAVE_MTIO_H
 int             rc;                     /* Return code               */
 struct mtop     opblk;                  /* Area for MTIOCTOP ioctl   */
 
@@ -1409,6 +1441,12 @@
     /* Return normal status */
     return 0;
 
+#else
+
+	 logmsg ("HHC286I SCSI Support is disabled\n");
+	 return -1;
+
+#endif
 } /* end function write_scsimark */
 
 /*-------------------------------------------------------------------*/
@@ -1421,6 +1459,7 @@
 /*-------------------------------------------------------------------*/
 static int fsb_scsitape (DEVBLK *dev, BYTE *unitstat)
 {
+#ifdef HAVE_MTIO_H
 int             rc;                     /* Return code               */
 int             fsrerrno;               /* Value of errno after MTFSR*/
 U32             stat;                   /* Tape status bits          */
@@ -1435,6 +1474,7 @@
     /* Obtain tape status after forward space */
     stat = status_scsitape (dev);
 
+#ifdef GNU_MTIO_SUPPORT
     /* If I/O error and status indicates EOF, then a tapemark
        was detected, so increment the file number and return 0 */
     if (rc < 0 && fsrerrno == EIO && GMT_EOF(stat))
@@ -1443,6 +1483,7 @@
         dev->blockid++;
         return 0;
     }
+#endif
 
     /* Handle MTFSR error condition */
     if (rc < 0)
@@ -1461,6 +1502,12 @@
     /* Return +1 to indicate forward space successful */
     return +1;
 
+#else
+
+	 logmsg ("HHC286I SCSI Support is disabled\n");
+	 return -1;
+
+#endif
 } /* end function fsb_scsitape */
 
 /*-------------------------------------------------------------------*/
@@ -1473,6 +1520,7 @@
 /*-------------------------------------------------------------------*/
 static int bsb_scsitape (DEVBLK *dev, BYTE *unitstat)
 {
+#ifdef HAVE_MTIO_H
 int             rc;                     /* Return code               */
 int             bsrerrno;               /* Value of errno after MTBSR*/
 U32             stat;                   /* Tape status bits          */
@@ -1481,6 +1529,7 @@
     /* Obtain tape status before backward space */
     stat = status_scsitape (dev);
 
+#ifdef GNU_MTIO_SUPPORT
     /* Unit check if already at start of tape */
     if (GMT_BOT(stat))
     {
@@ -1489,6 +1538,7 @@
         *unitstat = CSW_CE | CSW_DE | CSW_UC;
         return -1;
     }
+#endif
 
     /* Backspace block on SCSI tape */
     opblk.mt_op = MTBSR;
@@ -1527,6 +1577,12 @@
     /* Return +1 to indicate backspace successful */
     return +1;
 
+#else
+
+	 logmsg ("HHC286I SCSI Support is disabled\n");
+	 return -1;
+
+#endif
 } /* end function bsb_scsitape */
 
 /*-------------------------------------------------------------------*/
@@ -1538,6 +1594,7 @@
 /*-------------------------------------------------------------------*/
 static int fsf_scsitape (DEVBLK *dev, BYTE *unitstat)
 {
+#ifdef HAVE_MTIO_H
 int             rc;                     /* Return code               */
 struct mtop     opblk;                  /* Area for MTIOCTOP ioctl   */
 
@@ -1563,6 +1620,12 @@
     /* Return normal status */
     return 0;
 
+#else
+
+	 logmsg ("HHC286I SCSI Support is disabled\n");
+	 return -1;
+
+#endif
 } /* end function fsf_scsitape */
 
 /*-------------------------------------------------------------------*/
@@ -1574,6 +1637,7 @@
 /*-------------------------------------------------------------------*/
 static int bsf_scsitape (DEVBLK *dev, BYTE *unitstat)
 {
+#ifdef HAVE_MTIO_H
 int             rc;                     /* Return code               */
 struct mtop     opblk;                  /* Area for MTIOCTOP ioctl   */
 
@@ -1600,6 +1664,12 @@
     /* Return normal status */
     return 0;
 
+#else
+
+	 logmsg("HHC286I SCSI Support is disabled\n");
+	 return -1;
+
+#endif
 } /* end function bsf_scsitape */
 
 /*-------------------------------------------------------------------*/
@@ -2726,7 +2796,9 @@
 
         case TAPEDEVT_SCSITAPE:
             stat = status_scsitape (dev);
+#ifdef GNU_MTIO_SUPPORT
             if (GMT_BOT(stat)) dev->sense[1] |= SENSE1_TAPE_LOADPT;
+#endif
             break;
 
         case TAPEDEVT_OMATAPE:
