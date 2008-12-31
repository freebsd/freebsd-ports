Index: pcp/pcp_node_count.c
===================================================================
RCS file: /cvsroot/pgpool/pgpool-II/pcp/pcp_node_count.c,v
retrieving revision 1.2
diff -u -r1.2 pcp_node_count.c
--- pcp/pcp_node_count.c	29 Jan 2008 01:56:38 -0000	1.2
+++ pcp/pcp_node_count.c	29 Dec 2008 05:15:44 -0000
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "pcp.h"
 
@@ -38,53 +39,64 @@
 	char user[MAX_USER_PASSWD_LEN];
 	char pass[MAX_USER_PASSWD_LEN];
 	int node_count;
+	int ch;
 
-	if (argc == 2 && (strcmp(argv[1], "-h") == 0) )
-	{
-		usage();
-		exit(0);
+	while ((ch = getopt(argc, argv, "hd")) != -1) {
+		switch (ch) {
+		case 'd':
+			pcp_enable_debug();
+			break;
+
+		case 'h':
+		case '?':
+		default:
+			usage();
+			exit(0);
+		}
 	}
+	argc -= optind;
+	argv += optind;
 
-	if (argc != 6) {
+	if (argc != 5) {
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
 
-	timeout = atol(argv[1]);
+	timeout = atol(argv[0]);
 	if (timeout < 0) {
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
 
-	if (strlen(argv[2]) >= MAX_DB_HOST_NAMELEN) {
+	if (strlen(argv[1]) >= MAX_DB_HOST_NAMELEN) {
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
-	strcpy(host, argv[2]);
+	strcpy(host, argv[1]);
 
-	port = atoi(argv[3]);
+	port = atoi(argv[2]);
 	if (port <= 1024 || port > 65535) {
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
 
-	if (strlen(argv[4]) >= MAX_USER_PASSWD_LEN) {
+	if (strlen(argv[3]) >= MAX_USER_PASSWD_LEN) {
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
-	strcpy(user, argv[4]);
+	strcpy(user, argv[3]);
 
-	if (strlen(argv[5]) >= MAX_USER_PASSWD_LEN) {
+	if (strlen(argv[4]) >= MAX_USER_PASSWD_LEN) {
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
-	strcpy(pass, argv[5]);
+	strcpy(pass, argv[4]);
 
 	pcp_set_timeout(timeout);
 
@@ -112,8 +124,9 @@
 usage(void)
 {
 	fprintf(stderr, "pcp_node_count - display the total number of nodes under pgpool-II's control\n\n");
-	fprintf(stderr, "Usage: pcp_node_count timeout hostname port# username password\n");
+	fprintf(stderr, "Usage: pcp_node_count [-d] timeout hostname port# username password\n");
 	fprintf(stderr, "Usage: pcp_node_count -h\n\n");
+	fprintf(stderr, "  -d       - enable debug message (optional)\n");
 	fprintf(stderr, "  timeout  - connection timeout value in seconds. command exits on timeout\n");
 	fprintf(stderr, "  hostname - pgpool-II hostname\n");
 	fprintf(stderr, "  port#    - pgpool-II port number\n");
