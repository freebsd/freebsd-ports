--- assembler.y.orig	Sat Oct 26 01:11:50 2002
+++ assembler.y	Mon Dec  2 12:00:50 2002
@@ -254,22 +254,22 @@
 %token SWFACTION
 %token HEXDATA
 
-%token '(', ')', ',', ':', '"',	'.'
+%token '(' ')' ',' ':' '"' '.'
 
 %type <str> funcname_opt
 %type <str> mcname_opt
-%type <len> statements,	statement, statements_opt
-%type <len> function, function_args
-%type <len> push_list, push_item
+%type <len> statements statement statements_opt
+%type <len> function function_args
+%type <len> push_list push_item
 %type <len> with
-%type <len> settarget, settargetexpression, ifframeloaded, ifframeloadedexpression
-%type <len> actionblocks, actionblock, actionblocks_opt
-%type <len> buttoneventblocks, buttoneventblock, buttoneventblocks_opt
-%type <len> mceventblocks, mceventblock, mceventblocks_opt
-%type <len> mcblocks, mcblock, mcblocks_opt
-%type <len> frame, definebutton, definemc, placemc, initmc
-%type <len> buttonevent, buttonevents, mcevent, mcevents, key, property
-%type <len> opcode,hex_list, hexdata_opt
+%type <len> settarget settargetexpression ifframeloaded ifframeloadedexpression
+%type <len> actionblocks actionblock actionblocks_opt
+%type <len> buttoneventblocks buttoneventblock buttoneventblocks_opt
+%type <len> mceventblocks mceventblock mceventblocks_opt
+%type <len> mcblocks mcblock mcblocks_opt
+%type <len> frame definebutton definemc placemc initmc
+%type <len> buttonevent buttonevents mcevent mcevents key property
+%type <len> opcode hex_list hexdata_opt
 %type <num> urlmethod
 
 %%
@@ -447,7 +447,7 @@
 	;
 
 mcevent
-	: /* empty */			{ yyerror("Missing mc event condition")	}
+	: /* empty */			{ yyerror("Missing mc event condition");	}
 	| MCLOAD			{ $$ = 0x01;   }
 	| MCENTERFRAME			{ $$ = 0x02;   }
 	| MCUNLOAD			{ $$ = 0x04;   }
@@ -551,16 +551,10 @@
 	: SETTARGET STRING		{ $$ = writeByte(SWFACTION_SETTARGET);
 					  $$ +=	writeShort(strlen($2)+1);
 					  $$ +=	writeString($2); }
-	  statements_opt END		{ $$ = $4 + writeByte(SWFACTION_SETTARGET);
-					  $$ +=	$<len>3	+ writeShort(1);
-					  $$ +=	writeByte(0); }
 	;
 
 settargetexpression
 	: SETTARGETEXPR			{ $$ = writeByte(SWFACTION_SETTARGETEXPRESSION); }
-	  statements_opt END		{ $$ = $3 + writeByte(SWFACTION_SETTARGET);
-					  $$ +=	$<len>2	+ writeShort(1);
-					  $$ +=	writeByte(0); }
 	;
 
 ifframeloadedexpression
@@ -849,7 +843,7 @@
 
 	| GOTOFRAME INTEGER		{ $$ = writeByte(SWFACTION_GOTOFRAME);
 					  $$ +=	writeShort(2);
-					  $$ +=	writeShort(atoi($2)) }
+					  $$ +=	writeShort(atoi($2)); }
 
 	| GETURL STRING	STRING		{ $$ = writeByte(SWFACTION_GETURL);
 					  $$ +=	writeShort(strlen($2)+strlen($3)+2);
