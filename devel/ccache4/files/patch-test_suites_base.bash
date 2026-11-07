--- test/suites/base.bash.orig	2026-11-07 17:55:50 UTC
+++ test/suites/base.bash
@@ -1996,6 +1996,24 @@ EOF
     expect_stat unsupported_code_directive 1
 
     # -------------------------------------------------------------------------
+    TEST ".incbin with macro operand in .S, direct mode"
+
+    unset CCACHE_NODIRECT
+
+    touch empty.bin
+
+    cat <<EOF >incbin.S
+        .incbin EMPTY_BIN
+EOF
+
+    $CCACHE_COMPILE -c -o incbin.o -DEMPTY_BIN='"empty.bin"' incbin.S
+
+    expect_stat cache_miss 0
+    expect_stat direct_cache_hit 0
+    expect_stat preprocessed_cache_hit 0
+    expect_stat unsupported_code_directive 1
+
+    # -------------------------------------------------------------------------
 if ! $HOST_OS_WINDOWS; then
     TEST "UNCACHED_ERR_FD set when executing preprocessor and compiler"
 
