--- tdbtool.c~	Tue Dec 11 04:45:47 2001
+++ tdbtool.c	Sun Aug 17 18:49:00 2003
@@ -169,23 +169,23 @@
 
 static void help(void)
 {
-	printf("
-tdbtool: 
-  create    dbname     : create a database
-  open      dbname     : open an existing database
-  erase                : erase the database
-  dump      dumpname   : dump the database as strings
-  insert    key  data  : insert a record
-  store     key  data  : store a record (replace)
-  show      key        : show a record by key
-  delete    key        : delete a record by key
-  list                 : print the database hash table and freelist
-  free                 : print the database freelist
-  1 | first            : print the first record
-  n | next             : print the next record
-  q | quit             : terminate
-  \\n                   : repeat 'next' command
-");
+	puts("");
+	puts("tdbtool: ");
+	puts("  create    dbname     : create a database");
+	puts("  open      dbname     : open an existing database");
+	puts("  erase                : erase the database");
+	puts("  dump      dumpname   : dump the database as strings");
+	puts("  insert    key  data  : insert a record");
+	puts("  store     key  data  : store a record (replace)");
+	puts("  show      key        : show a record by key");
+	puts("  delete    key        : delete a record by key");
+	puts("  list                 : print the database hash table and freelist");
+	puts("  free                 : print the database freelist");
+	puts("  1 | first            : print the first record");
+	puts("  n | next             : print the next record");
+	puts("  q | quit             : terminate");
+	puts("  \\n                   : repeat 'next' command");
+	puts("");
 }
 
 static void terror(char *why)
