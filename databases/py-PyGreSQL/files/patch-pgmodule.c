--- pgmodule.c~	Tue Jan 13 13:29:57 2004
+++ pgmodule.c	Sat Aug 28 16:41:56 2004
@@ -27,10 +27,19 @@
  */
 
 #include <Python.h>
-#include "postgres.h"
+
+/* defines snatched from "catalog/pg_type.h" */
+#define INT2OID 21
+#define INT4OID 23
+#define INT8OID 20
+#define OIDOID  26
+#define FLOAT4OID 700
+#define FLOAT8OID 701
+#define NUMERICOID 1700
+#define CASHOID 790
+
 #include "libpq-fe.h"
 #include "libpq/libpq-fs.h"
-#include "catalog/pg_type.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
