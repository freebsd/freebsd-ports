--- tapecopy.c	Sat Feb  1 20:34:57 2003
+++ ../work/hercules-2.17.1/tapecopy.c	Mon Apr 28 21:21:15 2003
@@ -42,6 +42,7 @@
 static BYTE hdrlbl[] = "\xC8\xC4\xD9";  /* EBCDIC characters "HDR"   */
 static BYTE eoflbl[] = "\xC5\xD6\xC6";  /* EBCDIC characters "EOF"   */
 static BYTE eovlbl[] = "\xC5\xD6\xE5";  /* EBCDIC characters "EOV"   */
+#ifdef GNU_MTIO_SUPPORT
 static struct mt_tape_info tapeinfo[] = MT_TAPE_INFO;
 static struct mt_tape_info densinfo[] = {
     {0x01, "NRZI (800 bpi)"},
@@ -69,6 +70,7 @@
     {0x8C, "EXB-8505 compressed"},
     {0x90, "EXB-8205 compressed"},
     {0, NULL}};
+#endif
 static BYTE buf[65500];
 
 /*-------------------------------------------------------------------*/
@@ -76,6 +78,7 @@
 /*-------------------------------------------------------------------*/
 static void print_status (BYTE *devname, long stat)
 {
+#ifdef GNU_MTIO_SUPPORT
     printf ("HHCTC015I %s status: %8.8lX", devname, stat);
     if (GMT_EOF(stat)) printf (" EOF");
     if (GMT_BOT(stat)) printf (" BOT");
@@ -89,6 +92,7 @@
     if (GMT_D_800(stat)) printf (" 800");
     if (GMT_DR_OPEN(stat)) printf (" NOTAPE");
     printf ("\n");
+#endif
 
 } /* end function print_status */
 
@@ -109,10 +113,12 @@
         return -1;
     }
 
+#ifdef GNU_MTIO_SUPPORT
     print_status (devname, stblk.mt_gstat);
 
     if (GMT_EOD(stblk.mt_gstat)) return 1;
     if (GMT_EOT(stblk.mt_gstat)) return 1;
+#endif
 
     return 0;
 } /* end function print_status */
@@ -205,6 +211,7 @@
         exit (7);
     }
 
+#ifdef GNU_MTIO_SUPPORT
     /* Display tape status information */
     for (i = 0; tapeinfo[i].t_type != 0
                 && tapeinfo[i].t_type != stblk.mt_type; i++);
@@ -233,6 +240,7 @@
 
     /* Set the tape device to process variable length blocks */
     opblk.mt_op = MTSETBLK;
+#endif
     opblk.mt_count = 0;
     rc = ioctl (devfd, MTIOCTOP, (char*)&opblk);
     if (rc < 0)
