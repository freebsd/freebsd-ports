--- src/main.c.orig	Tue Jul 16 23:45:12 2002
+++ src/main.c	Tue Jul 16 23:45:28 2002
@@ -75,7 +75,7 @@
 
   printf("%s version %s\nCopyleft foobar and judeo (See COPYING for info)\n",TITLE,VERSION);
 
-  loadconfig("config");
+  loadconfig("%%DATADIR%%/config");
   
   if(!initsdl())	error("SDL Loading Failed");
   else			printf("  Loaded: SDL\n");
