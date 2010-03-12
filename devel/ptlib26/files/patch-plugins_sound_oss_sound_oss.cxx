--- plugins/sound_oss/sound_oss.cxx.orig	2009-09-20 20:25:31.000000000 -0400
+++ plugins/sound_oss/sound_oss.cxx	2010-01-27 16:15:09.000000000 -0500
@@ -175,11 +175,11 @@
             if (dsp.GetAt(cardnum+1) == NULL) {
 #if defined (P_FREEBSD)
               // in FreeBSD the file name should be used via the devfs(5) and
-              // is just "/dev/dsp0" and devfs(5) takes care of virtual channels,
-              // like /dev/dsp0.0 /dev/dsp0.1 ...
+              // is just "/dev/dspN" and devfs(5) takes care of virtual channels,
+              // like /dev/dspN.0 /dev/dspN.1 ...
               // everything else would conflict with other KDE apps using the
               // audio
-              devname = devdir + "dsp0";
+              devname = devdir + "dsp" + PString(cardnum);
               PTRACE(1, "OSS\tCollectSoundDevices FreeBSD devname set to devfs(5) name:" << devname );
 #endif /* defined (P_FREEBSD) */
               dsp.SetAt(cardnum+1, devname);
