--- hash.c.orig	2014-08-07 15:18:25.000000000 +0200
+++ hash.c	2014-08-07 15:19:06.000000000 +0200
@@ -239,14 +239,14 @@
 
 	for( i = nel; i > 0; i-- )
 	{
-		if( here = ( *tab++ != (ITEM *)0 ) )
+		if( ( here = ( *tab++ != (ITEM *)0 ) ) )
 			count++;
 		if( here && !run )
 			sets++;
 		run = here;
 	}
 
-	printf( "%s table: %d+%d+%d (%dK+%dK) items+table+hash, %f density\n",
+	printf( "%s table: %d+%d+%d (%dK+%zuK) items+table+hash, %f density\n",
 		hp->name, 
 		count, 
 		hp->items.nel,
