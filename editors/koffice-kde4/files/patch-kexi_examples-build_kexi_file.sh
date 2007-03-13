--- kexi/examples/build_kexi_file.sh.orig	Mon Mar  5 01:50:05 2007
+++ kexi/examples/build_kexi_file.sh	Mon Mar  5 01:50:31 2007
@@ -7,9 +7,9 @@
 # Only .kexi file that is older than .sql file is recreated.
 # ksqlite is needed on the $PATH.
 
-KEXISQL3PATH=../3rdparty/kexisql3/src/.libs/
-PATH=$PATH:$KEXISQL3PATH
-LD_LIBRARY_PATH=$KEXISQL3PATH:$KEXISQL3PATH
+export KEXISQL3PATH=../3rdparty/kexisql3/src/.libs/
+export PATH=$PATH:$KEXISQL3PATH
+export LD_LIBRARY_PATH=$KEXISQL3PATH:$KEXISQL3PATH
 which ksqlite > /dev/null || exit 1
 
 [ $# -lt 1 ] && echo "Missing .sql filename." && exit 1
