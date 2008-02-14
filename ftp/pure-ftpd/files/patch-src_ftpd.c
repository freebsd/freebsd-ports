--- src/ftpd.c	2006-02-21 14:14:49.000000000 +0100
+++ src/ftpd.c	2007-12-20 14:53:56.000000000 +0100
@@ -3439,14 +3439,14 @@ void dofeat(void)
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


