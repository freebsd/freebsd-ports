--- cddb-slave2/cddb-slave.c.orig	Sat Mar  5 03:42:22 2005
+++ cddb-slave2/cddb-slave.c	Sat Mar  5 03:43:01 2005
@@ -572,6 +572,7 @@ do_query_response (ConnectionData *cd,
 		more = FALSE;
 		break;
 
+	case 210:
 	case 211:
 		/* Should this be 210 as well? */
 		cs_debug ("Multiple matches found\n<-- %s", response);
