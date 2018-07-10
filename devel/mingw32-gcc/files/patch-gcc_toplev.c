--- gcc/toplev.c.orig	2013-03-28 08:29:51 UTC
+++ gcc/toplev.c
@@ -1025,7 +1025,7 @@ output_stack_usage (void)
 	id = raw_id;
 
       fprintf (stack_usage_file,
-	       "%s:%d:%d:%s\t"HOST_WIDE_INT_PRINT_DEC"\t%s\n",
+	       "%s:%d:%d:%s\t" HOST_WIDE_INT_PRINT_DEC "\t%s\n",
 	       lbasename (loc.file),
 	       loc.line,
 	       loc.column,
