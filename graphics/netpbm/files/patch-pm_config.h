--- pm_config.h.orig	Sat Aug 10 01:19:45 2002
+++ pm_config.h	Sat Oct  5 00:00:00 2002
@@ -35,6 +35,10 @@
 typedef unsigned int uint32n;
 typedef signed int int32n;
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(USG) || defined(SVR4) || defined(VMS) || defined(__SVR4)
 #define SYSV
 #endif
@@ -44,7 +48,7 @@
 ** and if you run on an Amiga, set AMIGA. If your compiler is ANSI C, you're
 ** probably better off setting SYSV - all it affects is string handling.
 */
-#define BSD
+/* #define BSD */
 /* #define SYSV */
 /* #define MSDOS */
 /* #define AMIGA */
@@ -118,9 +122,9 @@
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
