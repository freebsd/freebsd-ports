--- tests/test-lz4-dict.sh.orig	2024-07-21 17:29:49 UTC
+++ tests/test-lz4-dict.sh
@@ -39,8 +39,8 @@ for l in 0 1 4 128 32767 32768 32769 65535 65536 65537
 datagen -g128KB > $FPREFIX-data-128KB
 set -e; \
 for l in 0 1 4 128 32767 32768 32769 65535 65536 65537 98303 98304 98305 131071 131072 131073; do \
-    datagen -g$$l > $FPREFIX-$$l; \
-    dd if=$FPREFIX-$$l of=$FPREFIX-$$l-tail bs=1 count=65536 skip=$((l > 65536 ? l - 65536 : 0)); \
-    < $FPREFIX-$$l      lz4 -D stdin $FPREFIX-data-128KB -c | lz4 -dD $FPREFIX-$$l-tail | diff - $FPREFIX-data-128KB; \
-    < $FPREFIX-$$l-tail lz4 -D stdin $FPREFIX-data-128KB -c | lz4 -dD $FPREFIX-$$l      | diff - $FPREFIX-data-128KB; \
+    datagen -g$l > $FPREFIX-$l; \
+    dd if=$FPREFIX-$l of=$FPREFIX-$l-tail bs=1 count=65536 skip=$((l > 65536 ? l - 65536 : 0)); \
+    < $FPREFIX-$l      lz4 -D stdin $FPREFIX-data-128KB -c | lz4 -dD $FPREFIX-$l-tail | diff - $FPREFIX-data-128KB; \
+    < $FPREFIX-$l-tail lz4 -D stdin $FPREFIX-data-128KB -c | lz4 -dD $FPREFIX-$l      | diff - $FPREFIX-data-128KB; \
 done
