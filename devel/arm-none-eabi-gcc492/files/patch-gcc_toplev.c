--- gcc/toplev.c.orig	2018-07-13 22:48:32 UTC
+++ gcc/toplev.c
@@ -1041,7 +1041,7 @@ output_stack_usage (void)
 	}
 
       fprintf (stack_usage_file,
-	       "%s:%d:%d:%s\t"HOST_WIDE_INT_PRINT_DEC"\t%s\n",
+	       "%s:%d:%d:%s\t" HOST_WIDE_INT_PRINT_DEC "\t%s\n",
 	       lbasename (loc.file),
 	       loc.line,
 	       loc.column,
