--- src/socket.c.orig	2021-10-17 13:36:53 UTC
+++ src/socket.c
@@ -54,6 +54,7 @@ static int try_sk_from_env(int fd, const struct addrin
 		return -1;
 	if (intf == nullptr)
 		return fd;
+#ifdef SO_BINDTODEVICE
 	char ifname[32];
 	optlen = sizeof(ifname);
 	ret = getsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, ifname, &optlen);
@@ -65,6 +66,7 @@ static int try_sk_from_env(int fd, const struct addrin
 		ifname[sizeof(ifname)-1] = '\0';
 	if (strcmp(intf, ifname) != 0)
 		return -1;
+#endif
 	return fd;
 }
 
