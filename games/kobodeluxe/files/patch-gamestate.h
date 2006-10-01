--- gamestate.h.orig	Sun Apr 28 05:48:59 2002
+++ gamestate.h	Sat Sep 30 23:58:17 2006
@@ -24,6 +24,8 @@
 
 #include "window.h"
 
+class gamestatemanager_t;
+
 class gamestate_t
 {
 	friend class gamestatemanager_t;
