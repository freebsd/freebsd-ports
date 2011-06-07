--- backend/genesys.c.orig	2011-06-07 13:06:00.000000000 +0200
+++ backend/genesys.c	2011-06-07 13:06:46.000000000 +0200
@@ -5436,7 +5436,7 @@
  * @param size maximum size of the range
  * @return a poiter to a valid range or NULL
  */
-static create_range(SANE_Fixed size)
+static SANE_Range *create_range(SANE_Fixed size)
 {
 SANE_Range *range=NULL;
 
