--- tapecopy.c.orig	Mon Sep  2 11:00:59 2002
+++ tapecopy.c	Mon Sep  2 11:03:21 2002
@@ -32,6 +32,7 @@
 static BYTE hdrlbl[] = "\xC8\xC4\xD9";  /* EBCDIC characters "HDR"   */
 static BYTE eoflbl[] = "\xC5\xD6\xC6";  /* EBCDIC characters "EOF"   */
 static BYTE eovlbl[] = "\xC5\xD6\xE5";  /* EBCDIC characters "EOV"   */
+#ifdef GNU_MTIO_SUPPORT
 static struct mt_tape_info tapeinfo[] = MT_TAPE_INFO;
 static struct mt_tape_info densinfo[] = {
     {0x01, "NRZI (800 bpi)"},
@@ -59,6 +60,7 @@
     {0x8C, "EXB-8505 compressed"},
     {0x90, "EXB-8205 compressed"},
     {0, NULL}};
+#endif
 static BYTE buf[65500];
 
 /*-------------------------------------------------------------------*/
@@ -71,6 +73,7 @@
 /*-------------------------------------------------------------------*/
 static void print_status (BYTE *devname, long stat)
 {
+#ifdef GNU_MTIO_SUPPORT
     printf ("%s status: %8.8lX", devname, stat);
     if (GMT_EOF(stat)) printf (" EOF");
     if (GMT_BOT(stat)) printf (" BOT");
@@ -84,6 +87,7 @@
     if (GMT_D_800(stat)) printf (" 800");
     if (GMT_DR_OPEN(stat)) printf (" NOTAPE");
     printf ("\n");
+#endif
 
 } /* end function print_status */
 
@@ -104,10 +108,12 @@
         return -1;
     }
 
+#ifdef GNU_MTIO_SUPPORT
     print_status (devname, stblk.mt_gstat);
 
     if (GMT_EOD(stblk.mt_gstat)) return 1;
     if (GMT_EOT(stblk.mt_gstat)) return 1;
+#endif
 
     return 0;
 } /* end function print_status */
@@ -188,6 +194,7 @@
         exit (7);
     }
 
+#ifdef GNU_MTIO_SUPPORT
     /* Display tape status information */
     for (i = 0; tapeinfo[i].t_type != 0
                 && tapeinfo[i].t_type != stblk.mt_type; i++);
@@ -215,6 +222,7 @@
 
     /* Set the tape device to process variable length blocks */
     opblk.mt_op = MTSETBLK;
+#endif
     opblk.mt_count = 0;
     rc = ioctl (devfd, MTIOCTOP, (char*)&opblk);
     if (rc < 0)
