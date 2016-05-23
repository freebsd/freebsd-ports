--- ../lang/sql/upgrade61.sh	2016-03-28 21:45:53.000000000 +0200
+++ ../../db6-upgrade61.sh	2016-05-23 21:55:49.741020000 +0200
@@ -1,12 +1,19 @@
 #!/bin/sh
 # This script upgrades SQL databases from BDB 5.0 to early 6.1
 # to late 6.1 and up by reindexing them.
+# 
+# Originally provided by Oracle as part of the Oracle BerkeleyDB
+# 12.1.6.* tarballs.
 #
+# Bugfixed for proper quoting and error checking
+# by Matthias Andree <mandree@FreeBSD.org>
 
-for var in $@
+rc=0
+for var in "$@"
 do
-    echo Recovering database $var
-    db_recover -f -h ${var}-journal
-    echo Reindexing database $var
-    echo .quit | dbsql -cmd REINDEX  $var
+    echo "Recovering database $var"
+    db_recover-%%BDBVER%% -f -h "${var}-journal" || { rc=1 ; continue ; }
+    echo "Reindexing database $var"
+    echo .quit | dbsql-%%BDBVER%% -cmd REINDEX "$var" || rc=1
 done
+exit $rc
