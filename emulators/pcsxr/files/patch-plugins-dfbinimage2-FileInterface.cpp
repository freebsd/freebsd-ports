--- plugins/dfbinimage2/FileInterface.cpp.orig	2008-08-24 14:27:09.000000000 +0000
+++ plugins/dfbinimage2/FileInterface.cpp	2010-04-22 06:01:39.002592019 +0000
@@ -35,7 +35,9 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
-#include <linux/cdrom.h>
+#include <sys/cdio.h>
+
+#define CDROM_LEADOUT  0xAA
 
 extern Preferences prefs;
 
@@ -462,15 +464,15 @@
         THROW(e);
     }
     fileName = str;
-    struct cdrom_tocentry tocEntry;
+    struct ioc_read_toc_single_entry tocEntry;
     memset(&tocEntry, 0, sizeof(tocEntry));
-    tocEntry.cdte_track = CDROM_LEADOUT;
-    tocEntry.cdte_format = CDROM_LBA;
-    if(ioctl(theFd, CDROMREADTOCENTRY, &tocEntry) < 0) {
+    tocEntry.track = CDROM_LEADOUT;
+    tocEntry.address_format = CD_LBA_FORMAT;
+    if(ioctl(theFd, CDIOREADTOCENTRY, &tocEntry) < 0) {
         Exception e(std::string("Cannot read TOC: ") + str);
         THROW(e);
     }
-    CDLength = CDTime(tocEntry.cdte_addr.lba, CDTime::abFrame) + CDTime(0,2,0);
+    CDLength = CDTime(tocEntry.entry.addr.lba, CDTime::abFrame) + CDTime(0,2,0);
     bufferPos.setMSF(MSFTime(255,255,255));
 }
 
@@ -482,9 +484,16 @@
     char *buf = (char*)fileBuffer;
     int cnt;
     for(cnt = 0; cnt < bufferFrames; cnt++) {
-        memcpy(buf, seekTime.getMSFbuf(), 3);
-        if(ioctl(theFd, CDROMREADRAW, buf)<0)
-            break;
+        if (lseek(theFd,
+                  seekTime.getMSF().m() * bytesPerMinute +
+                  seekTime.getMSF().s() * bytesPerSecond +
+                  seekTime.getMSF().f() * bytesPerFrame,
+                  SEEK_SET) == -1) {
+          return;
+        }
+        if (read(theFd, buf, bytesPerFrame) == -1) {
+          return;
+        }
         buf += bytesPerFrame;
         seekTime += CDTime(0,0,1);
     }
