--- srvrsnpp.c.orig	2008-10-20 10:30:57.539127452 -0400
+++ srvrsnpp.c	2008-10-20 10:35:43.096529509 -0400
@@ -1066,7 +1066,12 @@
 
 		fromhost(&request);
 
-		ptr = eval_user(&request);
+		/*
+		** If we aren't doing an ident request, don't ask
+		** TCP Wrappers to do it either
+		*/
+		if (IdentTimeout) ptr = eval_user(&request);
+		else ptr = NULL;
 
 		if (ptr && strcmp(ptr, STRING_UNKNOWN) != 0)
 			p->ident = strdup(ptr);
