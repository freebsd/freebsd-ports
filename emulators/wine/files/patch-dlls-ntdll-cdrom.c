--- dlls/ntdll/cdrom.c	19 Feb 2003 22:08:50 -0000	1.25
+++ dlls/ntdll/cdrom.c	20 Feb 2003 09:30:31 -0000
@@ -72,6 +72,15 @@
 #include "file.h"
 #include "wine/debug.h"
 
+/* Non-Linux systems do not have linux/cdrom.h and the like, and thus
+   lack the following constants. */ 
+
+#ifndef CD_SECS  
+  #define CD_SECS              60 /* seconds per minute */
+#endif
+#ifndef CD_FRAMES
+  #define CD_FRAMES            75 /* frames per second */
+#endif
 
 static const struct iocodexs
 {
@@ -285,8 +294,10 @@ static int CDROM_SyncCache(int dev)
         + sizeof(TRACK_DATA) * (toc->LastTrack-toc->FirstTrack+2);
     toc->Length[0] = tsz >> 8;
     toc->Length[1] = tsz;
-   
+  
+#ifdef linux
     TRACE("caching toc from=%d to=%d\n", hdr.cdth_trk0, hdr.cdth_trk1);
+#endif
 
     for (i = toc->FirstTrack; i <= toc->LastTrack + 1; i++)
     {
@@ -1038,7 +1049,9 @@ static DWORD CDROM_SeekAudioMSF(int dev,
     if (i <= toc.FirstTrack || i > toc.LastTrack+1)
       return STATUS_INVALID_PARAMETER;
     i--;
-    cp->FormatCode = CDROM_MSF; 
+#ifdef CDROM_MSF
+    cp->FormatCode = CDROM_MSF;
+#endif
     cp->Control = toc.TrackData[i-toc.FirstTrack].Control; 
     cp->ADR = toc.TrackData[i-toc.FirstTrack].Adr; 
     cp->TrackNumber = toc.TrackData[i-toc.FirstTrack].TrackNumber;
