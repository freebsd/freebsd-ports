--- src/common/t/run_tests.sh.orig	2022-07-06 03:00:02 UTC
+++ src/common/t/run_tests.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 set +e        # allow tests to fail without aborting make test
 
@@ -10,7 +10,7 @@ for t in $( cat t/test1.hh | sed -e 's/^[^"]*"//' -e '
 		touch $f
 	fi
 	
-	nr=$[$nr+1]
+	nr=$((nr+1))
 	t/test $t > $f.mine.stdout 2> $f.mine.stderr
 	rv=$?
 	(echo stdout: ; cat $f.mine.stdout ; echo stderr: ; cat $f.mine.stderr ; echo exit: $rv ) > $f.mine
@@ -25,7 +25,7 @@ for t in $( cat t/test1.hh | sed -e 's/^[^"]*"//' -e '
 		else
 			diff -w $f $f.mine | sed -e 's/^/\# /'
 		fi
-		fail=$[$fail+1]
+		fail=$((fail+1))
 	fi
 done
 
