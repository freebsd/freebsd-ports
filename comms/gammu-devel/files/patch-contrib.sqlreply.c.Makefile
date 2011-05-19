--- contrib/sqlreply/c/Makefile.orig	2011-05-19 14:38:18.000000000 -0300
+++ contrib/sqlreply/c/Makefile	2011-05-19 14:38:31.000000000 -0300
@@ -7,8 +7,8 @@
 
 michal: michal.o
 	@echo Linking
-	@$(CC) michal.o -L/usr/lib/mysql -lmysqlclient -lz -o michal
+	@$(CC) michal.o -L/usr/local/lib/mysql -lmysqlclient -lz -o michal
 
 clean:
 	@rm michal michal.o
-	
\ No newline at end of file
+	
