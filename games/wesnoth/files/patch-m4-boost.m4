--- m4/boost.m4~	2010-05-27 11:37:13.000000000 +0400
+++ m4/boost.m4	2010-08-23 07:12:17.014432212 +0400
@@ -729,7 +729,7 @@ AC_CACHE_CHECK([for the flags needed to 
   esac
   # Generate the test file.
   AC_LANG_CONFTEST([AC_LANG_PROGRAM([#include <pthread.h>],
-    [pthread_t th; pthread_join(th, 0);
+    [pthread_t th=NULL; pthread_join(th, 0);
     pthread_attr_init(0); pthread_cleanup_push(0, 0);
     pthread_create(0,0,0,0); pthread_cleanup_pop(0);])])
   for boost_pthread_flag in '' $boost_pthread_flags; do
