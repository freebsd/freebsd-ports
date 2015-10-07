--- cmd/tools/gmlscan.l.orig	2014-04-13 22:40:25.000000000 +0200
+++ cmd/tools/gmlscan.l	2015-07-29 14:51:42.000000000 +0200
@@ -127,7 +127,7 @@
 	return;
     errors = 1;
     sprintf(buf," %s in line %d near '%s'\n", str,line_num,yytext);
-    agerr(AGWARN,buf);
+    agerr(AGWARN, "%s", buf);
 }
 
 int gmlerrors()
