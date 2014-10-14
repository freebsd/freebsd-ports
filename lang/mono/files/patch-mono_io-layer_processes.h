
$FreeBSD$

pid_t is typedef'd in sys/types.h
Merged in #1341 upstream.

--- mono/io-layer/processes.h.orig
+++ mono/io-layer/processes.h
@@ -10,6 +10,8 @@
 #ifndef _WAPI_PROCESSES_H_
 #define _WAPI_PROCESSES_H_
 
+#include <sys/types.h>
+
 #include <glib.h>
 
 #include <mono/io-layer/handles.h>
