--- plugins/dfbinimage2/TrackParser.cpp.orig	2010-04-15 06:30:33.334174874 +0000
+++ plugins/dfbinimage2/TrackParser.cpp	2010-04-15 18:38:51.436143280 +0000
@@ -30,7 +30,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
-#include <linux/cdrom.h>
+#include <sys/cdio.h>
 
 using namespace std;
 
@@ -282,25 +282,25 @@
         Exception e(std::string("Cannot open device: ") + cuename);
         THROW(e);
     }
-    struct cdrom_tochdr tocHdr;
-    if(ioctl(theFd, CDROMREADTOCHDR, &tocHdr) < 0) {
+    struct ioc_toc_header tocHdr;
+    if(ioctl(theFd, CDIOREADTOCENTRY, &tocHdr) < 0) {
         close(theFd);
         Exception e(std::string("Cannot read TOC: ") + cuename);
         THROW(e);
     }
-    struct cdrom_tocentry tocEntry;
-    for(int i = tocHdr.cdth_trk0; i <= tocHdr.cdth_trk1; i++) {
+    struct ioc_read_toc_single_entry tocEntry;
+    for(int i = tocHdr.starting_track; i <= tocHdr.ending_track; i++) {
         memset(&tocEntry, 0, sizeof(tocEntry));
-        tocEntry.cdte_track = i;
-        tocEntry.cdte_format = CDROM_LBA;
-        if(ioctl(theFd, CDROMREADTOCENTRY, &tocEntry) < 0) {
+        tocEntry.track = i;
+        tocEntry.address_format = CD_LBA_FORMAT;
+        if(ioctl(theFd, CDIOREADTOCENTRY, &tocEntry) < 0) {
             close(theFd);
             Exception e(std::string("Cannot read TOC: ") + cuename);
             THROW(e);
         }
         TrackInfo thisTrack;
         thisTrack.trackNumber = i;
-        thisTrack.trackStart = CDTime(tocEntry.cdte_addr.lba, CDTime::abFrame);
+        thisTrack.trackStart = CDTime(tocEntry.entry.addr.lba, CDTime::abFrame);
         tiv.push_back(thisTrack);
     }
     close(theFd);
