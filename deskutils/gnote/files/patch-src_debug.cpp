--- src/debug.cpp.orig	2009-11-25 14:12:33.000000000 +0100
+++ src/debug.cpp	2009-12-03 17:28:54.000000000 +0100
@@ -126,7 +126,7 @@
 //    static boost::recursive_mutex mutex;
 //    boost::recursive_mutex::scoped_lock lock(mutex);
     char buf[128];
-    snprintf(buf, 128, "(%d) ", (int)pthread_self());
+    snprintf(buf, 128, "(%ld) ", (pthread_t)pthread_self());
     fwrite(buf, 1, strlen(buf), stderr);
     fwrite(prefix, 1, strlen(prefix), stderr);
 
