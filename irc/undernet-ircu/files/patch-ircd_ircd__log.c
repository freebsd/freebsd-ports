
$FreeBSD$

--- ircd/ircd_log.c.orig
+++ ircd/ircd_log.c
@@ -49,6 +49,7 @@
 #include <syslog.h>
 #include <time.h>
 #include <unistd.h>
+#include <osreldate.h>
 
 #define LOG_BUFSIZE 2048 
 
@@ -395,7 +396,11 @@
 
   /* Build the basic log string */
   vd.vd_format = fmt;
+  #if __FreeBSD_version > 500000 && defined(__amd64__)
+  va_copy(vd.vd_args, vl);
+  #else
   vd.vd_args = vl;
+  #endif
 
   /* save the length for writev */
   /* Log format: "SYSTEM [SEVERITY]: log message" */
