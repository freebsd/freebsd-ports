--- thirdparty/RGFW.h.orig	2026-02-15 10:27:12 UTC
+++ thirdparty/RGFW.h
@@ -2911,7 +2911,7 @@ struct RGFW_info {
 
     RGFW_monitors monitors;
 
-    #ifdef __linux__
+    #if defined(__linux__) || defined(__FreeBSD__)
 	    int eventWait_forceStop[3];
     #endif
 
