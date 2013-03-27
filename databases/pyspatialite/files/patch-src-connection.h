--- src/connection.h.bak	2012-10-25 19:40:06.000000000 +0200
+++ src/connection.h	2012-10-25 19:40:25.000000000 +0200
@@ -33,8 +33,6 @@
 #include "sqlite3.h"
 #include "spatialite.h"
 
-int spatialite_init(int verbose);
-
 typedef struct
 {
     PyObject_HEAD
