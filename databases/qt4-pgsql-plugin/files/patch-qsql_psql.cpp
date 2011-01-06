--- ./src/sql/drivers/psql/qsql_psql.cpp	2010-09-10 11:05:25.000000000 +0200
+++ ./src/sql/drivers/psql/qsql_psql.cpp	2010-11-03 12:37:55.966977333 +0100
@@ -661,6 +661,17 @@
                     break;
                 }
                 break;
+             case 9:
+                switch (vMin) {
+                case 0:
+                    serverVersion = QPSQLDriver::Version9;
+                    break;
+                default:
+                    serverVersion = QPSQLDriver::Version9;
+                    break;
+                }
+                break;
+
             default:
                 break;
             }
@@ -852,7 +863,8 @@
     // This hack can dissapear once there is an API to query this sort of information.
     if (d->pro == QPSQLDriver::Version8 ||
         d->pro == QPSQLDriver::Version81 ||
-        d->pro == QPSQLDriver::Version82) {
+        d->pro == QPSQLDriver::Version82 ||
+        d->pro == QPSQLDriver::Version9)  {
         transaction_failed = qstrcmp(PQcmdStatus(res), "ROLLBACK") == 0;
     }
 
@@ -963,6 +975,7 @@
     case QPSQLDriver::Version8:
     case QPSQLDriver::Version81:
     case QPSQLDriver::Version82:
+    case QPSQLDriver::Version9:
         stmt = QLatin1String("SELECT pg_attribute.attname, pg_attribute.atttypid::int, "
                 "pg_class.relname "
                 "FROM pg_attribute, pg_class "
@@ -1046,6 +1059,7 @@
     case QPSQLDriver::Version8:
     case QPSQLDriver::Version81:
     case QPSQLDriver::Version82:
+    case QPSQLDriver::Version9:
         stmt = QLatin1String("select pg_attribute.attname, pg_attribute.atttypid::int, "
                 "pg_attribute.attnotnull, pg_attribute.attlen, pg_attribute.atttypmod, "
                 "pg_attrdef.adsrc "
