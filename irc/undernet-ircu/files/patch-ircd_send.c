
$FreeBSD$

--- ircd/send.c.orig
+++ ircd/send.c
@@ -44,7 +44,7 @@
 #include <assert.h>
 #include <stdio.h>
 #include <string.h>
-
+#include <osreldate.h>
 
 static int sentalong[MAXCONNECTIONS];
 static int sentalong_marker;
@@ -697,7 +697,11 @@
    * this is ok...
    */
   vd.vd_format = pattern;
+  #if __FreeBSD_version > 500000 && defined(__amd64__)
+  va_copy(vd.vd_args, vl);
+  #else
   vd.vd_args = vl;
+  #endif
   mb = msgq_make(0, ":%s " MSG_NOTICE " * :*** Notice -- %v", cli_name(&me),
 		 &vd);
 
