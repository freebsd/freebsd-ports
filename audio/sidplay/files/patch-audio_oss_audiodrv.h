--- audio/oss/audiodrv.h.org	Tue Jan 21 19:51:13 2003
+++ audio/oss/audiodrv.h	Tue Jan 21 19:51:50 2003
@@ -16,8 +16,8 @@
 
 #if defined(HAVE_LINUX) && defined(HAVE_LINUX_SOUNDCARD_H)
   #include <linux/soundcard.h>
-#elif defined(HAVE_FREEBSD) && defined(HAVE_MACHINE_SOUNDCARD_H)
-  #include <machine/soundcard.h>
+#elif defined(HAVE_FREEBSD) && defined(HAVE_SYS_SOUNDCARD_H)
+  #include <sys/soundcard.h>
 #elif defined(HAVE_OPENBSD) && defined(HAVE_SOUNDCARD_H)
   #include <soundcard.h>
 #elif defined(HAVE_NETBSD) && defined(HAVE_SOUNDCARD_H)
