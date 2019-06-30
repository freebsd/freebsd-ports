--- sql/mysqld.cc.orig	2017-05-14 23:13:18 UTC
+++ sql/mysqld.cc
@@ -4838,8 +4840,9 @@ static void init_ssl()
       while ((err= ERR_get_error()))
         sql_print_warning("SSL error: %s", ERR_error_string(err, NULL));
     }
-    else
+    else {
       ERR_remove_state(0);
+    }
   }
   else
   {
