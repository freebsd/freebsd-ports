Index: dlls/ntdll/cdrom.c
===================================================================
RCS file: /home/wine/wine/dlls/ntdll/cdrom.c,v
retrieving revision 1.38
diff -u -3 -p -r1.38 cdrom.c
--- cdrom.c	8 Oct 2003 02:59:22 -0000	1.38
+++ cdrom.c	31 Oct 2003 14:24:08 -0000
@@ -1350,10 +1350,8 @@ static NTSTATUS CDROM_RawRead(int dev, c
             return ret;
         }
     }
-#elif defined(__FreeBSD__)
+#else
     {
-        struct ioc_read_audio   ira;
-
         switch (raw->TrackMode)
         {
         case YellowMode2:
@@ -1363,33 +1361,12 @@ static NTSTATUS CDROM_RawRead(int dev, c
             FIXME("XAForm2: NIY\n");
             return ret;
         case CDDA:
-            /* 2048 = 2 ** 11 */
-            if (raw->DiskOffset.s.HighPart & ~2047) FIXME("Unsupported value\n");
-            ira.address.lba = ((raw->DiskOffset.s.LowPart >> 11) |
-                raw->DiskOffset.s.HighPart << (32 - 11)) - 1;
-            ira.address_format = CD_LBA_FORMAT;
-            ira.nframes = raw->SectorCount;
-            ira.buffer = buffer;
-            io = ioctl(cdrom_cache[dev].fd, CDIOCREADAUDIO, &ira);
-            break;
-        }
-    }
-#elif defined(__NetBSD__)
-    {
-        switch (raw->TrackMode)
-        {
-        case YellowMode2:
-            FIXME("YellowMode2: NIY\n");
-            return ret;
-        case XAForm2:
-            FIXME("XAForm2: NIY\n");
+            FIXME("CDDA: NIY\n");
             return ret;
-        case CDDA:
-	    FIXME("CDDA: NIY\n");
-	    return ret;
-	}
+        }
     }
 #endif
+
     *sz = sectSize * raw->SectorCount;
     ret = CDROM_GetStatusCode(io);
     return ret;
