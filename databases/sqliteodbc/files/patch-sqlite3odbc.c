--- sqlite3odbc.c.orig	2023-08-24 08:50:22 UTC
+++ sqlite3odbc.c
@@ -13305,7 +13305,7 @@ drvdriverconnect(SQLHDBC dbc, SQLHWND hwnd,
 				   attas, sizeof (attas), ODBC_INI);
     }
 #endif
-    illag[0] = '\0';
+    ilflag[0] = '\0';
     getdsnattr(buf, "ilike", ilflag, sizeof (ilflag));
 #ifndef WITHOUT_DRIVERMGR
     if (dsn[0] && !ilflag[0]) {
