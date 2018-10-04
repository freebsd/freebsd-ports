--- cava.c.orig	2018-10-04 05:51:51 UTC
+++ cava.c
@@ -341,8 +341,12 @@ as of 0.4.0 all options are specified in config file, 
 			 "/dev/console") == 0) inAtty = 1;
 
 		if (inAtty) {
+#ifdef __FreeBSD__
+			system("/usr/sbin/vidcontrol -f " FONT_DIR "/cava.fnt >/dev/null 2>&1");
+#else
 			system("setfont cava.psf  >/dev/null 2>&1");
 			system("setterm -blank 0");
+#endif
 		}
 	}
 
