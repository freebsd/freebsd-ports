--- scripts/mysql_install_db.sh.orig	Thu Mar 11 10:20:57 2004
+++ scripts/mysql_install_db.sh	Thu Mar 11 10:27:09 2004
@@ -118,7 +118,7 @@
   if [ $? -ne 0 ]
   then
     resolved=`$bindir/resolveip localhost 2>&1`
-    if [ $? -eq 0 ]
+    if [ $? -ne 0 ]
     then
       echo "Neither host '$hostname' and 'localhost' could not be looked up with"
       echo "$bindir/resolveip"
@@ -128,8 +128,8 @@
       exit 1
     fi
     echo "WARNING: The host '$hostname' could not be looked up with resolveip."
-    echo "This probably means that your libc libraries are not 100 % compatible"
-    echo "with this binary MySQL version. The MySQL daemon, mysqld, should work"
+    echo "This probably means that your host name is not listed in your"
+    echo "/etc/hosts file (as it should). The MySQL daemon, mysqld, should work"
     echo "normally with the exception that host name resolving will not work."
     echo "This means that you should use IP addresses instead of hostnames"
     echo "when specifying MySQL privileges !"
