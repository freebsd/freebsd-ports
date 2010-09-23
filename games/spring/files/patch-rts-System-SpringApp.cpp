--- rts/System/SpringApp.cpp.orig	2010-09-06 16:16:18.000000000 +0400
+++ rts/System/SpringApp.cpp	2010-09-15 23:03:15.000000000 +0400
@@ -255,7 +255,7 @@
 			logOutput.Print("CPU: affinity failed");
 		}
 	}
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) // may still use something like below for FreeBSD
 	// no-op
 #else
 	if (affinity > 0) {
