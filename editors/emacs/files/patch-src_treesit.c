--- src/treesit.c.orig	2025-07-05 09:56:00 UTC
+++ src/treesit.c
@@ -415,17 +415,17 @@ static Lisp_Object Vtreesit_str_plus;
 static Lisp_Object Vtreesit_str_question_mark;
 static Lisp_Object Vtreesit_str_star;
 static Lisp_Object Vtreesit_str_plus;
-static Lisp_Object Vtreesit_str_pound_equal;
-static Lisp_Object Vtreesit_str_pound_match;
-static Lisp_Object Vtreesit_str_pound_pred;
+static Lisp_Object Vtreesit_str_pound_eq_question_mark;
+static Lisp_Object Vtreesit_str_pound_match_question_mark;
+static Lisp_Object Vtreesit_str_pound_pred_question_mark;
 static Lisp_Object Vtreesit_str_open_bracket;
 static Lisp_Object Vtreesit_str_close_bracket;
 static Lisp_Object Vtreesit_str_open_paren;
 static Lisp_Object Vtreesit_str_close_paren;
 static Lisp_Object Vtreesit_str_space;
-static Lisp_Object Vtreesit_str_equal;
-static Lisp_Object Vtreesit_str_match;
-static Lisp_Object Vtreesit_str_pred;
+static Lisp_Object Vtreesit_str_eq_question_mark;
+static Lisp_Object Vtreesit_str_match_question_mark;
+static Lisp_Object Vtreesit_str_pred_question_mark;
 static Lisp_Object Vtreesit_str_empty;
 
 /* This is the limit on recursion levels for some tree-sitter
@@ -632,6 +632,22 @@ treesit_load_language_push_for_each_suffix (Lisp_Objec
     }
 }
 
+/* This function is a compatibility shim.  Tree-sitter 0.25 introduced
+   ts_language_abi_version as a replacement for ts_language_version, and
+   tree-sitter 0.26 removed ts_language_version.  Here we use the fact
+   that 0.25 bumped TREE_SITTER_LANGUAGE_VERSION to 15, to use the new
+   function instead of the old one, when Emacs is compiled against
+   tree-sitter version 0.25 or newer.  */
+static uint32_t
+treesit_language_abi_version (const TSLanguage *ts_lang)
+{
+#if TREE_SITTER_LANGUAGE_VERSION >= 15
+  return ts_language_abi_version (ts_lang);
+#else
+  return ts_language_version (ts_lang);
+#endif
+}
+
 /* Load the dynamic library of LANGUAGE_SYMBOL and return the pointer
    to the language definition.
 
@@ -746,7 +762,7 @@ treesit_load_language (Lisp_Object language_symbol,
     {
       *signal_symbol = Qtreesit_load_language_error;
       *signal_data = list2 (Qversion_mismatch,
-			    make_fixnum (ts_language_version (lang)));
+			    make_fixnum (treesit_language_abi_version (lang)));
       return NULL;
     }
   return lang;
@@ -817,7 +833,7 @@ Return nil if a grammar library for LANGUAGE is not av
 						       &signal_data);
       if (ts_language == NULL)
 	return Qnil;
-      uint32_t version =  ts_language_version (ts_language);
+      uint32_t version =  treesit_language_abi_version (ts_language);
       return make_fixnum((ptrdiff_t) version);
     }
 }
@@ -2604,12 +2620,12 @@ See Info node `(elisp)Pattern Matching' for detailed e
     return Vtreesit_str_star;
   if (BASE_EQ (pattern, QCplus))
     return Vtreesit_str_plus;
-  if (BASE_EQ (pattern, QCequal))
-    return Vtreesit_str_pound_equal;
-  if (BASE_EQ (pattern, QCmatch))
-    return Vtreesit_str_pound_match;
-  if (BASE_EQ (pattern, QCpred))
-    return Vtreesit_str_pound_pred;
+  if (BASE_EQ (pattern, QCequal) || BASE_EQ (pattern, QCeq_q))
+    return Vtreesit_str_pound_eq_question_mark;
+  if (BASE_EQ (pattern, QCmatch) || BASE_EQ (pattern, QCmatch_q))
+    return Vtreesit_str_pound_match_question_mark;
+  if (BASE_EQ (pattern, QCpred) || BASE_EQ (pattern, QCpred_q))
+    return Vtreesit_str_pound_pred_question_mark;
   Lisp_Object opening_delimeter
     = VECTORP (pattern)
       ? Vtreesit_str_open_bracket : Vtreesit_str_open_paren;
@@ -2640,7 +2656,9 @@ A PATTERN in QUERY can be
     :*
     :+
     :equal
+    :eq?
     :match
+    :match?
     (TYPE PATTERN...)
     [PATTERN...]
     FIELD-NAME:
@@ -2803,7 +2821,7 @@ treesit_predicate_equal (Lisp_Object args, struct capt
   return !NILP (Fstring_equal (text1, text2));
 }
 
-/* Handles predicate (#match "regexp" @node).  Return true if "regexp"
+/* Handles predicate (#match? "regexp" @node).  Return true if "regexp"
    matches the text spanned by @node; return false otherwise.
    Matching is case-sensitive.  If everything goes fine, don't touch
    SIGNAL_DATA; if error occurs, set it to a suitable signal data.  */
