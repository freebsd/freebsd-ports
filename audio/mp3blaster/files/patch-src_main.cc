
$FreeBSD$

--- src/main.cc.orig	Sun Jul 21 13:55:40 2002
+++ src/main.cc	Sun Jul 21 13:55:52 2002
@@ -3945,7 +3945,7 @@
 
 /* called when someone presses '/' in filemanager */
 void
-fw_start_search(int timeout=2)
+fw_start_search(int timeout)
 {
 	signal(SIGALRM, &fw_search_timeout);
 	fw_set_search_timeout(timeout);
