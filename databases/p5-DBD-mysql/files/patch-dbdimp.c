--- dbdimp.c.orig	2018-09-08 20:02:03 UTC
+++ dbdimp.c
@@ -1907,14 +1907,14 @@ MYSQL *mysql_dr_connect(
                          (SvTRUE(*svp) ? "utf8" : "latin1"));
         }
 
-#if (MYSQL_VERSION_ID >= 50723) && (MYSQL_VERSION_ID < MARIADB_BASE_VERSION)
+#if (MYSQL_VERSION_ID >= 50723) && (MYSQL_VERSION_ID < MARIADB_VERSION_ID)
         if ((svp = hv_fetch(hv, "mysql_get_server_pubkey", 23, FALSE)) && *svp && SvTRUE(*svp)) {
           my_bool server_get_pubkey = 1;
           mysql_options(sock, MYSQL_OPT_GET_SERVER_PUBLIC_KEY, &server_get_pubkey);
         }
 #endif
 
-#if (MYSQL_VERSION_ID >= 50600) && (MYSQL_VERSION_ID < MARIADB_BASE_VERSION)
+#if (MYSQL_VERSION_ID >= 50600) && (MYSQL_VERSION_ID < MARIADB_VERSION_ID)
         if ((svp = hv_fetch(hv, "mysql_server_pubkey", 19, FALSE)) && *svp) {
           STRLEN plen;
           char *server_pubkey = SvPV(*svp, plen);
