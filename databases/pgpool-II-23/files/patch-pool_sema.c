Index: pool_sema.c
===================================================================
RCS file: /cvsroot/pgpool/pgpool-II/pool_sema.c,v
retrieving revision 1.4
diff -u -r1.4 pool_sema.c
--- pool_sema.c	29 Jan 2008 01:56:36 -0000	1.4
+++ pool_sema.c	29 Dec 2008 05:15:44 -0000
@@ -82,7 +82,7 @@
 
 	if (semId < 0)
 	{
-		pool_error("could not create semaphores: %s", strerror(errno));
+		pool_error("could not create %d semaphores: %s", numSems, strerror(errno));
 		return -1;
 	}
 
