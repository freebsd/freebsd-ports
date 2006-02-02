Index: syntax.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/syntax.c,v
retrieving revision 1.25
retrieving revision 1.26
diff -u -r1.25 -r1.26
--- src/syntax.c	2005/11/25 01:42:06	1.25
+++ src/syntax.c	2005/12/18 22:55:52	1.26
@@ -613,7 +613,7 @@
 {
   *multi_p_out = 1;
   /* !!#### get this right */
-  return Spunct;
+  return Sword;
 }
 
 #endif
@@ -2296,8 +2296,8 @@
   if (!EQ (table, Vstandard_syntax_table) && !NILP (Vstandard_syntax_table))
     map_char_table (Vstandard_syntax_table, &range,
 		    copy_if_not_already_present, LISP_TO_VOID (mirrortab));
-  /* The resetting made the default be Qnil.  Put it back to Spunct. */
-  set_char_table_default (mirrortab, make_int (Spunct));
+  /* The resetting made the default be Qnil.  Put it back to Sword. */
+  set_char_table_default (mirrortab, make_int (Sword));
   XCHAR_TABLE (mirrortab)->dirty = 0;
 }
 
@@ -2419,7 +2419,7 @@
 							Smax);
   staticpro (&Vsyntax_designator_chars_string);
 
-  set_char_table_default (Vstandard_syntax_table, make_int (Spunct));
+  set_char_table_default (Vstandard_syntax_table, make_int (Sword));
 
   for (i = 0; i <= 32; i++)	/* Control 0 plus SPACE */
     Fput_char_table (make_char (i), make_int (Swhitespace),
