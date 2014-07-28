--- ./xpostit.c.org	Thu Dec 10 08:40:27 1992
+++ ./xpostit.c	Thu Oct 31 21:31:14 1996
@@ -121,7 +121,6 @@
 {
 	Arg args[4];
 	char *appname;
-	char *rindex();
 	Atom protos[2];
 	register int nargs;
 	Boolean setsigs = False;
