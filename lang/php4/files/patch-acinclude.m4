--- acinclude.m4.orig	Fri Sep 23 11:20:22 2005
+++ acinclude.m4	Tue Nov 15 23:25:54 2005
@@ -1709,9 +1709,9 @@
   test -z "$PHP_IMAP_SSL" && PHP_IMAP_SSL=no
 
   dnl Fallbacks for different configure options
-  if test "$PHP_OPENSSL" != "no"; then
+  if test -n "$PHP_OPENSSL" && test "$PHP_OPENSSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_OPENSSL
-  elif test "$PHP_IMAP_SSL" != "no"; then
+  elif test -n "$PHP_IMAP_SSL" && test "$PHP_IMAP_SSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_IMAP_SSL
   fi
 
