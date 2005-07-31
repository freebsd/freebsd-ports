--- src/napster.c.orig	Sat Aug 28 23:27:09 2004
+++ src/napster.c	Sun Jul 10 14:46:50 2005
@@ -717,11 +717,13 @@
 		 global.linespeed,
 		 email?email:"anon@anon");
 #else  
-  size = sprintf(text+4, "%s %s %d \"Lopster %s\" %d",
+  size = sprintf(text+4, "%s %s %d \"Lopster %s\" %d %s",
 		 net->user.username, 
-		 net->user.password,
+		 strlen(net->user.password)?net->user.password:net->user.username,
 		 port, VERSION,
-		 global.linespeed);
+		 global.linespeed,
+		 email?email:"anon@anon"
+		 );
 #endif
   
   size = BSWAP16(size);
