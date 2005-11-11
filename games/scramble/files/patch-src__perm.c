--- src/perm.c.orig	Sun Mar 27 03:45:59 2005
+++ src/perm.c	Thu Nov 10 05:23:00 2005
@@ -149,11 +149,11 @@
  ****************************************************/
 static void resize()
 {
+        struct node ** old_table = dictionary;
 	unsigned int a;
         size_t old_size = sizeOfTable, i;
         sizeOfTable *= 2;
         numOfEntries = 0;
-        struct node ** old_table = dictionary;
 
         dictionary = (struct node **)malloc(sizeof(struct node *) * sizeOfTable);
         if(!dictionary) {
