--- src/args.cpp.orig	2004-05-05 23:49:20 UTC
+++ src/args.cpp
@@ -95,7 +95,7 @@ using std::endl;
 // Convert time from integer
 bool ConsolePlayer::parseTime (const char *str, uint_least32_t &time)
 {
-    char *sep;
+    const char *sep;
     uint_least32_t _time;
 
     // Check for empty string
@@ -110,8 +110,9 @@ bool ConsolePlayer::parseTime (const cha
     else
     {   // Read in MM:SS format
         int val;
-        *sep = '\0';
-        val  = atoi (str);
+        char *tmp = strndup(str, sep - str);
+        val  = atoi (tmp);
+        free(tmp);
         if (val < 0 || val > 99)
             return false;
         _time = (uint_least32_t) val * 60;
