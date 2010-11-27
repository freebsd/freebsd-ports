$FreeBSD$

Fix bug with --one-file-system and --listed-incremental.

--- src/names.c.orig	2010-10-24 20:07:55.000000000 +0200
+++ src/names.c	2010-11-27 21:11:20.000000000 +0100
@@ -360,8 +360,6 @@ name_next_elt (int change_dirs)
 	{
 	  if (unquote_option)
 	    unquote_string (name_buffer);
-	  if (incremental_option)
-	    register_individual_file (name_buffer);
 	  entry.type = ep->type;
 	  entry.v.name = name_buffer;
 	  return &entry;
