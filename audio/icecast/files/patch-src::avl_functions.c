--- src/avl_functions.c
+++ src/avl_functions.c
@@ -307,7 +307,7 @@
 	}
 
 	snprintf(s1, BUFSIZE, "%s:%d", dir1->host, dir1->port);
-	snprintf(s2, "%s:%d", dir2->host, dir2->port);
+	snprintf(s2, BUFSIZE, "%s:%d", dir2->host, dir2->port);
 
 	return compare_strings (s1, s2, param);
 }
