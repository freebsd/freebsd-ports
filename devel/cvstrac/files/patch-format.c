--- ./format.c.orig	2007-01-28 17:50:24.000000000 -0500
+++ ./format.c	2009-11-09 17:15:57.000000000 -0500
@@ -701,11 +701,10 @@
 ** Return TRUE if the HTML element given in the argument is a form of
 ** external reference (i.e. A, IMG, etc).
 */
-extern int sqlite3StrNICmp(const char *, const char*, int);
 static int isLinkTag(const char *zElem, int nElem){
-  return (nElem==1 && 0==sqlite3StrNICmp(zElem,"A",nElem))
-      || (nElem==3 && 0==sqlite3StrNICmp(zElem,"IMG",nElem))
-      || (nElem==4 && 0==sqlite3StrNICmp(zElem,"CITE",nElem));
+  return (nElem==1 && 0==sqlite3_strnicmp(zElem,"A",nElem))
+      || (nElem==3 && 0==sqlite3_strnicmp(zElem,"IMG",nElem))
+      || (nElem==4 && 0==sqlite3_strnicmp(zElem,"CITE",nElem));
 }
 
 /*
@@ -713,12 +712,11 @@
 ** before it ends, then return the number of characters through the end of
 ** the </html>.  If the <html> or the </html> is missing, return 0.
 */
-extern int sqlite3StrNICmp(const char *, const char*, int);
 static int is_html(const char *z){
   int i;
-  if( sqlite3StrNICmp(z, "<html>", 6) ) return 0;
+  if( sqlite3_strnicmp(z, "<html>", 6) ) return 0;
   for(i=6; z[i]; i++){
-    if( z[i]=='<' && sqlite3StrNICmp(&z[i],"</html>",7)==0 ) return i+7;
+    if( z[i]=='<' && sqlite3_strnicmp(&z[i],"</html>",7)==0 ) return i+7;
   }
   return 0;
 }
