--- src/mkreleasehdr.sh.orig	2013-03-12 22:27:27.000000000 +0400
+++ src/mkreleasehdr.sh	2013-03-12 22:27:37.000000000 +0400
@@ -1,6 +1,6 @@
 #!/bin/sh
-GIT_SHA1=`(git show-ref --head --hash=8 2> /dev/null || echo 00000000) | head -n1`
-GIT_DIRTY=`git diff --no-ext-diff 2> /dev/null | wc -l`
+GIT_SHA1="00000000"
+GIT_DIRTY="0"
 test -f release.h || touch release.h
 (cat release.h | grep SHA1 | grep $GIT_SHA1) && \
 (cat release.h | grep DIRTY | grep $GIT_DIRTY) && exit 0 # Already up-to-date
