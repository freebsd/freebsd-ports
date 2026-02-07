--- server/comuni.c.orig	2008-10-27 00:11:36.000000000 +0900
+++ server/comuni.c	2008-10-27 00:14:22.000000000 +0900
@@ -338,8 +338,16 @@
 	memset((char *)&sin, '\0', sizeof(sin));
 	sin.sin_family      = AF_INET;
 	sin.sin_port        = htons(port);
-	sin.sin_addr.s_addr = htonl(INADDR_ANY);
-
+	if (!inet_aton(server_name, &sin.sin_addr)) {
+		struct hostent	*hp;
+		struct in_addr	**pptr;
+		if ((hp = gethostbyname(server_name)) == NULL) {
+			fprintf(stderr, "Can't resolve %s\n", server_name);
+			exit(1);
+		}
+		pptr = (struct in_addr **)hp->h_addr_list;
+		memcpy(&sin.sin_addr, pptr[0], sizeof(struct in_addr));
+	}
 	if ((fd_inet = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
 		fprintf(stderr, "Can't create AF_INET socket\n");
 		exit(1);
