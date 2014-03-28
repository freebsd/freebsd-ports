--- src/notices.c.orig	2012-04-26 16:10:18.000000000 -0500
+++ src/notices.c
@@ -31,6 +31,9 @@
 #include <stdio.h>
 #include <libpq-fe.h>
 
+void notice_install (PGconn *, void *);
+void notice_uninstall (PGconn *);
+
 /*
  * Connection_Notify is an Ada procedure using C calling convention :
  */
