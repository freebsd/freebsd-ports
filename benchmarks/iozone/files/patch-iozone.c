--- iozone.c.orig	2020-08-23 23:33:25 UTC
+++ iozone.c
@@ -1676,7 +1676,7 @@ int client_error;
 
 char pit_hostname[40];
 char pit_service[8];
-int junk;
+extern int junk;
 
 /* 
  * Host ports used to listen, and handle errors.
