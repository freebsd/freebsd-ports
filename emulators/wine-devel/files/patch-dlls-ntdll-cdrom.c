--- dlls/ntdll/cdrom.c	19 Feb 2003 22:08:50 -0000	1.25
+++ dlls/ntdll/cdrom.c	20 Feb 2003 09:30:31 -0000
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
