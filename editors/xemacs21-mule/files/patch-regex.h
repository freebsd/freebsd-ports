Index: src/regex.h
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/regex.h,v
retrieving revision 1.7.2.2
retrieving revision 1.7.2.1
diff -u -r1.7.2.2 -r1.7.2.1
--- src/regex.h	2004/09/23 03:03:47	1.7.2.2
+++ src/regex.h	2001/04/16 09:24:54	1.7.2.1
@@ -358,14 +358,9 @@
            when it is matched.  */
   RE_TRANSLATE_TYPE translate;
 
-	/* Number of returnable groups found by the compiler. (This does
-           not count shy groups.) */
+	/* Number of subexpressions found by the compiler.  */
   Element_count re_nsub;
 
-	/* Total number of groups found by the compiler. (Including
-	   shy ones.) */
-  Element_count re_ngroups;
-
         /* Zero if this pattern cannot match the empty string, one else.
            Well, in truth it's used only in `re_search_2', to see
            whether or not we should use the fastmap, so we don't set
@@ -399,12 +394,6 @@
 
         /* If true, an anchor at a newline matches.  */
   unsigned newline_anchor : 1;
-
-	/* Mapping between back references and groups (may not be
-	   equivalent with shy groups). */
-  int *external_to_internal_register;
-
-  int external_to_internal_register_size;
 
 /* [[[end pattern_buffer]]] */
 };
