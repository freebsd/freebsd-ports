--- actioncompiler/swf5compiler.y.orig	Mon Dec  2 11:13:11 2002
+++ actioncompiler/swf5compiler.y	Mon Dec  2 11:18:08 2002
@@ -37,23 +37,23 @@
 
 /* tokens etc. */
 
-%token BREAK, CONTINUE, FUNCTION, ELSE, SWITCH, CASE, FOR, IN, IF, WHILE,
-  DO, VAR, NEW, DELETE, RETURN, END, WITH, ASM, EVAL
+%token BREAK CONTINUE FUNCTION ELSE SWITCH CASE FOR IN IF WHILE
+  DO VAR NEW DELETE RETURN END WITH ASM EVAL
 
-%token RANDOM, GETTIMER, LENGTH, CONCAT, SUBSTR, TRACE, INT, ORD, CHR, GETURL,
-  GETURL1, NEXTFRAME, PREVFRAME, PLAY, STOP, TOGGLEQUALITY, STOPSOUNDS
+%token RANDOM GETTIMER LENGTH CONCAT SUBSTR TRACE INT ORD CHR GETURL
+  GETURL1 NEXTFRAME PREVFRAME PLAY STOP TOGGLEQUALITY STOPSOUNDS
 
-%token DUP, SWAP, POP, PUSH, SETREGISTER, CALLFUNCTION, CALLMETHOD,
-  AND, OR, XOR, MODULO, ADD, LESSTHAN, EQUALS,
-  INC, DEC, TYPEOF, ENUMERATE, INITOBJECT, INITARRAY, GETMEMBER,
-  SETMEMBER, SHIFTLEFT, SHIFTRIGHT, SHIFTRIGHT2, VAREQUALS, OLDADD, SUBTRACT,
-  MULTIPLY, DIVIDE, OLDEQUALS, OLDLESSTHAN, LOGICALAND, LOGICALOR, NOT,
-  STRINGEQ, STRINGLENGTH, SUBSTRING, GETVARIABLE, SETVARIABLE,
-  SETTARGETEXPRESSION,  DUPLICATEMOVIECLIP, REMOVEMOVIECLIP,
-  STRINGLESSTHAN, MBLENGTH, MBSUBSTRING, MBORD, MBCHR,
-  BRANCHALWAYS, BRANCHIFTRUE, GETURL2, POST, GET,
-  LOADVARIABLES, LOADMOVIE, LOADVARIABLESNUM, LOADMOVIENUM,
-  CALLFRAME, STARTDRAG, STOPDRAG, GOTOFRAME, SETTARGET
+%token DUP SWAP POP PUSH SETREGISTER CALLFUNCTION CALLMETHOD
+  AND OR XOR MODULO ADD LESSTHAN EQUALS
+  INC DEC TYPEOF ENUMERATE INITOBJECT INITARRAY GETMEMBER
+  SETMEMBER SHIFTLEFT SHIFTRIGHT SHIFTRIGHT2 VAREQUALS OLDADD SUBTRACT
+  MULTIPLY DIVIDE OLDEQUALS OLDLESSTHAN LOGICALAND LOGICALOR NOT
+  STRINGEQ STRINGLENGTH SUBSTRING GETVARIABLE SETVARIABLE
+  SETTARGETEXPRESSION  DUPLICATEMOVIECLIP REMOVEMOVIECLIP
+  STRINGLESSTHAN MBLENGTH MBSUBSTRING MBORD MBCHR
+  BRANCHALWAYS BRANCHIFTRUE GETURL2 POST GET
+  LOADVARIABLES LOADMOVIE LOADVARIABLESNUM LOADMOVIENUM
+  CALLFRAME STARTDRAG STOPDRAG GOTOFRAME SETTARGET
 
 %token NULLVAL
 %token <intVal> INTEGER
@@ -106,26 +106,26 @@
 %left '.' '[' ']'
 
 
-%type <action> program, code
-%type <action> stmt, stmts
-%type <action> if_stmt, iter_stmt, cont_stmt, break_stmt, return_stmt
+%type <action> program code
+%type <action> stmt stmts
+%type <action> if_stmt iter_stmt cont_stmt break_stmt return_stmt
 %type <action> with_stmt
-%type <action> switch_stmt, switch_cases, switch_case
-%type <action> anon_function_decl, function_decl, anycode
-%type <action> void_function_call, function_call, method_call
-%type <action> assign_stmt, assign_stmts, assign_stmts_opt
-%type <action> expr, expr_or_obj, objexpr, expr_opt, obj_ref
-%type <action> emptybraces, level, init_vars, init_var, primary, lvalue_expr
+%type <action> switch_stmt switch_cases switch_case
+%type <action> anon_function_decl function_decl anycode
+%type <action> void_function_call function_call method_call
+%type <action> assign_stmt assign_stmts assign_stmts_opt
+%type <action> expr expr_or_obj objexpr expr_opt obj_ref
+%type <action> emptybraces level init_vars init_var primary lvalue_expr
 %type <lval> lvalue
 
-%type <exprlist> expr_list, objexpr_list, formals_list
+%type <exprlist> expr_list objexpr_list formals_list
 
-%type <op> assignop, incdecop
+%type <op> assignop incdecop
 %type <getURLMethod> urlmethod
 
 %type <str> identifier
 
-%type <len> opcode, opcode_list, push_item, with, push_list
+%type <len> opcode opcode_list push_item with push_list
 
 /*
 %type <intVal> integer
@@ -144,6 +144,7 @@
 		  bufferConcat(b, bf);
 		  bufferConcat(b, bc);
 		  *((Buffer *)buffer) = b; }
+		  ;
 
 code
 	: anycode
@@ -228,6 +229,7 @@
 		  bufferWriteS16($$, 2);
 		  bufferWriteS16($$, bufferLength($5));
 		  bufferConcat($$, $5); }
+		  ;
 
 expr_opt
 	: /* empty */	{ $$ = NULL; }
