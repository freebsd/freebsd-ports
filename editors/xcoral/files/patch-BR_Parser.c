--- BR_Parser.c.orig	2002-12-18 07:22:09 UTC
+++ BR_Parser.c
@@ -116,7 +116,7 @@
 
 #define YYDEBUG                 1
 
-#define BR_YYERROR              YYFAIL
+#define BR_YYERROR              YYERROR
 
 
    /*-----------------------------------------------------------------------*/
@@ -960,12 +960,7 @@ static const short yycheck[] = {     1,
 #define YYEOF		0
 #define YYACCEPT	goto yyacceptlab
 #define YYABORT 	goto yyabortlab
-#define YYERROR		goto yyerrlab1
-/* Like YYERROR except do call yyerror.
-   This remains here temporarily to ease the
-   transition to the new meaning of YYERROR, for GCC.
-   Once GCC version 2 has supplanted version 1, this can go.  */
-#define YYFAIL		goto yyerrlab
+#define YYERROR		goto yyerrlab
 #define YYRECOVERING()  (!!yyerrstatus)
 #define YYBACKUP(token, value) \
 do								\
@@ -2465,9 +2460,6 @@ yyerrlab:   /* here on detecting error *
 	yyerror("parse error");
     }
 
-  goto yyerrlab1;
-yyerrlab1:   /* here on error raised explicitly by an action */
-
   if (yyerrstatus == 3)
     {
       /* if just tried and failed to reuse lookahead token after an error, discard it.  */
