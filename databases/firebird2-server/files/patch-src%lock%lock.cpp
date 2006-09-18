--- src/lock/lock.cpp.orig	Fri Feb  3 16:13:23 2006
+++ src/lock/lock.cpp	Wed Aug 16 12:41:32 2006
@@ -2708,7 +2708,12 @@
 #ifdef DEBUG_MANAGER
 	gds__prefix(string, DEBUG_MANAGER);
 #else
-	gds__prefix(string, LOCK_MANAGER);
+	if (! getenv("FIREBIRD")) {
+		strlcpy(string, FB_EXEC_PREFIX "/", MAXPATHLEN);
+		strlcat(string, LOCK_MANAGER, MAXPATHLEN);
+	} else	{
+		gds__prefix(string, LOCK_MANAGER);
+	}
 #endif
 	if (statistics(string, &stat_buf) == -1) {
 		// bug() fills the vector with this address, it must be static.
