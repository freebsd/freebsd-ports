--- client/mysql.cc.orig	2018-05-08 12:44:38.160868000 +0200
+++ client/mysql.cc	2018-05-08 12:45:01.377062000 +0200
@@ -2671,7 +2671,7 @@
         mysql_free_result(fields);
         break;
       }
-      field_names[i][num_fields*2]= '\0';
+      field_names[i][num_fields*2]= NULL;
       j=0;
       while ((sql_field=mysql_fetch_field(fields)))
       {
