--- iodev/cdrom.cc	Sat Dec 14 21:29:42 2002
+++ iodev/cdrom.cc	Fri Jan  3 13:21:31 2003
@@ -101,6 +101,8 @@
 #include <sys/cdio.h>
 #include <sys/ioctl.h>
 #include <sys/disklabel.h>
+// ntohl(x) et al have been moved out of sys/param.h in FreeBSD 5
+#include <netinet/in.h>
 
 // XXX
 #define BX_CD_FRAMESIZE 2048
@@ -881,7 +883,7 @@
     t.data_len = sizeof(tocentry);
     t.data = &tocentry;
 
-    if (ioctl (fd, CDIOREADTOCENTRYS, &tocentry) < 0)
+    if (ioctl (fd, CDIOREADTOCENTRYS, &t) < 0)
       BX_PANIC(("cdrom: read_toc: READTOCENTRY failed."));
 
     buf[len++] = 0; // Reserved
@@ -910,7 +912,7 @@
   t.data_len = sizeof(tocentry);
   t.data = &tocentry;
 
-  if (ioctl (fd, CDIOREADTOCENTRYS, &tocentry) < 0)
+  if (ioctl (fd, CDIOREADTOCENTRYS, &t) < 0)
     BX_PANIC(("cdrom: read_toc: READTOCENTRY lead-out failed."));
 
   buf[len++] = 0; // Reserved
@@ -1123,9 +1125,8 @@
   }
 #elif defined(__FreeBSD__)
   {
-  // Read the TOC to get the data size, since disklabel doesn't appear
-  // to work, sadly.
-  // Keith Jones, 16 January 2000
+  // Read the TOC to get the size of the data track.
+  // Keith Jones <freebsd.dev@blueyonder.co.uk>, 16 January 2000
 
 #define MAX_TRACKS 100
 
