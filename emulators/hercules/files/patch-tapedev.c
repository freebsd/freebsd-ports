--- tapedev.c.orig	Tue Nov 20 23:39:47 2001
+++ tapedev.c	Thu Jan 31 13:06:43 2002
@@ -131,6 +131,11 @@
 #define TAPEDEVT_SCSITAPE       3       /* Physical SCSI tape        */
 #define TAPEDEVT_HET            4       /* HET format disk file      */
 
+/* Can you say totally b0rken? */
+#define MT_ST_DENSITY_MASK	1
+#define MT_TAPE_INFO		2
+#define MTSETBLK		3
+#define MT_ST_DENSITY_SHIFT	4
 /*-------------------------------------------------------------------*/
 /* Structure definition for tape block headers                       */
 /*-------------------------------------------------------------------*/
@@ -194,7 +199,10 @@
 /*-------------------------------------------------------------------*/
 /* Static data areas                                                 */
 /*-------------------------------------------------------------------*/
-static struct mt_tape_info tapeinfo[] = MT_TAPE_INFO;
+
+
+/* static struct mt_tape_info tapeinfo[] = MT_TAPE_INFO; 
+
 static struct mt_tape_info densinfo[] = {
     {0x01, "NRZI (800 bpi)"},
     {0x02, "PE (1600 bpi)"},
@@ -221,7 +229,7 @@
     {0x8C, "EXB-8505 compressed"},
     {0x90, "EXB-8205 compressed"},
     {0, NULL}};
-
+*/
 static PARSER ptab[] =
 {
     { "awstape", NULL }, 
@@ -1151,6 +1159,7 @@
     if (dev->fd < 0) return 0;
 
     /* Obtain tape status */
+/*
     rc = ioctl (dev->fd, MTIOCGET, (char*)&stblk);
     if (rc < 0)
     {
@@ -1159,8 +1168,9 @@
         return 0;
     }
     stat = stblk.mt_gstat;
-
+*/
     /* Display tape status */
+/*
     if (dev->ccwtrace || dev->ccwstep)
     {
         sprintf (buf, "%s status: %8.8X", dev->filename, stat);
@@ -1177,10 +1187,11 @@
         if (GMT_DR_OPEN(stat)) strcat (buf, " NOTAPE");
         logmsg ("HHC215I %s\n", buf);
     }
-
+*/
     /* If tape has been ejected, then close the file because
        the driver will not recognize that a new tape volume
        has been mounted until the file is re-opened */
+/*
     if (GMT_DR_OPEN(stat))
     {
         close (dev->fd);
@@ -1190,8 +1201,10 @@
         dev->prvblkpos = -1;
         dev->blockid = 0;
     }
-
+*/
     /* Return tape status */
+
+	fprintf(stderr,"Sorry, tape support is broken.\n");
     return stat;
 
 } /* end function status_scsitape */
@@ -1249,6 +1262,7 @@
     }
 
     /* Intervention required if no tape is mounted */
+/*
     if (GMT_DR_OPEN(stblk.mt_gstat))
     {
         dev->sense[0] = SENSE_IR;
@@ -1256,8 +1270,9 @@
         *unitstat = CSW_CE | CSW_DE | CSW_UC;
         return -1;
     }
-
+*/
     /* Display tape status information */
+/*
     for (i = 0; tapeinfo[i].t_type != 0
                 && tapeinfo[i].t_type != stblk.mt_type; i++);
 
@@ -1280,8 +1295,9 @@
     else
         logmsg ("HHC221I %s tape density code: 0x%lX\n",
                 dev->filename, density);
-
+*/
     /* Set the tape device to process variable length blocks */
+ /*
     opblk.mt_op = MTSETBLK;
     opblk.mt_count = 0;
     rc = ioctl (dev->fd, MTIOCTOP, (char*)&opblk);
@@ -1294,8 +1310,9 @@
         *unitstat = CSW_CE | CSW_DE | CSW_UC;
         return -1;
     }
-
+*/
     /* Rewind the tape to the beginning */
+/* 
     opblk.mt_op = MTREW;
     opblk.mt_count = 1;
     rc = ioctl (dev->fd, MTIOCTOP, (char*)&opblk);
@@ -1308,7 +1325,7 @@
         *unitstat = CSW_CE | CSW_DE | CSW_UC;
         return -1;
     }
-
+*/
     return 0;
 
 } /* end function open_scsitape */
@@ -1436,13 +1453,14 @@
 
     /* If I/O error and status indicates EOF, then a tapemark
        was detected, so increment the file number and return 0 */
+/*
     if (rc < 0 && fsrerrno == EIO && GMT_EOF(stat))
     {
         dev->curfilen++;
         dev->blockid++;
         return 0;
     }
-
+*/
     /* Handle MTFSR error condition */
     if (rc < 0)
     {
@@ -1481,6 +1499,7 @@
     stat = status_scsitape (dev);
 
     /* Unit check if already at start of tape */
+/*
     if (GMT_BOT(stat))
     {
         dev->sense[0] = 0;
@@ -1488,7 +1507,7 @@
         *unitstat = CSW_CE | CSW_DE | CSW_UC;
         return -1;
     }
-
+*/
     /* Backspace block on SCSI tape */
     opblk.mt_op = MTBSR;
     opblk.mt_count = 1;
@@ -2703,12 +2722,15 @@
 U32             stat;                   /* SCSI tape status bits     */
 
     /* Indicate intervention required if no file */
+/*
     if (!strcmp (dev->filename, TAPE_UNLOADED))
 	dev->sense[0] |= SENSE_IR;
 
     if (!(dev->fd < 0))
     {
+    */
         /* Set load point indicator if tape is at load point */
+/*
         dev->sense[1] &= ~SENSE1_TAPE_LOADPT;
         switch (dev->tapedevt)
         {
@@ -2732,41 +2754,14 @@
             if (dev->nxtblkpos == 0 && dev->curfilen == 1)
                 dev->sense[1] |= SENSE1_TAPE_LOADPT;
             break;
-        } /* end switch(dev->tapedevt) */
-    } /* !(fd < 0) */
+        } 
+	*/
+	/* end switch(dev->tapedevt) */
+    
 
     /* Indicate Drive online to control unit */
-    dev->sense[1] |= SENSE1_TAPE_TUA;
 
-    /* Set file protect indicator if read-only file */
-    if (dev->readonly)
-        dev->sense[1] |= SENSE1_TAPE_FP;
-    else
-        dev->sense[1] &= ~SENSE1_TAPE_FP;
 
-    /* Set Error Recovery Action Code */
-    if (dev->sense[0] & SENSE_IR)
-        dev->sense[3] = 0x43;
-    else if (dev->sense[0] & SENSE_CR)
-        dev->sense[3] = 0x27;
-    else if (dev->sense[1] & SENSE1_TAPE_FP)
-        dev->sense[3] = 0x30;
-    else
-        dev->sense[3] = 0x29;
-
-    /* Set sense bytes for 3420 */
-    if (dev->devtype != 0x3480)
-    {
-//      dev->sense[4] |= 0x20;
-        dev->sense[5] |= 0xC0;
-        dev->sense[6] |= 0x03;
-        dev->sense[13] = 0x80;
-        dev->sense[14] = 0x01;
-        dev->sense[15] = 0x00;
-        dev->sense[16] = 0x01;
-        dev->sense[19] = 0xFF;
-        dev->sense[20] = 0xFF;
-    }
 
 } /* end function build_sense */
 
