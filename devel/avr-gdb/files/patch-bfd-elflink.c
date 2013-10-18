--- bfd/elflink.c.orig
+++ bfd/elflink.c
@@ -12456,7 +12456,7 @@
 		   abfd, sec);
 	      else if (sec->size != 0)
 		{
-		  bfd_byte *sec_contents, *l_sec_contents;
+		  bfd_byte *sec_contents = NULL, *l_sec_contents = NULL;
 
 		  if (!bfd_malloc_and_get_section (abfd, sec, &sec_contents))
 		    (*_bfd_error_handler)
