--- scripts/mysqlbug.sh.orig	Tue May 18 10:20:19 2004
+++ scripts/mysqlbug.sh	Fri May 14 02:53:22 2004
@@ -254,9 +254,9 @@
 if cmp -s $TEMP $TEMP.x
 then
   echo "File not changed, no bug report submitted."
-  cp $TEMP /tmp/failed-mysql-bugreport
+  mv -f $TEMP /tmp/failed-mysql-bugreport
   echo "The raw bug report exists in /tmp/failed-mysql-bugreport"
-  echo "If you use this remember that the first lines of the report now is a lie.."
+  echo "If you use this remember that the first lines of the report are now a lie.."
   exit 1
 fi
 
