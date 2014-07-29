--- src/ebview-client.c.orig	Sat Apr 26 21:59:23 2003
+++ src/ebview-client.c	Fri May  2 20:14:43 2003
@@ -30,7 +30,7 @@
 	/* The total length of the address includes the sun_family 
 	   element */
 
-#ifdef __FreeBSD__
+#ifndef HAVE_GETOPT_LONG
         addrLength = sizeof(address.sun_len) + sizeof(address.sun_family) + strlen(address.sun_path) + 1;
         address.sun_len = addrLength;
 #else
