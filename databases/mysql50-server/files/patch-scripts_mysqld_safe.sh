--- scripts/mysqld_safe.sh.orig	2007-12-12 10:04:16.000000000 +0100
+++ scripts/mysqld_safe.sh	2007-12-12 10:04:52.000000000 +0100
@@ -152,10 +152,10 @@
 
 if test -z "$MYSQL_HOME"
 then 
-  if test -r "$MY_BASEDIR_VERSION/my.cnf" && test -r "$DATADIR/my.cnf"
+  if test -r "$MY_BASEDIR_VERSION/etc/my.cnf" && test -r "$DATADIR/my.cnf"
   then
     echo "WARNING: Found two instances of my.cnf -"
-    echo "$MY_BASEDIR_VERSION/my.cnf and"
+    echo "$MY_BASEDIR_VERSION/etc/my.cnf and"
     echo "$DATADIR/my.cnf"
     echo "IGNORING $DATADIR/my.cnf"
     echo
@@ -163,7 +163,7 @@
   elif test -r "$DATADIR/my.cnf"
   then
     echo "WARNING: Found $DATADIR/my.cnf"
-    echo "Datadir is deprecated place for my.cnf, please move it to $MY_BASEDIR_VERSION"
+    echo "Datadir is deprecated place for my.cnf, please move it to $MY_BASEDIR_VERSION/etc"
     echo
     MYSQL_HOME=$DATADIR
   else
