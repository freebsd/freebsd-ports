--- ../../j2se/src/solaris/native/java/net/PlainDatagramSocketImpl.c.orig	Tue Mar 11 10:43:29 2003
+++ ../../j2se/src/solaris/native/java/net/PlainDatagramSocketImpl.c	Tue Mar 11 10:43:24 2003
@@ -2034,9 +2034,7 @@
 	/* 
 	 * Join the multicast group.
 	 */
-// XXXBSD: fix for BSD (re-implement with KAME ?)
-//	if (JVM_SetSockOpt(fd, IPPROTO_IP, (join ? IP_ADD_MEMBERSHIP:IP_DROP_MEMBERSHIP),
-	if (JVM_SetSockOpt(fd, IPPROTO_IP, (join ? 1 : 0),
+	if (JVM_SetSockOpt(fd, IPPROTO_IP, (join ? IP_ADD_MEMBERSHIP:IP_DROP_MEMBERSHIP),
 		           (char *) &mname, mname_len) < 0) {
 
 	    /*
