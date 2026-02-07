--- src/lexer.en.l.bak	Tue Jul 16 06:15:12 2002
+++ src/lexer.en.l	Thu Jul 27 22:45:32 2006
@@ -70,7 +70,7 @@
    #define IS_TOK_WITH_VAL(tok, type, val)                                    \
    {                                                                          \
      lextxt = yylex; \
-     yylval.##type = val;                                                     \
+     yylval.type = val;                                                     \
      return(tok);                                                             \
    }
  #endif
