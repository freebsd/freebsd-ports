--- selftests.sh	(revision 397)
+++ selftests.sh	(working copy)
@@ -14,7 +14,8 @@
   rm -f $t/*
   sed -e '1,/^#ifdef SELFTEST_EXP$/d' -e '/^#endif/,$d' $1 >$t/test.exp
 
-  ./compile $1 -DSELFTEST_MAIN -o $t/test.o || {
+  sed -e 's/-o ${base}.o//' compile | \
+  sh -s $1 -DSELFTEST_MAIN -o $t/test.o || {
     echo "=====> Compile failed! <====="
     return 1
   }
