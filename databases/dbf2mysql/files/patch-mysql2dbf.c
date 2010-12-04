Index: databases/dbf2mysql/work/dbf2mysql-1.14/mysql2dbf.c
===================================================================
--- mysql2dbf.c.orig	2010-11-28 19:46:34.000000000 +0100
+++ mysql2dbf.c	2010-11-28 21:23:22.000000000 +0100
@@ -1,6 +1,11 @@
 /*	utility to read out an mySQL-table, and store it into a DBF-file
 
 	M. Boekhold (boekhold@cindy.et.tudelft.nl) April 1996
+
+	M. Lachman Nov 2010
+	Replaced mysql_connect with mysql_real_connect, SQLsock isn't used anymore
+	Can be compiled with MySQL client 5.0.x
+
 */
 
 #include <stdio.h>
@@ -47,7 +52,7 @@
 
 int main(int argc, char **argv) {
 	int             i;
-	MYSQL		*SQLsock,mysql;
+	MYSQL		mysql;
 	extern int      optind;
 	extern char     *optarg;
 	char            *query = NULL;
@@ -148,7 +153,9 @@
 		printf("Making connection with mySQL-server\n");
 	}
 
-    if (!(SQLsock = mysql_connect(&mysql,host,user,pass))) {
+    mysql_init(&mysql);
+
+    if (!mysql_real_connect(&mysql,host,user,pass, dbase, 0, NULL,0)) {
         fprintf(stderr, "Couldn't get a connection with the ");
         fprintf(stderr, "designated host!\n");
         fprintf(stderr, "Detailed report: %s\n", mysql_error(&mysql));
@@ -157,37 +164,24 @@
         exit(1);
     }
 
-    if (verbose > 1) {
-        printf("Selecting database\n");
-    }
-
-    if ((mysql_select_db(SQLsock, dbase)) == -1) {
-        fprintf(stderr, "Couldn't select database %s.\n", dbase);
-        fprintf(stderr, "Detailed report: %s\n", mysql_error(SQLsock));
-        close(dbh->db_fd);
-        free(dbh);
-        mysql_close(SQLsock);
-        exit(1);
-    }
-
 	if (verbose > 1) {
 		printf("Sending query\n");
 	}
 	
 
-	if (mysql_query(SQLsock, query) == -1) {
+	if (mysql_query(&mysql, query) == -1) {
 		fprintf(stderr, "Error sending query.\nDetailed report: %s\n",
-				mysql_error(SQLsock));
+				mysql_error(&mysql));
 		if (verbose > 1) {
 			fprintf(stderr, "%s\n", query);
 		}
-		mysql_close(SQLsock);
+		mysql_close(&mysql);
 		close(dbh->db_fd);
 		free(dbh);
 		exit(1);
 	}
 
-	qres            = mysql_store_result(SQLsock);
+	qres            = mysql_store_result(&mysql);
 	numfields       = mysql_num_fields(qres);
 	numrows			= mysql_num_rows(qres);
 
@@ -303,7 +297,7 @@
 	}
 				
 	mysql_free_result(qres);
-	mysql_close(SQLsock);
+	mysql_close(&mysql);
 	close(dbh->db_fd);
 	free(dbh);
 	exit(0);

