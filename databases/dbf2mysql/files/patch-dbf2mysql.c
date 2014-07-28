--- dbf2mysql.c.orig	Fri Jul  7 04:55:02 2000
+++ dbf2mysql.c	Mon Mar 15 16:46:17 2004
@@ -9,6 +9,12 @@
    Fixxed Quick mode insert for blank Numeric fields
    Modified to use -x flag to add _rec and _timestamp fields to start of record.
       ( only those lines immediately affect by if(express) (and getopt) )
+
+   Bart Friederichs (bart@friesoft.nl) feb 2003
+   Added MYSQL_OPT_LOCAL_INFILE to options for compatibility with 
+   MySQL >3.23.49 and >4.0.2, new option -L enables it
+   Replaced mysql_connect with mysql_real_connect, SQLsock isn't used anymore
+
 */
 #include <stdio.h>
 #include <fcntl.h>
@@ -17,10 +23,15 @@
 #include <string.h>
 #include <ctype.h>
 #include <mysql.h>
+#include <paths.h>
 #include "dbf.h"
 
+#if !defined(_PATH_TMP)
+#define _PATH_TMP	"/tmp/"
+#endif
+
 int	verbose=0, upper=0, lower=0, create=0, fieldlow=0, var_chars=1;
-int	express=0;
+int	express=0, enable_local=0;
 int	null_fields=0, trim=0, quick=0;
 char	primary[11];
 char	*host = NULL;
@@ -79,7 +90,7 @@
 		printf("dbf2mysql %s\n", VERSION);
 		printf("usage: dbf2mysql [-h hostname] [-d dbase] [-t table] [-p primary key]\n");
 		printf("                 [-o field[,field]] [-s oldname=newname[,oldname=newname]]\n");
-		printf("                 [-i field[,field]] [-c] [-f] [-F] [-n] [-r] [-u|-l] \n"); 
+		printf("                 [-i field[,field]] [-c] [-f] [-F] [-n] [-r] [-u|-l] [-L]\n"); 
 		printf("                 [-v[v]] [-x] [-q]  [-P password] [-U user] dbf-file\n");
 }
 
