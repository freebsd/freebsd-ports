--- ./src/MadEditFrame.cpp.orig	2007-10-08 02:37:26.000000000 -0700
+++ ./src/MadEditFrame.cpp	2009-02-12 17:39:21.810385103 -0800
@@ -2158,7 +2158,7 @@
 #ifndef __WXMSW__
     // it will crash randomly under linux.
     // so we must call exit() to quit the app.
-    exit(0);
+    _Exit(0);
 #else
     extern HANDLE g_Mutex;
     if(g_Mutex)
