--- ical.h.orig	1996-02-10 04:17:36.000000000 +0100
+++ ical.h	2003-04-28 18:14:32.000000000 +0200
@@ -4,6 +4,11 @@
 
 #include <tcl.h>
 
+// That was introduced in tcl8.4
+#ifndef CONST84
+#define CONST84
+#endif
+
 // Proc for triggering tcl code based on changes
 // to calendars/items.
 
