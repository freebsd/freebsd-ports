--- dms.c.orig	Sun Nov  1 18:59:47 1998
+++ dms.c	Fri Aug 11 13:23:07 2006
@@ -485,7 +485,7 @@
 else
 	printf( "Illegal input format\n"  );
 printf( ") ? ");
-gets(s);
+fgets(s, 40, stdin);
 if( s[0] != '\0' )
 	sscanf( s, format, num );
 return(0);
