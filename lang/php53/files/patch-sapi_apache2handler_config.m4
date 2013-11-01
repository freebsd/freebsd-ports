--- sapi/apache2handler/config.m4.orig	2013-10-18 12:22:26.576545216 +0000
+++ sapi/apache2handler/config.m4	2013-10-18 12:23:00.903131412 +0000
@@ -67,7 +67,7 @@
   fi
 
   APXS_LIBEXECDIR='$(INSTALL_ROOT)'`$APXS -q LIBEXECDIR`
-  if test -z `$APXS -q SYSCONFDIR`; then
+  if true; then
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
                        -i -n php5"
