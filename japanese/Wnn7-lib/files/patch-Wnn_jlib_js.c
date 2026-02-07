--- Wnn/jlib/js.c.orig	2001-10-17 10:37:17.000000000 +0900
+++ Wnn/jlib/js.c	2008-12-30 01:41:03.000000000 +0900
@@ -159,9 +159,9 @@
 */
 
 
-extern	char	*malloc();
-
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #ifdef UX386
 #include <X11/Xos.h>
@@ -199,8 +199,6 @@
 #include "../etc/pwd.c"
 
 
-char *malloc();
-
 typedef struct _host_address {
 	int address_len;
 	char *address;
@@ -358,14 +356,17 @@
 	/* find socket name from table by lang */
 	sock_name = UNIX_SOCKET_NAME;		/* Jserver */
 	strcpy(saddr.sun_path, sock_name);
-#if ((defined AIXV3) || (defined FREEBSD))
+#if ((defined AIXV3))
 	strcat(saddr.sun_path, "=");
 #endif
 
 	if ((sd = socket(AF_UNIX,SOCK_STREAM, 0)) == ERROR) {
 		return -1;
 	}
-	if (connect(sd,(struct sockaddr *)&saddr,strlen(saddr.sun_path)+sizeof(saddr.sun_family)) == ERROR) {
+#if !defined(SUN_LEN)
+# define SUN_LEN(su) (sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
+#endif
+	if (connect(sd,(struct sockaddr *)&saddr, SUN_LEN(&saddr)) == ERROR) {
 		close(sd);
 		return -1;
 	}
