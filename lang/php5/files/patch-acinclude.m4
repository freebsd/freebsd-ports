--- acinclude.m4.orig	Sat Dec 24 12:38:05 2005
+++ acinclude.m4	Mon Jan 16 12:20:17 2006
@@ -1021,12 +1021,6 @@
 build to be successful.
 ])
   fi
-  if test "x$is_it_shared" = "x" && test "x$3" != "xtrue"; then
-    AC_MSG_ERROR([
-You've configured extension $1, which depends on extension $2,
-but you've either not enabled $2, or have disabled it.
-])
-  fi
   dnl Some systems require that we link $2 to $1 when building
 ])
 
@@ -2151,9 +2145,9 @@
   test -z "$PHP_IMAP_SSL" && PHP_IMAP_SSL=no
 
   dnl Fallbacks for different configure options
-  if test "$PHP_OPENSSL" != "no"; then
+  if test -n "$PHP_OPENSSL" && test "$PHP_OPENSSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_OPENSSL
-  elif test "$PHP_IMAP_SSL" != "no"; then
+  elif test -n "$PHP_IMAP_SSL" && test "$PHP_IMAP_SSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_IMAP_SSL
   fi
 
