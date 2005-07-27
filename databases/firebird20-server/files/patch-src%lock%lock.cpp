--- src/lock/lock.cpp.orig	Mon Mar 29 08:35:49 2004
+++ src/lock/lock.cpp	Wed Jul 27 14:01:51 2005
@@ -2800,7 +2800,11 @@
 #ifdef DEBUG_MANAGER
 	gds__prefix(string, DEBUG_MANAGER);
 #else
-	gds__prefix(string, LOCK_MANAGER);
+	if (! getenv("FIREBIRD")) {
+		strlcpy(string, FB_EXEC_PREFIX "/s" LOCK_MANAGER, MAXPATHLEN);
+	}else	{
+		gds__prefix(string, LOCK_MANAGER);
+	}
 #endif
 	if (statistics(string, &stat_buf) == -1) {
 		sprintf (errorstring, "can't start lock manager: %s", string);
