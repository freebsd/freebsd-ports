--- src/dict.c.orig	Sun Apr 11 01:22:40 2004
+++ src/dict.c	Thu Nov 10 05:18:25 2005
@@ -84,11 +84,15 @@
  ****************************************************/
 static void resize()
 {
+	struct node *d;
+	struct node *t;
+        struct node ** old_table = dictionary;
 	unsigned int a;
+	size_t i;
         size_t old_size = sizeOfTable;
-        sizeOfTable *= 2;
         numOfEntries = 0;
-        struct node ** old_table = dictionary;
+
+        sizeOfTable *= 2;
 
         dictionary = (struct node **)malloc(sizeof(struct node *) * sizeOfTable);
         if(!dictionary) {
@@ -99,8 +103,9 @@
 
         /* now copy old table into new table
 	   and delete the old one */
-        for(size_t i = 0; i < old_size; i++) {
-		struct node * d = NULL, * t = old_table[i];
+        for(i = 0; i < old_size; i++) {
+		d = NULL;
+		t = old_table[i];
 		while(t) {
 			addToDictionary(t->word);
 			d = t;
@@ -157,10 +162,11 @@
 {
 	FILE * input = NULL;
 	unsigned int a;
+	size_t i;
 
 	/* Delete the old dictionary if one exists */
 	if(dictionary) {
-		for(size_t i = 0; i < sizeOfTable; i++) {
+		for(i = 0; i < sizeOfTable; i++) {
 			struct node * t = dictionary[i];
 			while(t) {
 				free(t->word);
