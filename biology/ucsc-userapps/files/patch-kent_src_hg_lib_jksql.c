--- kent/src/hg/lib/jksql.c.orig	2026-08-31 20:06:42 UTC
+++ kent/src/hg/lib/jksql.c
@@ -1140,7 +1140,8 @@ else   // TURN VERIFICATION OFF
 else   // TURN VERIFICATION OFF
     {
     #if !defined(MARIADB_BASE_VERSION) && defined(MYSQL_VERSION_ID) && (MYSQL_VERSION_ID >= 80000) // OVER-RIDE DEFAULT COMPILED IN.
-    mysql_options(conn, MYSQL_OPT_SSL_MODE, SSL_MODE_PREFERRED);
+    int mode_arg = SSL_MODE_PREFERRED;
+    mysql_options(conn, MYSQL_OPT_SSL_MODE, &mode_arg);
     #else
     my_bool flag = FALSE;
     mysql_options(conn, MYSQL_OPT_SSL_VERIFY_SERVER_CERT, &flag);
