--- ./pgmecab.c.orig	2006-02-15 00:36:39.000000000 +0900
+++ ./pgmecab.c	2010-06-21 03:04:30.000000000 +0900
@@ -7,7 +7,9 @@
 
 #include "postgres.h"
 #include "fmgr.h"
-
+#ifdef PG_MODULE_MAGIC
+PG_MODULE_MAGIC;
+#endif
 #include "mecab.h"
 
 #include <stdio.h>
