
$FreeBSD$

--- conn.c.orig
+++ conn.c
@@ -321,7 +321,7 @@
 				break;
 			if( ( t = http_header( conn->http, "location:" ) ) == NULL )
 				return( 0 );
-			sscanf( t, "%s", s );
+			sscanf( t, "%255s", s );
 			if( strstr( s, "://" ) == NULL)
 			{
 				sprintf( conn->http->headers, "%s%s",
