--- kexi/examples/update_sql_files.sh.orig	Sun Mar  4 13:49:03 2007
+++ kexi/examples/update_sql_files.sh	Sun Mar  4 13:49:14 2007
@@ -4,9 +4,9 @@
 # Only .sql file that is older than .kexi file is recreated.
 # ksqlite is needed on the PATH
 
-KEXISQL3PATH=../3rdparty/kexisql3/src/.libs/
-PATH=$PATH:$KEXISQL3PATH
-LD_LIBRARY_PATH=$KEXISQL3PATH:$KEXISQL3PATH
+export KEXISQL3PATH=../3rdparty/kexisql3/src/.libs/
+export PATH=$PATH:$KEXISQL3PATH
+export LD_LIBRARY_PATH=$KEXISQL3PATH:$KEXISQL3PATH
 which ksqlite > /dev/null || exit 1
 
 for f in `ls -1 *.kexi` ; do
