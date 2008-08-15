
$FreeBSD$

--- ggadget/qt/utilities.cc.orig
+++ ggadget/qt/utilities.cc
@@ -111,7 +111,7 @@
     if (fork() != 0)
       _exit(0);
 
-    execl(xdg_open.c_str(), xdg_open.c_str(), url, NULL);
+    execl(xdg_open.c_str(), xdg_open.c_str(), url, (const char*)0);
 
     DLOG("Failed to exec command: %s", xdg_open.c_str());
     _exit(-1);
