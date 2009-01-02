--- Wnn/jlib/js.c.orig	2000-09-01 18:58:55.000000000 +0900
+++ Wnn/jlib/js.c	2009-01-03 07:49:43.000000000 +0900
@@ -342,18 +342,20 @@
     } else {
 	sock_name = UNIX_SOCKET_NAME;		/* Jserver */
     }
-    strcpy(saddr.sun_path, sock_name);
-#if ((defined AIXV3) || (defined FREEBSD) || (defined BSDOS) || (defined NETBSD))
-    strcat(saddr.sun_path, "=");
-#endif
-	    
+    strncpy(saddr.sun_path, sock_name, sizeof(saddr.sun_path) - 1);
+    saddr.sun_path[sizeof(saddr.sun_path) - 1] = '\0';
+
     if ((sd = socket(AF_UNIX,SOCK_STREAM, 0)) == ERROR) {
 #if DEBUG
 	xerror("jslib:Can't create socket.\n");
 #endif
 	return -1;
     }
-    if (connect(sd,(struct sockaddr *)&saddr,strlen(saddr.sun_path)+sizeof(saddr.sun_family)) == ERROR) {
+
+#if !defined(SUN_LEN)
+# define SUN_LEN(su) (sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
+#endif
+    if (connect(sd,(struct sockaddr *)&saddr, SUN_LEN(&saddr)) == ERROR) {
 #if DEBUG
 	xerror("jslib:Can't connect socket.\n");
 #endif
