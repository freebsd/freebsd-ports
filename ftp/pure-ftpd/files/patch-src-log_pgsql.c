Obtained from:	https://github.com/jedisct1/pure-ftpd/commit/c3f0f3c91d86939e6fabf5f65c6c6fc964e6032e

--- src/log_pgsql.c.orig	2021-11-23 21:36:05 UTC
+++ src/log_pgsql.c
@@ -278,7 +278,6 @@ static int pw_pgsql_connect(PGconn ** const id_sql_ser
     *id_sql_server = NULL;
 
     if ((escaped_server = pw_pgsql_escape_conninfo(server)) == NULL ||
-        (escaped_port = pw_pgsql_escape_conninfo(port)) == NULL ||
         (escaped_db = pw_pgsql_escape_conninfo(db)) == NULL ||
         (escaped_user = pw_pgsql_escape_conninfo(user)) == NULL ||
         (escaped_pw = pw_pgsql_escape_conninfo(pw)) == NULL) {
@@ -296,7 +295,7 @@ static int pw_pgsql_connect(PGconn ** const id_sql_ser
     }
     if (SNCHECK(snprintf(conninfo, sizeof_conninfo,
                          PGSQL_CONNECT_FMTSTRING,
-                         escaped_server, escaped_port, escaped_db,
+                         escaped_server, port, escaped_db,
                          escaped_user, escaped_pw), sizeof_conninfo)) {
         goto bye;
     }
@@ -314,7 +313,6 @@ static int pw_pgsql_connect(PGconn ** const id_sql_ser
     bye:
     free(conninfo);
     free(escaped_server);
-    free(escaped_port);
     free(escaped_db);
     free(escaped_user);
     free(escaped_pw);
