--- udb_ochunk.c.orig	Sun Oct 25 23:58:06 1998
+++ udb_ochunk.c	Tue Oct 28 01:01:14 2003
@@ -11,7 +11,7 @@
 #include	"mudconf.h"
 
 #ifdef VMS
-#include	<malloc.h>
+#include	<stdlib.h>
 #include        <types.h>
 #include        <file.h>
 #include        <unixio.h>
@@ -19,7 +19,7 @@
 #else
 #ifndef NEXT
 #ifndef MALLOC_IN_STDLIB_H
-#include	<malloc.h>
+#include	<stdlib.h>
 #endif
 #endif /* NEXT */
 #include	<sys/param.h>
@@ -75,7 +75,7 @@
 
 	if ((dbp = gdbm_open(dbfile, block_size, GDBM_WRCREAT, 0600, gdbm_panic)) == (GDBM_FILE) 0) {
 		gdbm_error = (char *)gdbm_strerror(gdbm_errno);
-		logf(copen, dbfile, " ", (char *)-1, "\n", gdbm_error, "\n", (char *)0);
+		Logf(copen, dbfile, " ", (char *)-1, "\n", gdbm_error, "\n", (char *)0);
 		return (1);
 	}
 
@@ -130,7 +130,7 @@
 	
 	/* if the file is badly formatted, ret == Obj * 0 */
 	if ((ret = objfromFILE(dat.dptr)) == (Obj *) 0) {
-		logf("db_get: cannot decode ", nam, "\n", (char *)0);
+		Logf("db_get: cannot decode ", nam, "\n", (char *)0);
 		free(dat.dptr);
 		return NULL;
 	}
@@ -170,13 +170,13 @@
 	dat.dsize = nsiz;
 
 	if (objtoFILE(obj, dat.dptr) != 0) {
-		logf("db_put: can't save ", nam, " ", (char *)-1, "\n", (char *)0);
+		Logf("db_put: can't save ", nam, " ", (char *)-1, "\n", (char *)0);
 		free(dat.dptr);
 		return (1);
 	}
 
 	if (gdbm_store(dbp, key, dat, GDBM_REPLACE)) {
-		logf("db_put: can't gdbm_store ", nam, " ", (char *)-1, "\n", (char *)0);
+		Logf("db_put: can't gdbm_store ", nam, " ", (char *)-1, "\n", (char *)0);
 		free(dat.dptr);
 		return (1);
 	}
@@ -204,7 +204,7 @@
 	
 	/* drop key from db */
 	if (gdbm_delete(dbp, key)) {
-		logf("db_del: can't delete key ", nam, "\n", (char *)0);
+		Logf("db_del: can't delete key ", nam, "\n", (char *)0);
 		return (1);
 	}
 	return (0);
