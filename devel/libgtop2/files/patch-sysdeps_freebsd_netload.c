--- sysdeps/freebsd/netload.c.orig	Sun Jan 12 21:40:04 2003
+++ sysdeps/freebsd/netload.c	Sat Feb  8 23:52:49 2003
@@ -83,6 +83,7 @@
     u_long ifnetaddr, ifnetfound, ifaddraddr;
     struct sockaddr *sa;
     char tname [16];
+    char temp [16];
 
     union {
 	struct ifaddr ifa;
@@ -109,7 +109,7 @@
 			  sizeof (ifnet)) != sizeof (ifnet))
 		    glibtop_error_io_r (server, "kvm_read (ifnetaddr)");
 
-#if defined(__FreeBSD__) || defined(__bsdi__)
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 501113)) || defined(__bsdi__)
 	    if (kvm_read (server->machine.kd, (u_long) ifnet.if_name,
 			  tname, 16) != 16)
 		    glibtop_error_io_r (server, "kvm_read (if_name)");
@@ -113,6 +114,9 @@
 	    if (kvm_read (server->machine.kd, (u_long) ifnet.if_name,
 			  tname, 16) != 16)
 		    glibtop_error_io_r (server, "kvm_read (if_name)");
+	    snprintf(temp, (15 - strlen(tname)), "%d", ifnet.if_unit);
+	    strcat(tname, temp);
+	    tname [15] = 0;
 #else
 	    strncpy (tname, ifnet.if_xname, 16);
 	    tname [15] = 0;
