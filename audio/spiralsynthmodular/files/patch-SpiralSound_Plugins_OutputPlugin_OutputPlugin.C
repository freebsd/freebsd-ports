--- SpiralSound/Plugins/OutputPlugin/OutputPlugin.C.orig	2004-02-08 18:36:17 UTC
+++ SpiralSound/Plugins/OutputPlugin/OutputPlugin.C
@@ -20,6 +20,7 @@
 #define	_ISOC9X_SOURCE	1
 #define _ISOC99_SOURCE	1
 #include  <math.h>
+#define lrintf(flt)             ((int) (flt))
 
 #include <sys/types.h>
 #include <stdio.h>
@@ -27,7 +28,7 @@
 #include <unistd.h>
 #include <limits.h>
 #if defined (__FreeBSD__)
-	#include <machine/soundcard.h>
+	#include <sys/soundcard.h>
 #else
 #if defined (__NetBSD__) || defined (__OpenBSD__)
 	#include <soundcard.h>            /* OSS emulation */
