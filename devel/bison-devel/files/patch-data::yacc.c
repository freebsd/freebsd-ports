--- data/yacc.c.orig	Sat Dec 28 00:36:02 2002
+++ data/yacc.c	Sun Dec  5 14:26:50 2004
@@ -465,7 +465,13 @@
 
 #define YYACCEPT	goto yyacceptlab
 #define YYABORT		goto yyabortlab
-#define YYERROR		goto yyerrlab1
+#define YYERROR		]b4_location_if([do	\
+			{			\
+			  yylerrsp = ylap;	\
+			  *++yylerrsp = yyloc;	\
+			  goto yyerrlab1;	\
+			} while (0)],		\
+			[goto yyerrlab1])[
 
 /* Like YYERROR except do call yyerror.  This remains here temporarily
    to ease the transition to the new meaning of YYERROR, for GCC.
@@ -1103,29 +1109,13 @@
 
   /* Else will try to reuse lookahead token after shifting the error
      token.  */
-  goto yyerrlab2;
+  goto yyerrlab1;
 
 
 /*----------------------------------------------------.
 | yyerrlab1 -- error raised explicitly by an action.  |
 `----------------------------------------------------*/
 yyerrlab1:
-
-  /* Suppress GCC warning that yyerrlab1 is unused when no action
-     invokes YYERROR.  */
-#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
-  __attribute__ ((__unused__))
-#endif
-
-]b4_location_if([  yylerrsp = yylsp;
-  *++yylerrsp = yyloc;])[
-  goto yyerrlab2;
-
-
-/*---------------------------------------------------------------.
-| yyerrlab2 -- pop states until the error token can be shifted.  |
-`---------------------------------------------------------------*/
-yyerrlab2:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
   for (;;)
