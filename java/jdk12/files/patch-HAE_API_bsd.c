$FreeBSD$

--- ../../src/bsd/native/sun/audio/HAE_API_bsd.c	11 Sep 2001 05:01:58 -0000	1.7
+++ ../../src/bsd/native/sun/audio/HAE_API_bsd.c	20 Feb 2003 07:10:48 -0000
@@ -51,7 +51,7 @@
 #include <sys/wait.h>
 #include <errno.h>
 #ifdef __FreeBSD__
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #elif __OpenBSD__
 #include <soundcard.h>
 #endif
