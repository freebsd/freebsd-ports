--- gliv.c.orig	Tue Jun 12 14:40:17 2001
+++ gliv.c	Wed Jun 13 19:42:54 2001
@@ -120,37 +120,6 @@
 }
 
 /***************************************
- *  Adds a filename to the list. This  *
- *function is only used by ftw when the*
- *	    -R flag is given.	       *
- ***************************************/
-static int add_to_list(const char *file, const struct stat *st, int flag)
-{
-    if (flag == FTW_F) {
-	/* It is not a directory, we don't care if it is an image or not. */
-	total++;
-	names = realloc(names, total * sizeof(char *));
-	names[total - 1] = strdup(file);
-    }
-    return 0;
-}
-
-/***************************************
- *  Recursively adds all files to the  *
- * list by descending directories. The *
- * image list is the variable 'names'. *
- ***************************************/
-static void build_image_list(char **array, unsigned int nb)
-{
-    unsigned int i;
-
-    for (i = 0; i < nb; i++) {
-	ftw(array[i], add_to_list, 8);
-	free(array[i]);
-    }
-}
-
-/***************************************
  *   Sets global variables according   *
  *     to  command-line arguments.     *
  ***************************************/
@@ -166,13 +135,8 @@
     rt.info = args->info_flag;
     rt.maximize = args->maximize_flag;
 
-    if (args->recursive_flag) {
-	build_image_list(args->inputs, args->inputs_num);
-	free(args->inputs);
-    } else {
 	total = args->inputs_num;
 	names = args->inputs;
-    }
 
     if (total < 2)
 	/* Don't use a thread for only one image. */
