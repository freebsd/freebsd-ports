--- src/lexer.fr.l.bak	Tue Aug  6 15:07:50 2002
+++ src/lexer.fr.l	Thu Jul 27 22:45:32 2006
@@ -73,7 +73,7 @@
    #define IS_TOK_WITH_VAL(tok, type, val)                                    \
    {                                                                          \
      lextxt = yylex; \
-     yylval.##type = val;                                                     \
+     yylval.type = val;                                                     \
      return(tok);                                                             \
    }
  #endif
