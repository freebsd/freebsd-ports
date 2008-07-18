--- src/query.c.orig	2008-04-19 21:17:23.000000000 +0200
+++ src/query.c	2008-07-18 16:32:13.000000000 +0200
@@ -577,7 +577,7 @@ static int string_query(query_node_t* qu
 	}
 	
     case qot_contains:
-	return (int) strcasestr(ts, query->right.str); /* returns null if not found */
+	return !!strcasestr(ts, query->right.str); /* returns null if not found */
 
     default:
 	DPRINTF(E_LOG,L_QRY,"Illegal query type: %d\n", query->type);
