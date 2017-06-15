regress runs multiple tests, don't silence it completely.

https://github.com/libevent/libevent/pull/446

--- test/test.sh.orig	2017-01-25 23:37:15 UTC
+++ test/test.sh
@@ -99,10 +99,10 @@ run_tests () {
 	fi
 
 	test -x $TEST_DIR/regress || return
-	announce_n " regress: "
+	announce " regress: [multiple tests]"
 	if test "$TEST_OUTPUT_FILE" = "/dev/null" ;
 	then
-		$TEST_DIR/regress --quiet $REGRESS_ARGS
+		$TEST_DIR/regress $REGRESS_ARGS
 	else
 		$TEST_DIR/regress $REGRESS_ARGS >>"$TEST_OUTPUT_FILE"
 	fi
@@ -114,10 +114,10 @@ run_tests () {
 		FAILED=yes
 	fi
 
-	announce_n " regress_debug: "
+	announce " regress_debug: [multiple tests]"
 	if test "$TEST_OUTPUT_FILE" = "/dev/null" ;
 	then
-		EVENT_DEBUG_MODE=1 $TEST_DIR/regress --quiet $REGRESS_ARGS
+		EVENT_DEBUG_MODE=1 $TEST_DIR/regress $REGRESS_ARGS
 	else
 		EVENT_DEBUG_MODE=1 $TEST_DIR/regress $REGRESS_ARGS >>"$TEST_OUTPUT_FILE"
 	fi
