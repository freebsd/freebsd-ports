--- src/ftpd.c.orig	2006-02-21 16:14:49.000000000 +0300
+++ src/ftpd.c	2009-02-13 17:55:48.000000000 +0300
@@ -2541,7 +2541,7 @@
     tm.tm_mon--;
     tm.tm_year -= 1900;
     if (tm.tm_mon < 0 || tm.tm_year <= 0 ||
-	(ts = mktime(&tm)) == (time_t) -1) {
+	(ts = timegm(&tm)) == (time_t) -1) {
 	addreply_noformat(501, MSG_TIMESTAMP_FAILURE);
 	return;
     }
@@ -3439,14 +3439,14 @@
 # define FEAT_UTF8 ""
 #endif
     
-    char feat[] = FEAT FEAT_DEBUG FEAT_TVFS FEAT_ESTP FEAT_PASV FEAT_ESTA FEAT_TLS FEAT_UTF8;
+    char feat[] = FEAT FEAT_DEBUG FEAT_TVFS FEAT_ESTP FEAT_TLS FEAT_PASV FEAT_ESTA FEAT_UTF8;
 
     if (disallow_passive != 0) {
         feat[sizeof FEAT FEAT_DEBUG FEAT_TVFS FEAT_ESTP] = 0;
     }
 #ifndef MINIMAL
     else if (STORAGE_FAMILY(force_passive_ip) != 0) {
-        feat[sizeof FEAT FEAT_DEBUG FEAT_TVFS FEAT_ESTP FEAT_PASV] = 0;
+        feat[sizeof FEAT FEAT_DEBUG FEAT_TVFS FEAT_ESTP FEAT_TLS FEAT_PASV] = 0;
     }
 #endif
     addreply_noformat(0, feat);
