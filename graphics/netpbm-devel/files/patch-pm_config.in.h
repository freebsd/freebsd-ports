--- pm_config.in.h.orig	Sat Jul 24 04:40:06 2004
+++ pm_config.in.h	Tue Aug 17 16:53:30 2004
@@ -15,6 +15,10 @@
 
 **************************************************************************/
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(USG) || defined(SVR4) || defined(VMS) || defined(__SVR4)
 #define SYSV
 #endif
@@ -99,9 +103,9 @@
 #define RGB_DB2 "PBMplus_Dir:RGB.TXT"
 #define RGB_DB3 "PBMplus_Dir:RGB.TXT"
 #else
-#define RGB_DB1 "/usr/lib/X11/rgb.txt"
-#define RGB_DB2 "/usr/openwin/lib/rgb.txt"
-#define RGB_DB3 "/usr/X11R6/lib/X11/rgb.txt"
+#define RGB_DB1 "%%PREFIX%%/share/netpbm/rgb.txt"
+#define RGB_DB2 "%%LOCALBASE%%/share/netpbm/rgb.txt"
+#define RGB_DB3 "%%X11BASE%%/lib/X11/rgb.txt"
 #endif
 
 /* CONFIGURE: This is the name of an environment variable that tells
