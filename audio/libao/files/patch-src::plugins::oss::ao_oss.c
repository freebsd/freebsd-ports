
$FreeBSD$

--- src/plugins/oss/ao_oss.c.orig	Wed Apr 10 21:56:57 2002
+++ src/plugins/oss/ao_oss.c	Wed Apr 10 21:57:11 2002
@@ -32,8 +32,6 @@
 #include <math.h>
 #if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <soundcard.h>
-#elif defined(__FreeBSD__)
-#include <machine/soundcard.h>
 #else
 #include <sys/soundcard.h>
 #endif
