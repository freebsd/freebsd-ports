--- libbase/GnashSleep.h.orig	2022-12-05 11:34:39 UTC
+++ libbase/GnashSleep.h
@@ -38,7 +38,7 @@ inline void gnashSleep(time_t useconds)
     Sleep(useconds / 1000);
 #else
     const time_t m = 1000000;
-    const struct timespec t = { useconds / m, (useconds % m) * 1000 };
+    const struct timespec t = { useconds / m, (long)((useconds % m) * 1000) };
     ::nanosleep(&t, nullptr);
 #endif
 }
