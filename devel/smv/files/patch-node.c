--- node.c
+++ node.c
@@ -609,7 +609,7 @@
 node_ptr n;
 int col;
 {
-  char *buf = (char *)malloc(option_print_node_length + 1);
+  char *buf = (char *)smv_malloc(option_print_node_length + 1);
   int c,p;
   if(buf == NULL) rpterr("Out of memory");
   buf[0] = 0;
@@ -623,7 +623,7 @@
   }
   fprintf(stream,"%s",buf);
   if(!c)fprintf(stream,"...");
-  free(buf);
+  smv_free(buf);
   return(col + p);
 }
