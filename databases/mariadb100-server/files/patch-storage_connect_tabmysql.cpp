See https://mariadb.atlassian.net/browse/MDEV-9603

--- storage/connect/tabmysql.cpp.orig	2016-04-28 20:27:49 UTC
+++ storage/connect/tabmysql.cpp
@@ -334,7 +334,7 @@ bool MYSQLDEF::DefineAM(PGLOBAL g, LPCST
     Delayed = !!GetIntCatInfo("Delayed", 0);
   } else {
     // MYSQL access from a PROXY table 
-    Database = GetStringCatInfo(g, "Database", Schema ? Schema : PlugDup(g, "*"));
+    Database = GetStringCatInfo(g, "Database", Schema ? Schema : PlugDup(g, (PSZ)"*"));
     Isview = GetBoolCatInfo("View", false);
 
     // We must get other connection parms from the calling table
