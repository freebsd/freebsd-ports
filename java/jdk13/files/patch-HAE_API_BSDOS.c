$FreeBSD: /tmp/pcvs/ports/java/jdk13/files/Attic/patch-HAE_API_BSDOS.c,v 1.1 2002-06-05 21:43:14 kris Exp $

--- ../src/solaris/native/com/sun/media/sound/engine/HAE_API_BSDOS.c	Thu Apr 11 14:58:48 2002
+++ ../src/solaris/native/com/sun/media/sound/engine/HAE_API_BSDOS.c	Thu Apr 11 15:14:18 2002
@@ -58,7 +58,11 @@
 #include <sys/wait.h>
 #include <errno.h>
 #ifdef __FreeBSD__
+#if __FreeBSD__ > 3
+#include <sys/soundcard.h>
+#else
 #include <machine/soundcard.h>
+#endif
 #endif
 #ifdef __NetBSD__
 #include <soundcard.h>
