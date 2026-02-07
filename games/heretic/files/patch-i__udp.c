--- i_udp.c.orig	2000-05-01 10:24:52 UTC
+++ i_udp.c
@@ -31,7 +31,7 @@
 
 boolean server = 0;
 
-static int DOOMPORT = (IPPORT_USERRESERVED +0x1d );
+static int DOOMPORT = (5000 +0x1d );
 
 /* static int sendsocket; */
 /* static int insocket; */
