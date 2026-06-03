--- libfoundry/foundry-init.c.orig	2025-10-28 23:23:12 UTC
+++ libfoundry/foundry-init.c
@@ -23,7 +23,6 @@
 #include <glib/gi18n-lib.h>
 #include <libdex.h>
 #include <libpeas.h>
-#include <sysprof-capture.h>
 
 #include <json-glib/json-glib.h>
 
@@ -188,9 +187,4 @@ foundry_trace_function (const gchar *func,
                         gint64       begin_time_usec,
                         gint64       end_time_usec)
 {
-  sysprof_collector_mark (begin_time_usec * 1000L,
-                          (end_time_usec - begin_time_usec) * 1000L,
-                          "tracing",
-                          "call",
-                          func);
 }
