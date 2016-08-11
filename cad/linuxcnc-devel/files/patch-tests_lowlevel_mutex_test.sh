--- tests/lowlevel/mutex/test.sh.orig	2016-06-25 02:19:12 UTC
+++ tests/lowlevel/mutex/test.sh
@@ -1,5 +1,5 @@
 #!/bin/sh
-gcc -O -I ../../../include test.c -o test -DULAPI -std=gnu99 -pthread || exit 1
+cc -O -I ../../../include test.c -o test -DULAPI -std=gnu99 -pthread || exit 1
 ./test; exitval=$?
 rm -f test
 exit $exitval
