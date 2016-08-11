--- src/ldlex.c.orig	2014-08-26 08:58:02 UTC
+++ src/ldlex.c
@@ -1629,7 +1629,7 @@ YY_RULE_SETUP
 #line 149 "/home/mark/src/elfutils/src/ldlex.l"
 { int cnt = 1 ;
 				  ldlval.num = 0;
-				  while (cnt < ldleng - 1)
+				  while (cnt < (int)ldleng - 1)
 				    ldlval.num |= attrib_convert (ldtext[cnt++]);
 				  return kMODE; }
 	YY_BREAK
