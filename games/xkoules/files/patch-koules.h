--- koules.h.orig	1998-03-04 18:59:19 UTC
+++ koules.h
@@ -238,7 +238,7 @@ extern Point    point[MAXPOINT];
 extern int      gameplan;
 extern int      rotation[MAXROCKETS];
 extern char     control[MAXROCKETS];
-extern struct control controls[5];
+extern struct control controls[MAXROCKETS];
 extern int      lastlevel, maxlevel;
 #ifdef NETSUPPORT
 extern int      client, server;
