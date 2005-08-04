--- postgres.c.orig	Sat Jun  5 15:05:36 1999
+++ postgres.c	Wed Aug  3 17:22:55 2005
@@ -18,7 +18,7 @@
 
 #include <libpq-fe.h>
 #include <string.h>
-#include <postgres.h>
+#include <c.h>
 
 #include "common.h"
 #include "status.h"
@@ -129,14 +129,7 @@
   PGresult *table_info;
   char query[512];
 
-  sprintf(query, "SELECT a.attnum, a.attname, t.typname, a.attlen,
-                         a.atttypmod, a.attnotnull, a.atthasdef
-                  FROM pg_class c, pg_attribute a, pg_type t
-                  WHERE c.relname = '%s' AND
-                        a.attnum > 0 AND
-                        a.attrelid = c.oid AND
-                        a.atttypid = t.oid
-                  ORDER BY attnum", tbf->name);
+  sprintf(query, "SELECT a.attnum, a.attname, t.typname, a.attlen, a.atttypmod, a.attnotnull, a.atthasdef FROM pg_class c, pg_attribute a, pg_type t WHERE c.relname = '%s' AND a.attnum > 0 AND a.attrelid = c.oid AND a.atttypid = t.oid ORDER BY attnum", tbf->name);
   
   table_info = PQexec(conn, query);
   if ((table_info == NULL) ||
@@ -183,11 +176,7 @@
       if (rnotnull[0] == 't')
 	strcat(type_str, " not null");
       if (rhasdef[0] == 't') {
-	sprintf(buf, "SELECT d.adsrc
-                      FROM pg_attrdef d, pg_class c
-                      WHERE c.relname = '%s' AND
-                            c.oid = d.adrelid AND
-                            d.adnum = %s",
+	sprintf(buf, "SELECT d.adsrc FROM pg_attrdef d, pg_class c WHERE c.relname = '%s' AND c.oid = d.adrelid AND d.adnum = %s",
 		tbf->name, PQgetvalue(table_info, i, 0));
 	table_info2 = PQexec(conn, buf);
 	if ((table_info2 == NULL) ||
@@ -240,13 +229,7 @@
     PGresult *tables;
     char query[512];
     
-    sprintf(query, "SELECT usename, relname, relkind, relhasrules
-                    FROM pg_class, pg_user
-                    WHERE relkind = 'r' AND
-                          relname !~ '^pg_' AND
-                          relname !~ '^xin[vx][0-9]+' AND
-                          usesysid = relowner
-                    ORDER BY relname");
+    sprintf(query, "SELECT usename, relname, relkind, relhasrules FROM pg_class, pg_user WHERE relkind = 'r' AND relname !~ '^pg_' AND relname !~ '^xin[vx][0-9]+' AND usesysid = relowner ORDER BY relname");
   
     tables = PQexec(conn->conn, query);
     if ((tables == NULL) || (PQresultStatus(tables) != PGRES_TUPLES_OK)) {
