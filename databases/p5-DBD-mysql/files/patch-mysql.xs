--- mysql.xs.orig	Fri Oct 17 19:20:50 2003
+++ mysql.xs	Tue Jun 29 05:03:15 2004
@@ -97,7 +97,11 @@
        }
  
        if (strEQ(command, "shutdown")) {
+#if MYSQL_VERSION_ID < 40103
 	   result = mysql_shutdown(sock);
+#else
+	   result = mysql_shutdown(sock, SHUTDOWN_DEFAULT);
+#endif
        } else if (strEQ(command, "reload")) {
 	   result = mysql_reload(sock);
        } else if (strEQ(command, "createdb")) {
