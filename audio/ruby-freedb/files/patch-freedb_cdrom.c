--- freedb_cdrom.c.orig	Wed Sep 25 15:05:37 2002
+++ freedb_cdrom.c	Sun Oct 13 03:13:25 2002
@@ -93,17 +93,18 @@
 
 
   char offsets[1089] = "", buff[255];
-	
-  Check_Type(device, T_STRING);
-  drive = open(STR2CSTR(device), O_RDONLY | O_NONBLOCK);
+
+  Check_SafeStr(device);
+  drive = open(RSTRING(device)->ptr, O_RDONLY | O_NONBLOCK);
 
   if (drive < 0) {
-    close(drive);
-    rb_sys_fail("Failed to open device");
+    rb_sys_fail(RSTRING(device)->ptr);
   }
 
-  if (ioctl(drive,CDROMREADTOCHDR,&hdr) < 0)
-    rb_sys_fail("Failed to read TOC");
+  if (ioctl(drive,CDROMREADTOCHDR,&hdr) < 0) {
+    close(drive);
+    rb_sys_fail("Failed to read TOC entry");
+  }
 
   first=hdr.cdth_trk0;
   last=hdr.cdth_trk1;
@@ -126,6 +127,7 @@
   t.data = TocEntry;
 
   if (ioctl(drive, CDIOREADTOCENTRYS, (char *) &t) < 0)
+    free(TocEntry);
     close(drive);
     rb_sys_fail("Failed to read TOC entry");
   }
@@ -157,9 +159,11 @@
   TocEntry[last].cdte_format = CDROM_LBA;
   if (ioctl(drive, CDROMREADTOCENTRY, &TocEntry[i]) < 0) {
     free(TocEntry);
+    close(drive);
     rb_sys_fail("Failed to read TOC entry");
   }
 #endif
+  close(drive);
 
 #if defined(OS_FREEBSD)
   TocEntry[i].cdte_addr.lba = ntohl(TocEntry[i].cdte_addr.lba);
