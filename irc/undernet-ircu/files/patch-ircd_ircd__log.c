
$FreeBSD$

--- ircd/ircd_log.c.orig
+++ ircd/ircd_log.c
@@ -395,7 +395,7 @@
 
   /* Build the basic log string */
   vd.vd_format = fmt;
-  vd.vd_args = vl;
+  va_copy(vd.vd_args, vl);
 
   /* save the length for writev */
   /* Log format: "SYSTEM [SEVERITY]: log message" */
