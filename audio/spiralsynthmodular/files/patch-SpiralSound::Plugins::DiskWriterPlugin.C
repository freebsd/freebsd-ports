--- SpiralSound/Plugins/DiskWriterPlugin/DiskWriterPlugin.C.orig	Tue Jan  7 01:20:23 2003
+++ SpiralSound/Plugins/DiskWriterPlugin/DiskWriterPlugin.C	Tue Jan  7 01:21:15 2003
@@ -20,6 +20,7 @@
 #define	_ISOC9X_SOURCE	1
 #define _ISOC99_SOURCE	1
 #include  <math.h>
+#define lrintf(flt)             ((int) (flt))
 
 #include <sys/types.h>
 #include <stdio.h>
