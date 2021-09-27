--- pblPerform.c.orig	2021-09-26 20:04:50 UTC
+++ pblPerform.c
@@ -85,7 +85,7 @@ if( end.tv_usec < start.tv_usec )\
     start.tv_sec++;\
 }\
 \
-printf( "%s took %ld.%.6ld\n", tag, (long)end.tv_sec - start.tv_sec, (long)end.tv_usec );\
+printf( "%s took %lld.%.6lld\n", tag, (long long)end.tv_sec - start.tv_sec, (long long)end.tv_usec );\
 }\
 
 /*****************************************************************************/
