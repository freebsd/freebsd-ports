--- sysdeps/freebsd/netload.c.orig	Mon Nov 25 12:51:03 2002
+++ sysdeps/freebsd/netload.c	Mon Nov 25 12:51:30 2002
@@ -109,7 +109,7 @@
 			  sizeof (ifnet)) != sizeof (ifnet))
 		    glibtop_error_io_r (server, "kvm_read (ifnetaddr)");
 
-#if defined(__FreeBSD__) || defined(__bsdi__)
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 501113)) || defined(__bsdi__)
 	    if (kvm_read (server->machine.kd, (u_long) ifnet.if_name,
 			  tname, 16) != 16)
 		    glibtop_error_io_r (server, "kvm_read (if_name)");
