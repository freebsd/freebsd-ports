--- Wnn/jlib/jl.c.orig	2007-11-11 17:47:05.000000000 +0900
+++ Wnn/jlib/jl.c	2007-11-11 17:47:24.000000000 +0900
@@ -143,6 +143,8 @@
 #include "commonhd.h"
 #include "config.h"
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #ifdef SYSVR2
 #   include <string.h>
@@ -734,7 +736,7 @@
 	js_close(js_id);
 }
 
-static void
+void
 jl_disconnect_if_server_dead_body_by_jsid(jsid)
 register WNN_JSERVER_ID	*jsid;
 {
