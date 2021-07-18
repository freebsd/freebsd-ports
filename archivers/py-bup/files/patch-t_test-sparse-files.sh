--- t/test-sparse-files.sh.orig	2020-12-15 12:42:46.593767000 -0800
+++ t/test-sparse-files.sh	2020-12-15 12:43:10.570419000 -0800
@@ -31,6 +31,12 @@
     exit 0
 fi
 
+if [ "$(current-filesystem)" == "zfs" ]; then
+    WVSTART "WARNING!! If zfs compression is enabled in the current " \
+       "filesytem, sparse test might fail!!. " \
+    " See https://groups.google.com/forum/#!topic/bup-list/NZCJ5wHwbFE"
+fi
+
 WVSTART "sparse restore on $(current-filesystem), assuming ${block_size}B blocks"
 
 WVPASS bup init
