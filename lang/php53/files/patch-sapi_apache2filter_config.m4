--- sapi/apache2filter/config.m4.orig	2013-10-18 12:17:14.622544934 +0000
+++ sapi/apache2filter/config.m4	2013-10-18 12:22:13.032234760 +0000
@@ -68,7 +68,7 @@
   fi
 
   APXS_LIBEXECDIR='$(INSTALL_ROOT)'`$APXS -q LIBEXECDIR`
-  if test -z `$APXS -q SYSCONFDIR`; then
+  if true; then
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
                        -i -n php5"
