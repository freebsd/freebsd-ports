Index: pcp/pcp_attach_node.c
===================================================================
RCS file: /cvsroot/pgpool/pgpool-II/pcp/pcp_attach_node.c,v
retrieving revision 1.2
diff -u -r1.2 pcp_attach_node.c
--- pcp/pcp_attach_node.c	29 Jan 2008 01:56:37 -0000	1.2
+++ pcp/pcp_attach_node.c	29 Dec 2008 05:15:44 -0000
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "pcp.h"
 
@@ -38,36 +39,47 @@
 	char user[MAX_USER_PASSWD_LEN];
 	char pass[MAX_USER_PASSWD_LEN];
 	int nodeID;
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
 
-	if (argc != 7)
+	if (argc != 6)
 	{
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
 
-	if (strlen(argv[2]) >= MAX_DB_HOST_NAMELEN)
+	if (strlen(argv[1]) >= MAX_DB_HOST_NAMELEN)
 	{
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
-	strcpy(host, argv[2]);
+	strcpy(host, argv[1]);
 
-	port = atoi(argv[3]);
+	port = atoi(argv[2]);
 	if (port <= 1024 || port > 65535)
 	{
 		errorcode = INVALERR;
@@ -75,23 +87,23 @@
 		myexit(errorcode);
 	}
 
-	if (strlen(argv[4]) >= MAX_USER_PASSWD_LEN)
+	if (strlen(argv[3]) >= MAX_USER_PASSWD_LEN)
 	{
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
-	strcpy(user, argv[4]);
+	strcpy(user, argv[3]);
 
-	if (strlen(argv[5]) >= MAX_USER_PASSWD_LEN)
+	if (strlen(argv[4]) >= MAX_USER_PASSWD_LEN)
 	{
 		errorcode = INVALERR;
 		pcp_errorstr(errorcode);
 		myexit(errorcode);
 	}
-	strcpy(pass, argv[5]);
+	strcpy(pass, argv[4]);
 
-	nodeID = atoi(argv[6]);
+	nodeID = atoi(argv[5]);
 	if (nodeID < 0 || nodeID > MAX_NUM_BACKENDS)
 	{
 		errorcode = INVALERR;
@@ -123,8 +135,9 @@
 usage(void)
 {
 	fprintf(stderr, "pcp_attach_node - attach a node from pgpool-II\n\n");
-	fprintf(stderr, "Usage: pcp_attach_node timeout hostname port# username password nodeID\n");
+	fprintf(stderr, "Usage: pcp_attach_node [-d] timeout hostname port# username password nodeID\n");
 	fprintf(stderr, "Usage: pcp_attach_node -h\n\n");
+	fprintf(stderr, "  -d       - enable debug message (optional)\n");
 	fprintf(stderr, "  timeout  - connection timeout value in seconds. command exits on timeout\n");
 	fprintf(stderr, "  hostname - pgpool-II hostname\n");
 	fprintf(stderr, "  port#    - pgpool-II port number\n");
