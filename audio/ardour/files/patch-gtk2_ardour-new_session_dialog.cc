--- gtk2_ardour/new_session_dialog.cc.orig	2008-01-14 10:04:17.000000000 +0100
+++ gtk2_ardour/new_session_dialog.cc	2008-01-14 10:04:44.000000000 +0100
@@ -556,7 +556,7 @@
 	*/
 
 
-#ifdef __APPLE__
+#ifndef __Linux__
 
 	char buf[PATH_MAX];
 
