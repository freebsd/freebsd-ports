--- src/plugins_3rdparty/phylip/src/phylip.h.orig	2017-12-30 19:54:56 UTC
+++ src/plugins_3rdparty/phylip/src/phylip.h
@@ -271,7 +271,6 @@ MALLOCRETURN    *mymalloc(long);
 #define MAXNCH          30   /* must be greater than or equal to nmlngth */
 #define maxcategs       9    /* maximum number of site types */
 #define maxcategs2     11    /* maximum number of site types + 2 */
-#define point           "."
 #define pointe          '.'
 #define down            2
 #define MAXSHIMOTREES 100
