--- soundcard/macro_to_function.c.orig	Mon Mar 21 05:18:34 2005
+++ soundcard/macro_to_function.c	Tue Mar 22 00:28:40 2005
@@ -24,7 +24,9 @@
 #include <unistd.h>
 #include <sys/ioctl.h>
 
+#ifdef HAVE_LINUX_AWE_VOICE_H
 #include <linux/awe_voice.h>
+#endif
 
 extern int _seqbufptr;
 extern int _seqbuflen;
