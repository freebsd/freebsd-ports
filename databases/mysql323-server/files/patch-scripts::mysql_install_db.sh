--- scripts/mysql_install_db.sh.orig	Thu Sep 11 13:49:21 2003
+++ scripts/mysql_install_db.sh	Fri Mar 12 11:32:09 2004
@@ -116,7 +116,7 @@
   if [ $? -ne 0 ]
   then
     resolved=`$bindir/resolveip localhost 2>&1`
-    if [ $? -eq 0 ]
+    if [ $? -ne 0 ]
     then
       echo "Sorry, the host '$hostname' could not be looked up."
       echo "Please configure the 'hostname' command to return a correct hostname."
@@ -125,8 +125,8 @@
       exit 1
     fi
     echo "WARNING: The host '$hostname' could not be looked up with resolveip."
-    echo "This probably means that your libc libraries are not 100 % compatible"
-    echo "with this binary MySQL version. The MySQL deamon, mysqld, should work"
+    echo "This probably means that your host name is not listed in your"
+    echo "/etc/hosts file (as it should). The MySQL daemon, mysqld, should work"
     echo "normally with the exception that host name resolving will not work."
     echo "This means that you should use IP addresses instead of hostnames"
     echo "when specifying MySQL privileges !"
