
$FreeBSD$

--- ggadget/gtk/utilities.cc.orig
+++ ggadget/gtk/utilities.cc
@@ -262,7 +262,7 @@
     if (fork() != 0)
       _exit(0);
 
-    execl(xdg_open.c_str(), xdg_open.c_str(), url, NULL);
+    execl(xdg_open.c_str(), xdg_open.c_str(), url, (char*)0);
 
     DLOG("Failed to exec command: %s", xdg_open.c_str());
     _exit(-1);
