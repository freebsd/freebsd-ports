--- ./src/Window/event.hpp.orig	Sun Oct  3 13:26:38 2004
+++ ./src/Window/event.hpp	Sat Oct 23 17:39:48 2004
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
