--- pm_config.in.h.orig	2006-10-18 20:29:13.000000000 +0200
+++ pm_config.in.h	2010-05-21 10:37:50.000000000 +0200
@@ -15,6 +15,10 @@
 
 **************************************************************************/
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(USG) || defined(SVR4) || defined(VMS) || defined(__SVR4)
 #define SYSV
 #endif
@@ -67,9 +71,9 @@
 #define RGB_DB2 "PBMplus_Dir:RGB.TXT"
 #define RGB_DB3 "PBMplus_Dir:RGB.TXT"
 #else
-#define RGB_DB1 "/usr/lib/X11/rgb.txt"
-#define RGB_DB2 "/usr/share/X11/rgb.txt"
-#define RGB_DB3 "/usr/X11R6/lib/X11/rgb.txt"
+#define RGB_DB1 "%%PREFIX%%/share/netpbm/rgb.txt"
+#define RGB_DB2 "%%LOCALBASE%%/share/netpbm/rgb.txt"
+#define RGB_DB3 "%%LOCALBASE%%/lib/X11/rgb.txt"
 #endif
 
 /* CONFIGURE: This is the name of an environment variable that tells
