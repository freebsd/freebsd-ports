
$FreeBSD$

--- tstring.cc.orig	Wed Apr 24 03:16:33 2002
+++ tstring.cc	Sat Sep 28 23:00:58 2002
@@ -72,7 +72,7 @@
   return(&ptoken);
 }
 
-int tstring::tokenvalue(char *t, int base=10) {
+int tstring::tokenvalue(char *t, int base) {
   string *v;
   int n;
   v=token(t);
