--- storage/connect/tabmysql.cpp.orig	2017-03-06 20:04:37 UTC
+++ storage/connect/tabmysql.cpp
@@ -335,7 +335,7 @@ bool MYSQLDEF::DefineAM(PGLOBAL g, LPCST
     Delayed = !!GetIntCatInfo("Delayed", 0);
   } else {
     // MYSQL access from a PROXY table 
-    Tabschema = GetStringCatInfo(g, "Database", Tabschema ? Tabschema : PlugDup(g, "*"));
+    Tabschema = GetStringCatInfo(g, "Database", Tabschema ? Tabschema : PlugDup(g, (PSZ)"*"));
     Isview = GetBoolCatInfo("View", false);
 
     // We must get other connection parms from the calling table
