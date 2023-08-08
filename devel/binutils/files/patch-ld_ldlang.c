--- ld/ldlang.c.orig	2023-01-13 16:00:00.000000000 -0800
+++ ld/ldlang.c	2023-05-13 21:48:06.006092000 -0700
@@ -649,7 +649,8 @@
 	 looking at the sections for this file.  */
 
       /* Find the correct node to append this section.  */
-      if (compare_section (sec->spec.sorted, section, (*tree)->section) < 0)
+      if (sec && sec->spec.sorted != none && sec->spec.sorted != by_none
+	  && compare_section (sec->spec.sorted, section, (*tree)->section) < 0)
 	tree = &((*tree)->left);
       else
 	tree = &((*tree)->right);
