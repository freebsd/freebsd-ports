--- server.c.orig	1998-03-04 18:59:19 UTC
+++ server.c
@@ -80,8 +80,7 @@ static long     sizes[MAXPACKET];
 static long     isizes[MAXPACKET];
 char            acceled[5];
 #endif
-struct control  controls[MAXROCKETS];
-static unsigned char Clientmap[5];
+static unsigned char Clientmap[MAXROCKETS];
 static int      Socket;
 /*static int      tbreak; */
 #define BUFFERSIZE 65536
