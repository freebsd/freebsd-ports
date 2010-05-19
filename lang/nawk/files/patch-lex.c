--- lex.c.orig	2006/04/16 02:10:18	1.9
+++ lex.c	2008/06/04 14:04:42	1.10
@@ -48,9 +48,11 @@
 	{ "BEGIN",	XBEGIN,		XBEGIN },
 	{ "END",	XEND,		XEND },
 	{ "NF",		VARNF,		VARNF },
+	{ "and",	FAND,		BLTIN },
 	{ "atan2",	FATAN,		BLTIN },
 	{ "break",	BREAK,		BREAK },
 	{ "close",	CLOSE,		CLOSE },
+	{ "compl",	FCOMPL,		BLTIN },
 	{ "continue",	CONTINUE,	CONTINUE },
 	{ "cos",	FCOS,		BLTIN },
 	{ "delete",	DELETE,		DELETE },
@@ -70,13 +72,16 @@
 	{ "int",	FINT,		BLTIN },
 	{ "length",	FLENGTH,	BLTIN },
 	{ "log",	FLOG,		BLTIN },
+	{ "lshift",	FLSHIFT,	BLTIN },
 	{ "match",	MATCHFCN,	MATCHFCN },
 	{ "next",	NEXT,		NEXT },
 	{ "nextfile",	NEXTFILE,	NEXTFILE },
+	{ "or",		FFOR,		BLTIN },
 	{ "print",	PRINT,		PRINT },
 	{ "printf",	PRINTF,		PRINTF },
 	{ "rand",	FRAND,		BLTIN },
 	{ "return",	RETURN,		RETURN },
+	{ "rshift",	FRSHIFT,	BLTIN },
 	{ "sin",	FSIN,		BLTIN },
 	{ "split",	SPLIT,		SPLIT },
 	{ "sprintf",	SPRINTF,	SPRINTF },
@@ -88,6 +93,7 @@
 	{ "tolower",	FTOLOWER,	BLTIN },
 	{ "toupper",	FTOUPPER,	BLTIN },
 	{ "while",	WHILE,		WHILE },
+	{ "xor",	FXOR,		BLTIN },
 };
 
 #define DEBUG
