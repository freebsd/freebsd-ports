--- predict.c.orig	2023-08-05 15:33:14 UTC
+++ predict.c
@@ -30,6 +30,7 @@
 #include <assert.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/stat.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include <unistd.h>
@@ -6839,7 +6840,6 @@ void NewUser (void)
 
 void NewUser (void)
 {
-	int *mkdir();
 
 	Banner();
 	attrset(COLOR_PAIR(3)|A_BOLD);
