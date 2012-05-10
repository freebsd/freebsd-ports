--- tdbcodbc/generic/tdbcodbc.c,orig	2011-08-01 16:50:38.000000000 +0200
+++ tdbcodbc/generic/tdbcodbc.c	2012-05-09 10:52:56.000000000 +0200
@@ -4092,10 +4092,10 @@
     SQLLEN colAllocLen = BUFSIZE * sizeof(SQLWCHAR);
 				/* Current allocated size of the buffer,
 				 * in bytes */
-    SQLLEN colLen;		/* Actual size of the return value, in bytes */
-    SQLINTEGER colLong;		/* Integer value of the column */
-    SQLBIGINT colWide;		/* Wide-integer value of the column */
-    SQLDOUBLE colDouble;	/* Double value of the column */
+    SQLLEN colLen = 0;		/* Actual size of the return value, in bytes */
+    SQLINTEGER colLong = 0L;	/* Integer value of the column */
+    SQLBIGINT colWide = 0;	/* Wide-integer value of the column */
+    SQLDOUBLE colDouble = 0.0;	/* Double value of the column */
     Tcl_DString colDS;		/* Column expressed as a Tcl_DString */
     Tcl_Obj* colObj;		/* Column expressed as a Tcl_Obj */
     SQLRETURN rc;		/* ODBC result code */
