#
# Apply fix for MySQL bug http://bugs.mysql.com/bug.php?id=22227
#
--- include/mysql_com.h.orig	Fri Aug 25 18:11:46 2006
+++ include/mysql_com.h	Wed Sep 27 10:02:44 2006
@@ -134,11 +134,11 @@
 #define CLIENT_TRANSACTIONS	8192	/* Client knows about transactions */
 #define CLIENT_RESERVED         16384   /* Old flag for 4.1 protocol  */
 #define CLIENT_SECURE_CONNECTION 32768  /* New 4.1 authentication */
-#define CLIENT_MULTI_STATEMENTS (((ulong) 1) << 16)   /* Enable/disable multi-stmt support */
-#define CLIENT_MULTI_RESULTS    (((ulong) 1) << 17)  /* Enable/disable multi-results */
+#define CLIENT_MULTI_STATEMENTS (1UL << 16)   /* Enable/disable multi-stmt support */
+#define CLIENT_MULTI_RESULTS    (1UL << 17)  /* Enable/disable multi-results */
 
-#define CLIENT_SSL_VERIFY_SERVER_CERT	(((ulong) 1) << 30)
-#define CLIENT_REMEMBER_OPTIONS	(((ulong) 1) << 31)
+#define CLIENT_SSL_VERIFY_SERVER_CERT	(1UL << 30)
+#define CLIENT_REMEMBER_OPTIONS	(1UL << 31)
 
 #define SERVER_STATUS_IN_TRANS     1	/* Transaction has started */
 #define SERVER_STATUS_AUTOCOMMIT   2	/* Server in auto_commit mode */