@@ -2813,26 +2831,24 @@ treesit_predicate_match (Lisp_Object args, struct capt
 {
   if (list_length (args) != 2)
     {
-      *signal_data = list2 (build_string ("Predicate `match' requires two "
+      *signal_data = list2 (build_string ("Predicate `match?' requires two "
 					  "arguments but got"),
 			    Flength (args));
       return false;
     }
-  Lisp_Object regexp = XCAR (args);
-  Lisp_Object capture_name = XCAR (XCDR (args));
+  Lisp_Object arg1 = XCAR (args);
+  Lisp_Object arg2 = XCAR (XCDR (args));
+  Lisp_Object regexp = SYMBOLP (arg2) ? arg1 : arg2;
+  Lisp_Object capture_name = SYMBOLP (arg2) ? arg2 : arg1;
 
-  /* It's probably common to get the argument order backwards.  Catch
-     this mistake early and show helpful explanation, because Emacs
-     loves you.  (We put the regexp first because that's what
-     string-match does.)  */
-  if (!STRINGP (regexp))
-    xsignal1 (Qtreesit_query_error,
-	      build_string ("The first argument to `match' should "
-		            "be a regexp string, not a capture name"));
-  if (!SYMBOLP (capture_name))
-    xsignal1 (Qtreesit_query_error,
-	      build_string ("The second argument to `match' should "
-		            "be a capture name, not a string"));
+  if (!STRINGP (regexp) || !SYMBOLP (capture_name))
+    {
+      *signal_data = list2 (build_string ("Predicate `match?' takes a regexp "
+	                                  "and a node capture (order doesn't "
+					  "matter), but got"),
+			    Flength (args));
+      return false;
+    }
 
   Lisp_Object node = Qnil;
   if (!treesit_predicate_capture_name_to_node (capture_name, captures, &node,
@@ -2916,11 +2932,11 @@ treesit_eval_predicates (struct capture_range captures
       Lisp_Object predicate = XCAR (tail);
       Lisp_Object fn = XCAR (predicate);
       Lisp_Object args = XCDR (predicate);
-      if (!NILP (Fstring_equal (fn, Vtreesit_str_equal)))
+      if (!NILP (Fstring_equal (fn, Vtreesit_str_eq_question_mark)))
 	pass &= treesit_predicate_equal (args, captures, signal_data);
-      else if (!NILP (Fstring_equal (fn, Vtreesit_str_match)))
+      else if (!NILP (Fstring_equal (fn, Vtreesit_str_match_question_mark)))
 	pass &= treesit_predicate_match (args, captures, signal_data);
-      else if (!NILP (Fstring_equal (fn, Vtreesit_str_pred)))
+      else if (!NILP (Fstring_equal (fn, Vtreesit_str_pred_question_mark)))
 	pass &= treesit_predicate_pred (args, captures, signal_data);
       else
 	{
@@ -4192,8 +4208,11 @@ syms_of_treesit (void)
   DEFSYM (QCstar, ":*");
   DEFSYM (QCplus, ":+");
   DEFSYM (QCequal, ":equal");
+  DEFSYM (QCeq_q, ":eq?");
   DEFSYM (QCmatch, ":match");
+  DEFSYM (QCmatch_q, ":match?");
   DEFSYM (QCpred, ":pred");
+  DEFSYM (QCpred_q, ":pred?");
 
   DEFSYM (Qnot_found, "not-found");
   DEFSYM (Qsymbol_error, "symbol-error");
@@ -4324,12 +4343,12 @@ the symbol of that THING.  For example, (or sexp sente
   Vtreesit_str_star = build_pure_c_string ("*");
   staticpro (&Vtreesit_str_plus);
   Vtreesit_str_plus = build_pure_c_string ("+");
-  staticpro (&Vtreesit_str_pound_equal);
-  Vtreesit_str_pound_equal = build_pure_c_string ("#equal");
-  staticpro (&Vtreesit_str_pound_match);
-  Vtreesit_str_pound_match = build_pure_c_string ("#match");
-  staticpro (&Vtreesit_str_pound_pred);
-  Vtreesit_str_pound_pred = build_pure_c_string ("#pred");
+  staticpro (&Vtreesit_str_pound_eq_question_mark);
+  Vtreesit_str_pound_eq_question_mark = build_pure_c_string ("#eq?");
+  staticpro (&Vtreesit_str_pound_match_question_mark);
+  Vtreesit_str_pound_match_question_mark = build_pure_c_string ("#match?");
+  staticpro (&Vtreesit_str_pound_pred_question_mark);
+  Vtreesit_str_pound_pred_question_mark = build_pure_c_string ("#pred?");
   staticpro (&Vtreesit_str_open_bracket);
   Vtreesit_str_open_bracket = build_pure_c_string ("[");
   staticpro (&Vtreesit_str_close_bracket);
@@ -4340,12 +4359,12 @@ the symbol of that THING.  For example, (or sexp sente
   Vtreesit_str_close_paren = build_pure_c_string (")");
   staticpro (&Vtreesit_str_space);
   Vtreesit_str_space = build_pure_c_string (" ");
-  staticpro (&Vtreesit_str_equal);
-  Vtreesit_str_equal = build_pure_c_string ("equal");
-  staticpro (&Vtreesit_str_match);
-  Vtreesit_str_match = build_pure_c_string ("match");
-  staticpro (&Vtreesit_str_pred);
-  Vtreesit_str_pred = build_pure_c_string ("pred");
+  staticpro (&Vtreesit_str_eq_question_mark);
+  Vtreesit_str_eq_question_mark = build_pure_c_string ("eq?");
+  staticpro (&Vtreesit_str_match_question_mark);
+  Vtreesit_str_match_question_mark = build_pure_c_string ("match?");
+  staticpro (&Vtreesit_str_pred_question_mark);
+  Vtreesit_str_pred_question_mark = build_pure_c_string ("pred?");
   staticpro (&Vtreesit_str_empty);
   Vtreesit_str_empty = build_pure_c_string ("");
 
