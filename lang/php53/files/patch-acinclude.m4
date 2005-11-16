--- acinclude.m4.orig	Tue Jul 26 00:31:07 2005
+++ acinclude.m4	Wed Nov 16 09:30:03 2005
@@ -1707,9 +1707,9 @@
   test -z "$PHP_IMAP_SSL" && PHP_IMAP_SSL=no
 
   dnl Fallbacks for different configure options
-  if test "$PHP_OPENSSL" != "no"; then
+  if test -n "$PHP_OPENSSL" && test "$PHP_OPENSSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_OPENSSL
-  elif test "$PHP_IMAP_SSL" != "no"; then
+  elif test -n "$PHP_IMAP_SSL" && test "$PHP_IMAP_SSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_IMAP_SSL
   fi
 
