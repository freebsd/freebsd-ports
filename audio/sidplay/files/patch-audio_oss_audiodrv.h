
$FreeBSD$

--- audio/oss/audiodrv.h.orig	Sun Apr 11 06:00:00 1999
+++ audio/oss/audiodrv.h	Tue Jul 30 14:12:10 2002
@@ -16,8 +16,8 @@
 
 #if defined(HAVE_LINUX) && defined(HAVE_LINUX_SOUNDCARD_H)
   #include <linux/soundcard.h>
-#elif defined(HAVE_FREEBSD) && defined(HAVE_MACHINE_SOUNDCARD_H)
-  #include <machine/soundcard.h>
+#elif defined(HAVE_FREEBSD) && defined(HAVE_SYS_SOUNDCARD_H)
+  #include <sys/soundcard.h>
 #elif defined(HAVE_NETBSD) && defined(HAVE_SOUNDCARD_H)
   #include <soundcard.h>
 #else
