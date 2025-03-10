--- sapi/apache2handler/config.m4.orig	2024-08-27 14:33:48 UTC
+++ sapi/apache2handler/config.m4
@@ -61,7 +61,7 @@ if test "$PHP_APXS2" != "no"; then
     [AC_MSG_ERROR([Please note that Apache version >= 2.4 is required])])
 
   APXS_LIBEXECDIR='$(INSTALL_ROOT)'$($APXS -q LIBEXECDIR)
-  if test -z $($APXS -q SYSCONFDIR); then
+  if true; then
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
                        -i -n php"
