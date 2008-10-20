--- lib.c.orig	2007-10-22 18:17:52.000000000 -0500
+++ lib.c	2008-07-07 09:38:58.000000000 -0500
@@ -59,7 +59,7 @@
 {
 	if ( (record = (char *) malloc(n)) == NULL
 	  || (fields = (char *) malloc(n+1)) == NULL
-	  || (fldtab = (Cell **) malloc((nfields+1) * sizeof(Cell *))) == NULL
+	  || (fldtab = (Cell **) calloc((nfields+1), sizeof(Cell *))) == NULL
 	  || (fldtab[0] = (Cell *) malloc(sizeof(Cell))) == NULL )
 		FATAL("out of space for $0 and fields");
 	*fldtab[0] = dollar0;
@@ -78,7 +78,7 @@
 		if (fldtab[i] == NULL)
 			FATAL("out of space in makefields %d", i);
 		*fldtab[i] = dollar1;
-		sprintf(temp, "%d", i);
+		snprintf(temp, sizeof temp, "%d", i);
 		fldtab[i]->nval = tostring(temp);
 	}
 }
@@ -226,7 +226,7 @@
 	char *s, temp[50];
 	extern Array *ARGVtab;
 
-	sprintf(temp, "%d", n);
+	snprintf(temp, sizeof temp, "%d", n);
 	x = setsymtab(temp, "", 0.0, STR, ARGVtab);
 	s = getsval(x);
 	   dprintf( ("getargv(%d) returns |%s|\n", n, s) );
