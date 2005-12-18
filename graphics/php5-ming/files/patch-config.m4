--- config.m4.orig	Sun Dec 18 19:56:10 2005
+++ config.m4	Sun Dec 18 19:57:15 2005
@@ -72,13 +72,6 @@
     AC_DEFINE(HAVE_NEW_MING,  1, [ ]) 
     dnl FIXME: This is now unconditional..better check coming later.
     AC_DEFINE(HAVE_MING_ZLIB, 1, [ ])
-    AC_TRY_COMPILE([
-#include <ming.h>
-int main(int,void) {
-  SWFMovie_output(NULL, NULL, NULL, 0));
-  return 0;
-}
-	], [ AC_DEFINE(HAVE_MING_MOVIE_LEVEL, 1, []) ])
   ])
   CPPFLAGS=$old_CPPFLAGS
 
