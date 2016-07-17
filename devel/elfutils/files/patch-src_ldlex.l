--- src/ldlex.l.orig	2014-02-05 00:21:44 UTC
+++ src/ldlex.l
@@ -148,7 +148,7 @@ VERSION				{ return kVERSION; }
 
 "["([RWX]){0,3}"]"		{ int cnt = 1 ;
 				  ldlval.num = 0;
-				  while (cnt < yyleng - 1)
+				  while (cnt < (int)yyleng - 1)
 				    ldlval.num |= attrib_convert (yytext[cnt++]);
 				  return kMODE; }
 
