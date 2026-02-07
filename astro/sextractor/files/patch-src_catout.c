--- src/catout.c.orig	2006-07-14 17:13:55 UTC
+++ src/catout.c
@@ -32,6 +32,7 @@
 #include	"sexheadsc.h"
 #include	"xml.h"
 
+double		ddummy;
 catstruct	*fitscat;
 tabstruct	*objtab = NULL;
 FILE		*ascfile;
