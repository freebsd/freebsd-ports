--- acinclude.m4.orig	Mon Apr  4 10:30:15 2005
+++ acinclude.m4	Mon Apr  4 10:33:00 2005
@@ -1685,9 +1685,9 @@
   unset OPENSSL_LIBDIR
 
   dnl Fallbacks for different configure options
-  if test "$PHP_OPENSSL" != "no"; then
+  if test -n "$PHP_OPENSSL" && test "$PHP_OPENSSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_OPENSSL
-  elif test "$PHP_IMAP_SSL" != "no"; then
+  elif test -n "$PHP_IMAP_SSL" && test "$PHP_IMAP_SSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_IMAP_SSL
   fi
 
