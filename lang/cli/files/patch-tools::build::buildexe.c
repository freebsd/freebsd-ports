
$FreeBSD$

--- tools/build/buildexe.c	2002/03/29 18:41:58	1.1
+++ tools/build/buildexe.c	2002/03/29 18:42:44
@@ -1927,7 +1927,7 @@
         }
 #ifdef __GNUC__
   else
-    if ( TestPrefixPath( &p, "gcc " )) {
+    if ( TestPrefixPath( &p, "cc " )) {
          ThreadState->FilterProc = C510Filter;
          ThreadState->ChildFlags = 0;
          if ( strstr( p, "-Wall" ) != NULL || strstr( p, "-Werror" ) != NULL) {
