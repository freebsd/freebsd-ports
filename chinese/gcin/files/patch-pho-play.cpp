--- pho-play.cpp.orig	2012-01-25 19:26:50.000000000 +0800
+++ pho-play.cpp	2012-01-25 19:27:29.000000000 +0800
@@ -12,7 +12,7 @@ int pho_play(phokey_t key)
   if (!phonetic_speak)
     return 0;
   if (test_mode)
-    return;
+    return 0;
 
   static int pid;
   static time_t last_time;
