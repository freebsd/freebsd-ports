RCS file: /cvs/src/src/ld/ldlang.c,v
retrieving revision 1.218
diff -u -p -r1.218 ldlang.c
--- ld/ldlang.c	17 May 2006 16:46:54 -0000	1.218
+++ ld/ldlang.c	19 May 2006 02:39:55 -0000
@@ -4198,7 +4198,8 @@ lang_size_sections_1
 		    /* If a loadable section is using the default memory
 		       region, and some non default memory regions were
 		       defined, issue an error message.  */
-		    if (!IGNORE_SECTION (os->bfd_section)
+		    if (!os->ignored
+			&& !IGNORE_SECTION (os->bfd_section)
 			&& ! link_info.relocatable
 			&& check_regions
 			&& strcmp (os->region->name,
