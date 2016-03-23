Obey hier(7)

--- scripts/mysqld_safe.sh.orig	2015-10-15 15:43:45 UTC
+++ scripts/mysqld_safe.sh
@@ -558,10 +558,10 @@ fi
 
 if test -z "$MYSQL_HOME"
 then 
-  if test -r "$MY_BASEDIR_VERSION/my.cnf" && test -r "$DATADIR/my.cnf"
+  if test -r "$MY_BASEDIR_VERSION/etc/my.cnf" && test -r "$DATADIR/my.cnf"
   then
     log_error "WARNING: Found two instances of my.cnf -
-$MY_BASEDIR_VERSION/my.cnf and
+$MY_BASEDIR_VERSION/etc/my.cnf and
 $DATADIR/my.cnf
 IGNORING $DATADIR/my.cnf"
 
@@ -570,7 +570,7 @@ IGNORING $DATADIR/my.cnf"
   then
     log_error "WARNING: Found $DATADIR/my.cnf
 The data directory is a deprecated location for my.cnf, please move it to
-$MY_BASEDIR_VERSION/my.cnf"
+$MY_BASEDIR_VERSION/etc/my.cnf"
     MYSQL_HOME=$DATADIR
   else
     MYSQL_HOME=$MY_BASEDIR_VERSION
