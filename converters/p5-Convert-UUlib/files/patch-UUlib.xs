--- UUlib.xs.orig	Fri Dec  5 11:22:16 2003
+++ UUlib.xs	Fri Dec  5 11:22:30 2003
@@ -383,10 +383,11 @@ UUFNameFilter (fname)
 	char *	fname
 
 void
-UULoadFile (fname, id = 0, delflag = 0, int partno = -1)
+UULoadFile (fname, id = 0, delflag = 0, partno = -1)
 	char *	fname
 	char *	id
 	int	delflag
+	int partno
         PPCODE:
 	{	
 	        int count;
