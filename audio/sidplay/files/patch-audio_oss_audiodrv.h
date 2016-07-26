--- audio/oss/audiodrv.h.orig	2002-09-28 18:43:38 UTC
+++ audio/oss/audiodrv.h
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
