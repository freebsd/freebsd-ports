--- linuxdoom-1.10/i_net.c~	Mon Dec 22 21:37:46 1997
+++ linuxdoom-1.10/i_net.c	Mon Jul 22 10:06:25 2002
@@ -23,6 +23,7 @@
 static const char
 rcsid[] = "$Id: patch-ae,v 1.1.1.1 1998/12/14 21:18:25 jmz Exp $";
 
+#include <sys/types.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
@@ -51,6 +52,7 @@
 
 
 
+#if 0
 // For some odd reason...
 #define ntohl(x) \
         ((unsigned long int)((((unsigned long int)(x) & 0x000000ffU) << 24) | \
@@ -64,6 +66,7 @@
 	  
 #define htonl(x) ntohl(x)
 #define htons(x) ntohs(x)
+#endif
 
 void	NetSend (void);
 boolean NetListen (void);
@@ -73,7 +76,7 @@
 // NETWORKING
 //
 
-int	DOOMPORT =	(IPPORT_USERRESERVED +0x1d );
+int	DOOMPORT =	5029;
 
 int			sendsocket;
 int			insocket;
