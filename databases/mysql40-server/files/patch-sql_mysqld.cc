--- sql/mysqld.cc.orig	Wed Aug 14 00:08:13 2002
+++ sql/mysqld.cc	Sun Nov 10 10:23:55 2002
@@ -92,7 +92,7 @@
 int allow_severity = LOG_INFO;
 int deny_severity = LOG_WARNING;
 
-#ifdef __STDC__
+#if defined(__STDC__) && !defined(__FreeBSD__)
 #define my_fromhost(A)	   fromhost(A)
 #define my_hosts_access(A) hosts_access(A)
 #define my_eval_client(A)  eval_client(A)
