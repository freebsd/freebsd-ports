--- dbdimp.c.orig	Sun Feb 15 02:36:38 2004
+++ dbdimp.c	Fri Jun 11 22:32:17 2004
@@ -1,4 +1,4 @@
-/* $Id: dbdimp.c,v 1.44 2004/02/14 17:36:38 matt Exp $ */
+/* $Id: dbdimp.c,v 1.45 2004/03/16 19:08:22 matt Exp $ */
 
 #include "SQLiteXS.h"
 
@@ -294,8 +294,11 @@
 char *
 sqlite_decode(imp_dbh_t *imp_dbh, char *input, size_t *len)
 {
-  char *ret = malloc(*len);
-  char *swit = ret;
+  char *ret;
+  char *swit;
+
+  New(1, ret, *len, char);
+  swit = ret;
 
   while (*input) {
     switch (*input) {
