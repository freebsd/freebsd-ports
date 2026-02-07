--- ./SpiralSound/Output.h.orig	Sun Dec  1 15:38:45 2002
+++ ./SpiralSound/Output.h	Sun Dec  1 15:40:05 2002
@@ -20,16 +20,12 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>
-#if defined (__FreeBSD__)
-	#include <machine/soundcard.h>
-#else
 #if defined (__NetBSD__) || defined (__OpenBSD__)
 	#include <soundcard.h>            /* OSS emulation */
 #undef ioctl
-#else 	                              /* BSDI, Linux, Solaris */
+#else 	                              /* FreeBSD, BSDI, Linux, Solaris */
 	#include <sys/soundcard.h>
 #endif                                /* __NetBSD__ or __OpenBSD__ */
-#endif                                /* __FreeBSD__ */
 #include <sys/ioctl.h>
 #include <limits.h>
 
