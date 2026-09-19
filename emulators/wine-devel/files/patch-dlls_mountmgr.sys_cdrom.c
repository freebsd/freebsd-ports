--- dlls/mountmgr.sys/cdrom.c.orig	2026-09-18 20:36:23 UTC
+++ dlls/mountmgr.sys/cdrom.c
@@ -340,7 +340,7 @@ static NTSTATUS seek_audio_msf( struct cdrom *cdrom, c
         msf.start_s = params->S;
         msf.start_f = params->F;
         final_frame = track_to_frame( &cdrom->toc, cdrom->toc.LastTrack + 1 ) - 1;
-        frame_to_msf( msf.end_m, final_frame );
+        frame_to_msf( &msf.end_m, final_frame );
         if (ioctl( cdrom->fd, CDIOCPLAYMSF, &msf ) < 0)
             return errno_to_status( errno );
     }
@@ -392,14 +392,14 @@ static NTSTATUS play_audio_msf( struct cdrom *cdrom, c
         WARN( "failed to start: %s\n", strerror( errno ));
         return errno_to_status( errno );
     }
-    if (ioctl( cdrom->fd, CDROMPLAYMSF, &msf ) == -1)
+    if (ioctl( cdrom->fd, CDIOCPLAYMSF, &msf ) == -1)
     {
         WARN( "failed to play: %s\n", strerror( errno ));
         return errno_to_status( errno );
     }
     TRACE( "playing %d:%d:%d to %d:%d:%d\n",
-            msf.cdmsf_min0, msf.cdmsf_sec0, msf.cdmsf_frame0,
-            msf.cdmsf_min1, msf.cdmsf_sec1, msf.cdmsf_frame1 );
+            msf.start_m, msf.start_s, msf.start_f,
+            msf.end_m, msf.end_s, msf.end_f );
     return STATUS_SUCCESS;
 #else
     FIXME( "not implemented for this platform\n" );
