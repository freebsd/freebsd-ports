--- sqlplusint/connection.cc.orig	Fri Nov 21 15:59:47 2003
+++ sqlplusint/connection.cc	Fri Nov 21 16:00:19 2003
@@ -109,7 +109,7 @@
 }
 
 string Connection::info () {
-  char *i = mysql_info(&mysql);
+  const char *i = mysql_info(&mysql);
   if (!i)
     return string();
   else
