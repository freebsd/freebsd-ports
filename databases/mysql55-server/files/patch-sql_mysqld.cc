--- sql/mysqld.cc.orig	Mon Jun  3 12:39:02 2002
+++ sql/mysqld.cc	Mon Aug 12 11:15:20 2002
@@ -90,7 +90,7 @@
 int allow_severity = LOG_INFO;
 int deny_severity = LOG_WARNING;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define my_fromhost(A)	   fromhost()
 #define my_hosts_access(A) hosts_access()
 #define my_eval_client(A)  eval_client()
