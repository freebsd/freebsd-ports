--- src/mkreleasehdr.sh.orig	2019-11-22 16:54:22 UTC
+++ src/mkreleasehdr.sh
@@ -1,6 +1,6 @@
 #!/bin/sh
-GIT_SHA1=`(git show-ref --head --hash=8 2> /dev/null || echo 00000000) | head -n1`
-GIT_DIRTY=`git diff --no-ext-diff 2> /dev/null | wc -l`
+GIT_SHA1="00000000"
+GIT_DIRTY="0"
 BUILD_ID=`uname -n`"-"`date +%s`
 if [ -n "$SOURCE_DATE_EPOCH" ]; then
   BUILD_ID=$(date -u -d "@$SOURCE_DATE_EPOCH" +%s 2>/dev/null || date -u -r "$SOURCE_DATE_EPOCH" +%s 2>/dev/null || date -u +%s)
