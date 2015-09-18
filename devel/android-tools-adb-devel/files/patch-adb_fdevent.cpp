--- adb/fdevent.cpp.orig	2015-09-17 22:58:36 UTC
+++ adb/fdevent.cpp
@@ -53,7 +53,7 @@ int SHELL_EXIT_NOTIFY_FD = -1;
 
 struct PollNode {
   fdevent* fde;
-  pollfd pollfd;
+  ::pollfd pollfd; // -fpermissive
 
   PollNode(fdevent* fde) : fde(fde) {
       memset(&pollfd, 0, sizeof(pollfd));
