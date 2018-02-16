--- ext/ripper/ripper.y.orig	2017-12-25 07:00:33 UTC
+++ ext/ripper/ripper.y
@@ -1983,18 +1983,10 @@ mlhs_node	: user_variable
 lhs		: user_variable
 		    {
 			$$ = assignable(var_field($1), 0, &@$);
-#if 0
-			if (!$$) $$ = new_begin(0, &@$);
-#endif
-
 		    }
 		| keyword_variable
 		    {
 			$$ = assignable(var_field($1), 0, &@$);
-#if 0
-			if (!$$) $$ = new_begin(0, &@$);
-#endif
-
 		    }
 		| primary_value '[' opt_call_args rbracket
 		    {
@@ -9957,11 +9949,13 @@ assignable_gen(struct parser_params *parser, ID id, NO
 #ifdef RIPPER
     ID id = get_id(lhs);
 # define assignable_result(x) (lhs)
+# define assignable_error() (lhs)
 # define parser_yyerror(parser, x) (lhs = assign_error_gen(parser, lhs))
 #else
 # define assignable_result(x) assignable_result0(x, location)
+# define assignable_error() new_begin(0, location)
 #endif
-    if (!id) return assignable_result(0);
+    if (!id) return assignable_error();
     switch (id) {
       case keyword_self:
 	yyerror0("Can't change the value of self");
@@ -10024,7 +10018,7 @@ assignable_gen(struct parser_params *parser, ID id, NO
 	compile_error(PARSER_ARG "identifier %"PRIsVALUE" is not valid to set", rb_id2str(id));
     }
   error:
-    return assignable_result(0);
+    return assignable_error();
 #undef assignable_result
 #undef parser_yyerror
 }
