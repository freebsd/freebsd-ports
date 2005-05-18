--- lex.l.orig	Sat Sep  4 22:45:16 1999
+++ lex.l	Mon May 16 15:55:19 2005
@@ -1,8 +1,8 @@
 %{
-#include <stdio.h>
-#include <string.h>
-#include <stream.h>
-#include <ctype.h>
+#include <cstdio>
+#include <cstring>
+#include <iostream>
+#include <cctype>
 #include "parsing.h"
 #include "parser.tab.h"
 int       LineNumber= 0;
@@ -72,5 +72,5 @@
 %%
 
 int yyerror(char* Error)
-{ cerr << form("%s:%d: %s.\n",FileName,LineNumber+1,Error); return 0;}
+{ cerr << "%s:%d: %s.\n",FileName,LineNumber+1,Error; return 0;}
 
