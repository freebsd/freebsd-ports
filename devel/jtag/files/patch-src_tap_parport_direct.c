--- src/tap/parport/direct.c.orig	Sat Aug  5 23:51:32 2006
+++ src/tap/parport/direct.c	Sat Aug  5 23:57:38 2006
@@ -46,28 +46,14 @@
 static __inline int
 ioperm( unsigned long from, unsigned long num, int permit )
 {
-	u_long ports[32];
-	u_long i;
-
-	if (i386_get_ioperm( ports ) == -1)
-		return -1;
-
-	for (i = from; i < (from + num); i++)
-		if (permit)
-			ports[i / 32] &= ~(1 << (i % 32));
-		else
-			ports[i / 32] |= (1 << (i % 32));
-
-	if (i386_set_ioperm( ports ) == -1)
-		return -1;
-
+	return i386_set_ioperm(from, num, permit);
 	return 0;
 }
 
 static __inline int
 iopl( int level )
 {
-	return i386_iopl( level );
+	return 0;
 }
 
 static __inline unsigned char
