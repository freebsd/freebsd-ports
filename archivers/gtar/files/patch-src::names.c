
$FreeBSD$

--- src/names.c	2002/06/01 21:08:46	1.1
+++ src/names.c	2002/06/01 21:09:16
@@ -549,6 +549,7 @@
   while (1)
     {
       struct name *cursor = namelist;
+      struct name *tmpnlp;
 
       if (!cursor)
 	return ! files_from_option;
@@ -572,6 +573,38 @@
 	      nametail = &namelist;
 	    }
 	  chdir_do (cursor->change_dir);
+	  if (fast_read_option)
+	    {
+	    /* remove the current entry, since we found a match */
+	      if (namelist->next == NULL)
+	        {
+	          /* the list contains one element */
+	          free(namelist);
+	          namelist = 0;
+	          nametail = &namelist;
+	          /* set a boolean to decide wether we started with a */
+	          /* non-empty  namelist, that was emptied */
+	          namelist_freed = 1;
+	        }
+	      else
+	        {
+	          if (cursor == namelist)
+	            {
+	              /* the first element is the one */
+	              tmpnlp = namelist->next;
+	              free(namelist);
+	              namelist = tmpnlp;
+	            }
+	          else
+	            {
+	              tmpnlp = namelist;
+	              while (tmpnlp->next != cursor)
+	                tmpnlp = tmpnlp->next;
+	              tmpnlp->next = cursor->next;
+	              free(cursor);
+	            }
+	        }
+	    }
   
 	  /* We got a match.  */
 	  return 1;
