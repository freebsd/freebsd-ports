--- ircd/res.c.orig	2007-11-14 03:06:21.000000000 +0600
+++ ircd/res.c	2007-11-14 03:07:15.000000000 +0600
@@ -193,13 +193,13 @@
 #endif
 	r2ptr = old;
 	if (r2ptr->he.h_name)
-		MyFree((char *)r2ptr->he.h_name);
+		MyFree(r2ptr->he.h_name);
 	for (i = 0; i < MAXALIASES; i++)
 		if ((s = r2ptr->he.h_aliases[i]))
 			MyFree(s);
 	if (r2ptr->name)
 		MyFree(r2ptr->name);
-	MyFree((char *)r2ptr);
+	MyFree(r2ptr);
 
 	return;
 }
@@ -1505,7 +1505,7 @@
 		if (*cpp == cp)
 		    {
 			*cpp = cp->list_next;
-			MyFree((char *)cp);
+			MyFree(cp);
 			break;
 		    }
 	return cr;
@@ -1592,7 +1592,7 @@
 	    {
 		for (hashv = 0; hp->h_aliases[hashv]; hashv++)
 			MyFree(hp->h_aliases[hashv]);
-		MyFree((char *)hp->h_aliases);
+		MyFree(hp->h_aliases);
 	    }
 
 	/*
@@ -1601,11 +1601,11 @@
 	if (hp->h_addr_list)
 	    {
 		if (*hp->h_addr_list)
-			MyFree((char *)*hp->h_addr_list);
-		MyFree((char *)hp->h_addr_list);
+			MyFree(*hp->h_addr_list);
+		MyFree(hp->h_addr_list);
 	    }
 
-	MyFree((char *)ocp);
+	MyFree(ocp);
 
 	incache--;
 	cainfo.ca_dels++;
