
$FreeBSD$

--- src/Window/event.hpp.orig	Fri Jun 27 17:45:59 2003
+++ src/Window/event.hpp	Wed Aug 27 20:35:35 2003
@@ -12,12 +12,17 @@
 
 #ifndef EVENT_H
 #define EVENT_H
+
+#include <osreldate.h>
+
 #include "tree.hpp"
 #include "command.hpp"
 
+#if __FreeBSD_version < 500000
 #ifndef _TIME_T
 #define _TIME_T
 typedef long time_t;
+#endif
 #endif
 
 class window_rep;
