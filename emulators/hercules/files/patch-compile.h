diff -ur ./cckddasd.c ../../work/hercules-2.17.1/cckddasd.c
--- ./cckddasd.c	Fri Jan 24 16:53:54 2003
+++ ../../work/hercules-2.17.1/cckddasd.c	Mon Apr 28 20:41:10 2003
@@ -2987,7 +2987,11 @@
     if (rc < hrc) hrc = rc;
 
     if (cckdblk.fsync)
+#if defined(__linux__)
         rc = fdatasync (cckd->fd[cckd->sfn]);
+#else
+	rc = fsync(cckd->fd[cckd->sfn]);
+#endif
 
     return hrc;
 } /* cckd_harden */
@@ -4268,7 +4272,11 @@
             {
                 obtain_lock (&cckd->filelock);
                 if (cckdblk.fsync)
+#if defined(__linux__)
                     rc = fdatasync (cckd->fd[cckd->sfn]);
+#else
+                    rc = fsync (cckd->fd[cckd->sfn]);
+#endif
                 cckd_flush_space (dev);
                 cckd_truncate (dev, 0);
                 release_lock (&cckd->filelock);
diff -ur ./ctc_ctci.c ../../work/hercules-2.17.1/ctc_ctci.c
--- ./ctc_ctci.c	Sat Feb  1 20:34:57 2003
+++ ../../work/hercules-2.17.1/ctc_ctci.c	Mon Apr 28 20:38:32 2003
@@ -9,7 +9,7 @@
 // linux 2.4 modifications (c) Copyright Fritz Elfert, 2001-2003
 //
 
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 
 #include "hercules.h"
 #include "devtype.h"
@@ -1302,4 +1302,4 @@
 
     return 0;
 }
-#endif /* !defined(__APPLE__) */
+#endif /* !defined(__APPLE__) && !defined(__FreeBSD__) */
diff -ur ./ctc_lcs.c ../../work/hercules-2.17.1/ctc_lcs.c
--- ./ctc_lcs.c	Sat Feb  1 20:34:57 2003
+++ ../../work/hercules-2.17.1/ctc_lcs.c	Mon Apr 28 20:38:00 2003
@@ -5,7 +5,7 @@
 // Copyright (C) 2002-2003 by James A. Pierson
 //
 
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 
 #include "hercules.h"
 #include "devtype.h"
@@ -1976,4 +1983,4 @@
 
     return pszBuff;
 }
-#endif /* !defined(__APPLE__) */
+#endif /* !defined(__APPLE__) && !defined(__FreeBSD__) */
diff -ur ./ctcadpt.c ../../work/hercules-2.17.1/ctcadpt.c
--- ./ctcadpt.c	Sat Feb  1 20:34:57 2003
+++ ../../work/hercules-2.17.1/ctcadpt.c	Mon Apr 28 20:39:09 2003
@@ -17,7 +17,7 @@
 //
 //   Please read README.NETWORKING for more info.
 //
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 
 #include "hercules.h"
 #include "devtype.h"
@@ -1561,4 +1561,4 @@
         logmsg( " %s\n", print_chars );
     }
 }
-#endif /* !defined(__APPLE__) */
+#endif /* !defined(__APPLE__) && !defined(__FreeBSD__) */
diff -ur ./ctcadpt.h ../../work/hercules-2.17.1/ctcadpt.h
--- ./ctcadpt.h	Mon Jan 20 04:23:51 2003
+++ ../../work/hercules-2.17.1/ctcadpt.h	Mon Apr 28 20:24:47 2003
@@ -93,7 +93,9 @@
 #define FRAME_TYPE_IP   0x0800
 #define FRAME_TYPE_ARP  0x0806
 #define FRAME_TYPE_SNA  0x80D5
-
+#ifndef IFHWADDRLEN
+#define IFHWADDRLEN	6
+#endif
 typedef uint8_t MAC[IFHWADDRLEN];       // Data Type for MAC Addresses
 
 // ---------------------------------------------------------------------
diff -ur ./devtype.c ../../work/hercules-2.17.1/devtype.c
--- ./devtype.c	Sat Feb  1 20:34:57 2003
+++ ../../work/hercules-2.17.1/devtype.c	Mon Apr 28 20:39:35 2003
@@ -51,13 +51,13 @@
     { "3270", 0x3270, &loc3270_device_hndinfo },
     { "3287", 0x3287, &loc3270_device_hndinfo },
 
-#   if !defined(__APPLE__)
+#   if !defined(__APPLE__) && !defined(__FreeBSD__)
     /* Communications devices */
     { "3088",  0x3088, &ctcadpt_device_hndinfo },
     { "CTCI",  0x3088, &ctcadpt_device_hndinfo },
     { "CTCT",  0x3088, &ctcadpt_device_hndinfo },
     { "LCS",   0x3088, &ctcadpt_device_hndinfo },
     { "VMNET", 0x3088, &ctcadpt_device_hndinfo },
-#   endif /* !defined(__APPLE__) */
+#   endif /* !defined(__APPLE__) && !defined(__FreeBSD__) */
 
     { NULL, 0, NULL } };
diff -ur ./tapedev.c ../../work/hercules-2.17.1/tapedev.c
--- ./tapedev.c	Sat Feb  1 20:34:57 2003
+++ ../../work/hercules-2.17.1/tapedev.c	Mon Apr 28 20:37:20 2003
@@ -2,6 +2,9 @@
 /* JCS - minor changes by John Summerfield                           */
 /*              ESA/390 Tape Device Handler                          */
 
+#if defined(__FreeBSD__)
+#define __APPLE__
+#endif
 /*-------------------------------------------------------------------*/
 /* This module contains device handling functions for emulated       */
 /* 3420 magnetic tape devices for the Hercules ESA/390 emulator.     */
diff -ur ./tuntap.c ../../work/hercules-2.17.1/tuntap.c
--- ./tuntap.c	Sat Feb  1 20:34:57 2003
+++ ../../work/hercules-2.17.1/tuntap.c	Mon Apr 28 20:35:31 2003
@@ -14,13 +14,13 @@
 // This abstraction layer is an attempt to create a common API set
 // that works on all platforms with (hopefully) equal results.
 
-#if !defined(__APPLE__) 
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include "hercules.h"
 #include "tuntap.h"
 #include "devtype.h"
 #include "ctcadpt.h"
 #include "hercifc.h"
 
 #if defined( WIN32 )
 #include "w32ctca.h"
 #endif
@@ -609,4 +610,4 @@
 }
 
 #endif // !defined( WIN32 )
-#endif /* !defined(__APPLE__) */
+#endif /* !defined(__APPLE__) && !defined(__FreeBSD__) */