@@ -319,7 +330,7 @@
 /* Patched by GLC to fix quick mode Numeric fields */
 void do_inserts(MYSQL *SQLsock, char *table, dbhead *dbh)
 {
-    int		result, i, j, nc = 0, h;
+    int		result, i, j, nc = 0, h, fd;
     field	*fields;
     char	*query, *vpos, *pos;
     char	str[257], *cvt = NULL, *s;
@@ -395,9 +406,17 @@
 	    strcat(query, "NULL,NULL,");
 	else  /* if specified -q create file for 'LOAD DATA' */
 	{
-	    datafile = tempnam ("/tmp", "d2my");
-	    tempfile = fopen (datafile, "wt");
-	    if (tempfile == NULL || datafile == NULL)
+	    if (asprintf(&datafile, "%s/d2myXXXXXXXX",
+	      getenv("TMPDIR") ? getenv("TMPDIR") : _PATH_TMP) == -1) {
+		fprintf (stderr, "asprintf() failed");
+		return;
+	    }
+	    if ((fd = mkstemp(datafile)) == -1) {
+		fprintf (stderr, "mkstemp() failed");
+		return;
+	    }
+	    tempfile = fdopen (fd, "w");
+	    if (tempfile == NULL)
 	    {
 		fprintf (stderr, "Cannot open file '%s' for writing\n", datafile);
 		return;
@@ -575,7 +594,7 @@
 	}
 	if (mysql_query(SQLsock, query) == -1) {
 	    fprintf(stderr,
-	  	    "Error sending LOAD DATA INFILE from file '%s'\n", datafile);
+	  	    "Error sending LOAD DATA LOCAL INFILE from file '%s'\n", datafile);
 	    fprintf(stderr,
 		    "Detailed report: %s\n",
 		    mysql_error(SQLsock));
@@ -591,7 +610,7 @@
 int main(int argc, char **argv)
 {
 	int 		i;
-	MYSQL		*SQLsock,mysql;
+	MYSQL		mysql;
 	extern int 	optind;
 	extern char	*optarg;
 	char		*query;
@@ -599,7 +618,7 @@
 
 	primary[0] = '\0';
 
-	while ((i = getopt(argc, argv, "xqfFrne:lucvi:h:p:d:t:s:o:U:P:")) != EOF) {
+	while ((i = getopt(argc, argv, "xqLfFrne:lucvi:h:p:d:t:s:o:U:P:")) != EOF) {
 		switch (i) {
 		        case 'P':
 				pass = (char *)strdup(optarg);
@@ -666,6 +685,9 @@
 			case 'o':
 				flist = (char *)strdup(optarg);
 				break;
+			case 'L':
+				enable_local = 1;
+				break;
 			case ':':
 				usage();
 				printf("missing argument!\n");
@@ -704,6 +726,7 @@
 		       table);
 		printf("Number of records: %ld\n", dbh->db_records);
 	}
+
 	if (verbose > 1) {
 		printf("Name\t\t Length\tDisplay\t Type\n");
 		printf("-------------------------------------\n");
@@ -720,7 +743,20 @@
 		printf("Making connection to MySQL-server\n");
 	}
 
-	if (!(SQLsock = mysql_connect(&mysql,host,user,pass))) {
+	mysql_init(&mysql);
+
+	if (enable_local == 1) {
+		if (verbose) {
+			printf("Setting MySQL option MYSQL_OPT_LOCAL_INFILE\n");
+		}
+
+		if (mysql_options(&mysql, MYSQL_OPT_LOCAL_INFILE, 0)) {
+		    printf("Setting options failed.");
+		    exit(1);
+		}
+	}
+
+	if (!mysql_real_connect(&mysql,host,user,pass, dbase, 0, NULL,0)) {
 		fprintf(stderr, "Couldn't get a connection with the ");
 		fprintf(stderr, "designated host!\n");
 		fprintf(stderr, "Detailed report: %s\n", mysql_error(&mysql));
@@ -728,23 +764,12 @@
 		exit(1);
 	}
 
-	if (verbose > 2) {
-		printf("Selecting database '%s'\n", dbase);
-	}
-
-	if ((mysql_select_db(SQLsock, dbase)) == -1) {
-		fprintf(stderr, "Couldn't select database %s.\n", dbase);
-		fprintf(stderr, "Detailed report: %s\n", mysql_error(SQLsock));
-		mysql_close(SQLsock);
-		dbf_close(&dbh);
-		exit(1);
-	}
 /* Substitute field names */
       do_onlyfields(flist, dbh);
       do_substitute(subarg, dbh);
 
 	if (!create) {
-		if (!check_table(SQLsock, table)) {
+		if (!check_table(&mysql, table)) {
 			printf("Table does not exist!\n");
 			exit(1);
 		}
@@ -755,30 +780,30 @@
 
 		if (!(query = (char *)malloc(12 + strlen(table)))) {
 			printf("Memory-allocation error in main (drop)!\n");
-			mysql_close(SQLsock);
+			mysql_close(&mysql);
 			dbf_close(&dbh);
 			exit(1);
 		}
 
 		sprintf(query, "DROP TABLE %s", table);
-		mysql_query(SQLsock, query);
+		mysql_query(&mysql, query);
 		free(query);
 
 /* Build a CREATE-clause
 */
-		do_create(SQLsock, table, dbh);
+		do_create(&mysql, table, dbh);
 	}
 
 /* Build an INSERT-clause
 */
 	if (create < 2)
-	  do_inserts(SQLsock, table, dbh);
+	  do_inserts(&mysql, table, dbh);
 
 	if (verbose > 2) {
 		printf("Closing up....\n");
 	}
 
-    mysql_close(SQLsock);
+    mysql_close(&mysql);
     dbf_close(&dbh);
     exit(0);
 }
