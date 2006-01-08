--- config.m4	Sat Jan  7 19:58:52 2006
+++ config.m4.new	Sat Jan  7 20:00:55 2006
@@ -36,10 +36,10 @@
         if test -d $i/lib64 ; then
           PHP_SVN_LDFLAGS="-L$i/lib64 $PHP_SVN_LDFLAGS"
         fi
-        PHP_SVN_LDFLAGS="$PHP_SVN_LDFLAGS -lsvn_client-1 -lapr-0"
+        PHP_SVN_LDFLAGS="$PHP_SVN_LDFLAGS -lsvn_client-1 -lapr-1"
       fi
-      if test -r $i/include/apr-0/apr.h ; then
-        PHP_SVN_INCLUDES="$PHP_SVN_INCLUDES -I$i/include/apr-0"
+      if test -r $i/include/apr-1/apr.h ; then
+        PHP_SVN_INCLUDES="$PHP_SVN_INCLUDES -I$i/include/apr-1"
       elif test -r $i/include/apache2/apr.h ; then
         PHP_SVN_INCLUDES="$PHP_SVN_INCLUDES -I$i/include/apache2"
       fi
