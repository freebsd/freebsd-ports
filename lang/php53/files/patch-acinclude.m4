--- acinclude.m4.orig	Tue Jan 25 14:02:45 2005
+++ acinclude.m4	Mon Apr  4 11:09:25 2005
@@ -1681,9 +1681,9 @@
   unset OPENSSL_LIBDIR
 
   dnl Fallbacks for different configure options
-  if test "$PHP_OPENSSL" != "no"; then
+  if test -n "$PHP_OPENSSL" && test "$PHP_OPENSSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_OPENSSL
-  elif test "$PHP_IMAP_SSL" != "no"; then
+  elif test -n "$PHP_IMAP_SSL" && test "$PHP_IMAP_SSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_IMAP_SSL
   fi
 
