--- scripts/mysqld_safe.sh.orig	2007-10-08 10:39:23.000000000 +0200
+++ scripts/mysqld_safe.sh	2007-10-08 10:40:52.000000000 +0200
@@ -235,10 +235,10 @@
 
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
 
@@ -247,7 +247,7 @@
   then
     log_error "WARNING: Found $DATADIR/my.cnf
 The data directory is a deprecated location for my.cnf, please move it to
-$MY_BASEDIR_VERSION/my.cnf"
+$MY_BASEDIR_VERSION/etc/my.cnf"
     MYSQL_HOME=$DATADIR
   else
     MYSQL_HOME=$MY_BASEDIR_VERSION
