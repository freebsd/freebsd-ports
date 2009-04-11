--- mtasc/parser.ml.orig	2009-04-11 12:35:07.000000000 +0400
+++ mtasc/parser.ml	2009-04-11 12:37:16.000000000 +0400
@@ -166,8 +166,8 @@
 	| [< '(Kwd For,p); '(POpen,_); c = parse_expr_opt; e = parse_for p c >] -> e
 	| [< '(Kwd If,p); cond = parse_eval; e = parse_expr_opt; e2 , p2 = parse_else (pos e) >] -> EIf (cond,wrap_var e,e2), punion p p2
 	| [< '(Kwd Return,p); v , p2 = parse_eval_option p; >] -> EReturn v , punion p p2
-	| [< '(Kwd Break,p); >] -> EBreak , p
-	| [< '(Kwd Continue,p); >] -> EContinue , p
+	| [< '(Kwd Break,p) >] -> EBreak , p
+	| [< '(Kwd Continue,p) >] -> EContinue , p
 	| [< '(Kwd While,p1); v = parse_eval; e = parse_expr_opt >] -> EWhile (v,wrap_var e,NormalWhile) , punion p1 (pos e)
 	| [< '(Kwd Do,p1); e = parse_expr; '(Kwd While,_); v = parse_eval; >] -> EWhile (v,wrap_var e,DoWhile) , punion p1 (pos v)
 	| [< '(Kwd Switch,p1); v = parse_eval; '(BrOpen,_); el, p2 = parse_switch false >] -> ESwitch (v,el) , punion p1 p2
@@ -278,7 +278,7 @@
 
 and parse_expr_opt = parser
 	| [< e = parse_expr >] -> e
-	| [< '(Next,p); >] -> EBlock [] , p
+	| [< '(Next,p) >] -> EBlock [] , p
 
 and parse_for p c = parser
 	| [< '(Kwd In,_); v = parse_eval; '(PClose,p2); e = parse_expr_opt >] -> EForIn(c,v,wrap_var e) , punion p p2
@@ -324,7 +324,7 @@
 and parse_block callb sp = parser
 	| [< e = callb; el,p = parse_block callb sp >] -> e :: el , p
 	| [< '(Next,_); el = parse_block callb sp >] -> el
-	| [< '(BrClose,p); >] -> [] , p
+	| [< '(BrClose,p) >] -> [] , p
 	| [< '(Eof,_) >] -> error Unclosed_parenthesis sp
 
 and parse_expr_list p = parser
@@ -351,7 +351,7 @@
 
 and parse_import = parser
 	| [< '(Const (Ident name),_); p = parse_import2 name >] -> p
-	| [< '(Binop OpMult,_); >] -> [] , None
+	| [< '(Binop OpMult,_) >] -> [] , None
 
 and parse_import2 name = parser
 	| [< '(Dot,_); p , n = parse_import >] -> name :: p , n
