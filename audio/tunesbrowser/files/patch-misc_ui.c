--- misc_ui.c.orig	Wed Jul 28 06:41:58 2004
+++ misc_ui.c	Wed Jul 28 06:43:37 2004
@@ -139,8 +139,8 @@
     if (seconds >= 0)
     {
         int minutes = seconds / 60;
+        char bufstr[11];
         seconds -= minutes * 60;
-        char bufstr[11] = {0};
 
         snprintf(bufstr, 10, "%i:%02i",
                  minutes, seconds);
