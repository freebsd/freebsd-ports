--- print-tree.c.orig	Thu Jun 15 04:56:40 1995
+++ print-tree.c	Mon Mar 20 13:29:11 2000
@@ -82,7 +82,7 @@
   if (indent > 0)
     fprintf (file, " ");
   fprintf (file, "%s <%s ", prefix, tree_code_name[(int) TREE_CODE (node)]);
-  fprintf (file, HOST_PTR_PRINTF, (HOST_WIDE_INT) node);
+  fprintf (file, HOST_PTR_PRINTF, (void *) node);
 
   if (class == 'd')
     {
@@ -259,7 +259,7 @@
 
   /* Print the slot this node is in, and its code, and address.  */
   fprintf (file, "%s <%s ", prefix, tree_code_name[(int) TREE_CODE (node)]);
-  fprintf (file, HOST_PTR_PRINTF, (HOST_WIDE_INT) node);
+  fprintf (file, HOST_PTR_PRINTF, (void *) node);
 
   /* Print the name, if any.  */
   if (class == 'd')
@@ -456,7 +456,7 @@
 	    {
 	      fprintf (file, "saved-insns ");
 	      fprintf (file, HOST_PTR_PRINTF,
- 		       (HOST_WIDE_INT) DECL_SAVED_INSNS (node));
+		       (void *) DECL_SAVED_INSNS (node));
 	    }
 	}
 
