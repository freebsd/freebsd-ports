diff --git apr-util-1.6.1/build/dbm.m4 apr-util-1.6.1/build/dbm.m4
index 57bd131f..5cbee4b3 100644
--- apr-util-1.6.3/build/dbm.m4
+++ apr-util-1.6.3/build/dbm.m4
@@ -112,7 +112,7 @@ AC_DEFUN([APU_CHECK_BERKELEY_DB], [
         changequote([,])
         unset $cache_id
         AC_CHECK_HEADER([$bdb_header], [
-          if test "$1" = "3" -o "$1" = "4" -o "$1" = "5" -o "$1" = "6"; then
+          if test "$1" = "3" -o "$1" = "4" -o "$1" = "5" -o "$1" = "6" -o "$1" = "18"; then
             # We generate a separate cache variable for each prefix and libname
             # we search under.  That way, we avoid caching information that
             # changes if the user runs `configure' with a different set of
@@ -293,7 +293,7 @@ AC_DEFUN([APU_CHECK_DB1], [
   APU_CHECK_BERKELEY_DB(1, 0, 0,
     "$places",
     "db1/db.h db.h",
-    "db1"
+    "c db1"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=1
@@ -432,7 +432,15 @@ AC_DEFUN([APU_CHECK_DB], [
       AC_MSG_ERROR(Berkeley db$db_major not found)
     fi
     ;;
-  db[[456]])
+  db18[[0-9]])
+    db_major=`echo "$requested" | sed -e 's/db//' -e 's/.$//'`
+    db_minor=`echo "$requested" | sed -e 's/db//' -e 's/..//'`
+    APU_CHECK_DBXY("$check_places", "$db_major", "$db_minor")
+    if test "$apu_db_version" != "$db_major"; then
+      AC_MSG_ERROR(Berkeley db$db_major not found)
+    fi
+    ;;
+  db[[456]] | db18)
     db_major=`echo "$requested" | sed -e 's/db//'`
     # Start version search at version x.9
     db_minor=9
@@ -455,17 +463,21 @@ AC_DEFUN([APU_CHECK_DB], [
 ])
 
 dnl
-dnl APU_CHECK_DB_ALL: Try all Berkeley DB versions, from 6.X to 1.
+dnl APU_CHECK_DB_ALL: Try all Berkeley DB versions, from 18.X to 1.
 dnl
 AC_DEFUN([APU_CHECK_DB_ALL], [
   all_places=$1
 
-  # Start version search at version 6.9
-  db_version=69
+  # Start version search at version 18.9
+  db_version=189
   while [[ $db_version -ge 40 ]]
   do
     db_major=`echo $db_version | sed -e 's/.$//'`
-    db_minor=`echo $db_version | sed -e 's/.//'`
+    if test "$db_version" -ge "100" ; then
+      db_minor=`echo $db_version | sed -e 's/..//'`
+    else
+      db_minor=`echo $db_version | sed -e 's/.//'`
+    fi
     APU_CHECK_DBXY("$all_places", "$db_major", "$db_minor")
     if test "$apu_have_db" = "1"; then
       break
@@ -511,7 +523,7 @@ AC_DEFUN([APU_CHECK_DBM], [
   apu_db_version=0
 
   # Maximum supported version announced in help string.
-  # Although we search for all versions up to 6.9,
+  # Although we search for all versions up to 18.9,
   # we should only include existing versions in our
   # help string.
   dbm_list="sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4"
@@ -531,7 +543,7 @@ AC_DEFUN([APU_CHECK_DBM], [
     dbm_list="$dbm_list, db$db_version"
     db_version=`expr $db_version + 1`
   done
-  db_max_version=60
+  db_max_version=62
   db_min_version=60
   db_version="$db_min_version"
   while [[ $db_version -le $db_max_version ]]
@@ -539,9 +551,17 @@ AC_DEFUN([APU_CHECK_DBM], [
     dbm_list="$dbm_list, db$db_version"
     db_version=`expr $db_version + 1`
   done
+  db_max_version=181
+  db_min_version=180
+  db_version="$db_min_version"
+  while [[ $db_version -le $db_max_version ]]
+  do
+    dbm_list="$dbm_list, db$db_version"
+    db_version=`expr $db_version + 1`
+  done
 
   AC_ARG_WITH(dbm, [APR_HELP_STRING([--with-dbm=DBM], [choose the DBM type to use.
-      DBM={sdbm,gdbm,ndbm,db,db1,db185,db2,db3,db4,db4X,db5X,db6X} for some X=0,...,9])],
+      DBM={sdbm,gdbm,ndbm,db,db1,db185,db2,db3,db4,db4X,db5X,db6X,db18x} for some X=0,...,9])],
   [
     if test "$withval" = "yes"; then
       AC_MSG_ERROR([--with-dbm needs to specify a DBM type to use.
@@ -684,11 +704,11 @@ AC_DEFUN([APU_CHECK_DBM], [
       eval "apu_use_$requested=1"
       apu_default_dbm=$requested
       ;;
-    db185 | db[[123456]])
+    db185 | db[[123456]] | db18)
       apu_use_db=1
       apu_default_dbm=$requested
       ;;
-    db[[456]][[0-9]])
+    db[[456]][[0-9]] | db18[[0-9]])
       apu_use_db=1
       apu_default_dbm=`echo $requested | sed -e 's/.$//'`
       ;;
