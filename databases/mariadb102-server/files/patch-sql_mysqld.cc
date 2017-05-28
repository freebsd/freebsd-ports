--- sql/mysqld.cc.orig	2017-05-14 23:13:18 UTC
+++ sql/mysqld.cc
@@ -111,6 +111,7 @@
 #endif
 
 #include <my_systemd.h>
+#include <my_crypt.h>
 
 #define mysqld_charset &my_charset_latin1
 
@@ -120,6 +121,7 @@
 #define HAVE_CLOSE_SERVER_SOCK 1
 #endif
 
+
 extern "C" {					// Because of SCO 3.2V4.2
 #include <sys/stat.h>
 #ifndef __GNU_LIBRARY__
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
