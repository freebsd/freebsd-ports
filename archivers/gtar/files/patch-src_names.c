$FreeBSD$

Fix an instance of use-after-free(), from upstream.

--- src/names.c.orig	2010-03-27 21:57:39.000000000 +0100
+++ src/names.c	2010-03-27 21:58:02.000000000 +0100
@@ -950,6 +950,7 @@ collect_and_sort_names (void)
 		{
 		  if (p->child)
 		    rebase_child_list (p->child, name);
+		  hash_delete (nametab, name);
 		  /* FIXME: remove_directory (p->caname); ? */
 		  remname (p);
 		  free_name (p);
