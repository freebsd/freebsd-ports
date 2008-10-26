--- server/sj3serv.h.orig	2008-10-26 23:43:14.000000000 +0900
+++ server/sj3serv.h	2008-10-26 23:43:29.000000000 +0900
@@ -126,6 +126,7 @@
 extern char	*error_file;
 extern char	*log_file;
 extern char	*port_name;
+extern char	*server_name;
 #ifdef TLI
 extern char	*port_number;
 #else
