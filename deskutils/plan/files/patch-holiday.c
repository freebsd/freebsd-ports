--- holiday.c.orig	2005-05-17 13:22:27.000000000 -0700
+++ holiday.c	2020-08-23 22:19:14.336458000 -0700
@@ -50,7 +50,7 @@
 extern int yyparse(void);
 
 
-#if defined(bsdi)||defined(linux)||defined(__NetBSD__)||defined(__FreeBSD__)||defined(HPGCC)||defined(__EMX__)||defined(__OpenBSD__)||defined(MACOSX)
+#if defined(bsdi)||defined(linux)||defined(__NetBSD__)||defined(HPGCC)||defined(__EMX__)||defined(__OpenBSD__)||defined(MACOSX)
 int yylineno;
 #else
 extern int	 yylineno;		/* current line # being parsed */
