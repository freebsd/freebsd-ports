Index: dlls/winmm/wineoss/audio.c
===================================================================
RCS file: /home/wine/wine/dlls/winmm/wineoss/audio.c,v
retrieving revision 1.108
diff -u -3 -p -r1.108 audio.c
--- dlls/winmm/wineoss/audio.c	12 Dec 2003 05:55:26 -0000	1.108
+++ dlls/winmm/wineoss/audio.c	28 Dec 2003 12:46:50 -0000
@@ -544,10 +544,15 @@ static BOOL OSS_WaveOutInit(OSS_DEVICE* 
                 strncpy(ossdev->out_caps.szPname, info.name, sizeof(info.name));
                 TRACE("%s\n", ossdev->ds_desc.szDesc);
             } else {
-                ERR("%s: can't read info!\n", ossdev->mixer_name);
+                ERR("%s: cannot read SOUND_MIXER_INFO!\n", ossdev->mixer_name);
+#ifndef __FreeBSD__
+                /* FreeBSD up to at least 5.2 provides this ioctl, but does
+                 * implement it properly, so ignore errors on that platform.
+                 */
                 OSS_CloseDevice(ossdev);
                 close(mixer);
                 return FALSE;
+#endif
             }
         } else {
             ERR("%s: %s\n", ossdev->mixer_name , strerror( errno ));
