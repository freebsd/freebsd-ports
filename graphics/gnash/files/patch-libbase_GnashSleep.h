$NetBSD: patch-libbase_GnashSleep.h,v 1.1 2013/02/26 11:04:25 joerg Exp $

--- libbase/GnashSleep.h.orig	2013-02-25 18:39:09.000000000 +0000
+++ libbase/GnashSleep.h
@@ -38,7 +38,7 @@ inline void gnashSleep(size_t useconds)
     Sleep(useconds / 1000);
 #else
     const size_t m = 1000000;
-    const struct timespec t = { useconds / m, (useconds % m) * 1000 };
+    const struct timespec t = { static_cast<time_t>(useconds / m), static_cast<long>((useconds % m) * 1000) };
     ::nanosleep(&t, 0);
 #endif
 }
