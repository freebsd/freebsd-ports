--- BDB.xs.orig	2011-07-29 17:28:48.000000000 +0800
+++ BDB.xs	2011-08-26 13:45:59.260319989 +0800
@@ -1313,8 +1313,10 @@
           const_iv (LOCK_DEADLOCK)
           const_iv (LOCK_NOTGRANTED)
           const_iv (NOSERVER)
+#if DBVER <= 501
           const_iv (NOSERVER_HOME)
           const_iv (NOSERVER_ID)
+#endif
           const_iv (NOTFOUND)
           const_iv (PAGE_NOTFOUND)
           const_iv (REP_DUPMASTER)
